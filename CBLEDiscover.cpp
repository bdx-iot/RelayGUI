#include "CBLEDiscover.h"

#include <QDebug>
#include <QtEndian>

CBLEDiscover::CBLEDiscover() :
    m_controller(NULL),
    m_relay1Changed(false),
    m_relay2Changed(false),
    m_connected(false),
    m_temperature(0)
{

}

CBLEDiscover::~CBLEDiscover()
{
    if (m_controller)
        m_controller->disconnectFromDevice();

    delete m_controller;
    qDeleteAll(m_devices);
}

void CBLEDiscover::start()
{
    connectToDevice("43:43:A1:12:1F:AC");
}

void CBLEDiscover::connectToDevice(const QString &address)
{
    m_controller =  new QLowEnergyController(QBluetoothAddress(address), this);

    connect(m_controller,
            SIGNAL(serviceDiscovered(QBluetoothUuid)),
            this,
            SLOT(addLowEnergyService(QBluetoothUuid)));
    connect(m_controller,
            SIGNAL(discoveryFinished()),
            this,
            SLOT(serviceScanDone()));
    connect(m_controller,
            SIGNAL(connected()),
            this,
            SLOT(deviceConnected()));

    m_controller->setRemoteAddressType(QLowEnergyController::PublicAddress);
    m_controller->connectToDevice();
}

void CBLEDiscover::connectToService(QLowEnergyService *service)
{
    m_connectedService = service;

    if (m_connectedService->state() == QLowEnergyService::DiscoveryRequired)
    {
        connect(m_controller,
                SIGNAL(serviceDiscovered(QBluetoothUuid)),
                this,
                SLOT(addLowEnergyService(QBluetoothUuid)));
        connect(m_connectedService,
                SIGNAL(characteristicChanged(QLowEnergyCharacteristic,QByteArray)),
                this,
                SLOT(serviceCharacteristicChanged(QLowEnergyCharacteristic,QByteArray)));
        connect(m_connectedService,
                SIGNAL(stateChanged(QLowEnergyService::ServiceState)),
                this,
                SLOT(serviceDetailsDiscovered(QLowEnergyService::ServiceState)));

        m_connectedService->discoverDetails();
    }
}

void CBLEDiscover::addLowEnergyService(QBluetoothUuid serviceUuid)
{
    QLowEnergyService *service = m_controller->createServiceObject(serviceUuid);
    connectToService(service);
}

void CBLEDiscover::serviceCharacteristicChanged(const QLowEnergyCharacteristic &c, const QByteArray &value)
{
    if (c.uuid().toUInt32() == UUID_TEMPERATURE)
    {
        m_temperature = value.toFloat();
        Q_EMIT temperatureChanged();
    }
}

void CBLEDiscover::serviceDetailsDiscovered(QLowEnergyService::ServiceState newState)
{
    Q_UNUSED(newState)

    if (newState != QLowEnergyService::ServiceDiscovered)
    {
            return;
    }

    QLowEnergyService *service = qobject_cast<QLowEnergyService *>(sender());
    const QList<QLowEnergyCharacteristic> chars = service->characteristics();
    foreach (const QLowEnergyCharacteristic &ch, chars)
    {
        if (ch.uuid().toUInt32() == UUID_TEMPERATURE)
        {
            const QLowEnergyDescriptor notificationDesc = ch.descriptor(QBluetoothUuid::ClientCharacteristicConfiguration);
            if (notificationDesc.isValid()) {
                service->writeDescriptor(notificationDesc, QByteArray::fromHex("0100"));
            }
        }

        if (ch.uuid().toUInt32() == UUID_RELAY1)
        {
            m_relay1Characteristic = ch;
            m_relay1Changed = ch.value().toInt();
            Q_EMIT relay1Changed();
        }
        if (ch.uuid().toUInt32() == UUID_RELAY2)
        {
            m_relay2Characteristic = ch;
            m_relay2Changed = ch.value().toInt();
            Q_EMIT relay2Changed();
        }
        m_connected = true;
        Q_EMIT connected();
    }
}

void CBLEDiscover::switchRelay1(bool value)
{
    m_connectedService->writeCharacteristic(m_relay1Characteristic, QByteArray::number(value));
}

void CBLEDiscover::switchRelay2(bool value)
{
    m_connectedService->writeCharacteristic(m_relay2Characteristic, QByteArray::number(value));
}

void CBLEDiscover::deviceConnected()
{
    qDebug() << "device Connected";
    m_controller->discoverServices();
}
