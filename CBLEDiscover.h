#ifndef CBLEDISCOVER_H
#define CBLEDISCOVER_H

#include <QLowEnergyController>
#include <QVariant>
#include <QTimer>

#include "CBLEDeviceInfo.h"

#define CHAR_UUID_RELAY1         0x2aa4
#define CHAR_UUID_RELAY2         0x2aa5
#define CHAR_UUID_TEMPERATURE    0x2aa6

class CBLEDiscover : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool relay1State MEMBER m_relay1Changed NOTIFY relay1Changed)
    Q_PROPERTY(bool relay2State MEMBER m_relay2Changed NOTIFY relay2Changed)
    Q_PROPERTY(bool connectionState MEMBER m_connected NOTIFY connected)
    Q_PROPERTY(float temperature MEMBER m_temperature NOTIFY temperatureChanged)

public:
    CBLEDiscover();
    ~CBLEDiscover();

protected slots:
    void connectToDevice(const QString &address);
    void connectToService(QLowEnergyService *service);
    void addLowEnergyService(QBluetoothUuid serviceUuid);
    void serviceDetailsDiscovered(QLowEnergyService::ServiceState newState);
    void serviceCharacteristicChanged(const QLowEnergyCharacteristic &c, const QByteArray &value);
    void deviceConnected();

private:
    QList<QObject*>                  m_devices;
    QLowEnergyController            *m_controller;
    QLowEnergyService               *m_connectedService;
    QLowEnergyCharacteristic        m_relay1Characteristic;
    QLowEnergyCharacteristic        m_relay2Characteristic;
    bool                            m_relay1Changed;
    bool                            m_relay2Changed;
    bool                            m_connected;
    float                           m_temperature;


public:
    Q_SIGNAL void relay1Changed();
    Q_SIGNAL void relay2Changed();
    Q_SIGNAL void connected();
    Q_SIGNAL void temperatureChanged();

    Q_INVOKABLE void start();
    Q_INVOKABLE void switchRelay1(bool value);
    Q_INVOKABLE void switchRelay2(bool value);
};

#endif // CBLEDISCOVER_H
