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
    //création du controleur avec l'addresse du serveur en paramètre
    m_controller =  new QLowEnergyController(QBluetoothAddress(address), this);

    //on crée les connections
    //Pour récupérer les services présents
    connect(m_controller,
            SIGNAL(serviceDiscovered(QBluetoothUuid)),
            this,
            SLOT(addLowEnergyService(QBluetoothUuid)));
    //Pour savoir quand la connection est faite
    connect(m_controller,
            SIGNAL(connected()),
            this,
            SLOT(deviceConnected()));

    //on se connecte
    m_controller->setRemoteAddressType(QLowEnergyController::PublicAddress);
    m_controller->connectToDevice();
}

void CBLEDiscover::connectToService(QLowEnergyService *service)
{
    //on stock l'addresse du pointeur
    m_connectedService = service;

    if (m_connectedService->state() == QLowEnergyService::DiscoveryRequired)
    {
        //permet de récupérer une mise à jour des charactéristiques venant du serveur
        connect(m_connectedService,
                SIGNAL(characteristicChanged(QLowEnergyCharacteristic,QByteArray)),
                this,
                SLOT(serviceCharacteristicChanged(QLowEnergyCharacteristic,QByteArray)));
        //Permet de découvrir les charactéristiques associées au service
        connect(m_connectedService,
                SIGNAL(stateChanged(QLowEnergyService::ServiceState)),
                this,
                SLOT(serviceDetailsDiscovered(QLowEnergyService::ServiceState)));

        //démarrer la découverte des charactéristiques
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
    if (c.uuid().toUInt32() == CHAR_UUID_TEMPERATURE)
    {
        m_temperature = value.toFloat();
        Q_EMIT temperatureChanged();
    }
}

void CBLEDiscover::serviceDetailsDiscovered(QLowEnergyService::ServiceState newState)
{
    Q_UNUSED(newState)

    //permet de filtrer
    if (newState != QLowEnergyService::ServiceDiscovered)
    {
            return;
    }

    //on récupère les service qui a appelé le SLOT
    QLowEnergyService *service = qobject_cast<QLowEnergyService *>(sender());
    //on récupère ses charactéristiques
    const QList<QLowEnergyCharacteristic> chars = service->characteristics();
    //on les parcours pour les traiter
    foreach (const QLowEnergyCharacteristic &ch, chars)
    {
        if (ch.uuid().toUInt32() == CHAR_UUID_TEMPERATURE)
        {
            const QLowEnergyDescriptor notificationDesc = ch.descriptor(QBluetoothUuid::ClientCharacteristicConfiguration);
            if (notificationDesc.isValid()) {
                service->writeDescriptor(notificationDesc, QByteArray::fromHex("0100"));
            }
        }

        //Si uuid relay1, on met à jour relay1
        if (ch.uuid().toUInt32() == CHAR_UUID_RELAY1)
        {
            m_relay1Characteristic = ch;
            m_relay1Changed = ch.value().toInt();
            Q_EMIT relay1Changed();
        }
        //Si uuid relay2, on met à jour relay2
        if (ch.uuid().toUInt32() == CHAR_UUID_RELAY2)
        {
            m_relay2Characteristic = ch;
            m_relay2Changed = ch.value().toInt();
            Q_EMIT relay2Changed();
        }

        //on indique à l'UI que les données ont été reçues
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
