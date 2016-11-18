/****************************************************************************
** Meta object code from reading C++ file 'CBLEDiscover.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CBLEDiscover.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CBLEDiscover.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CBLEDiscover_t {
    QByteArrayData data[29];
    char stringdata0[414];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CBLEDiscover_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CBLEDiscover_t qt_meta_stringdata_CBLEDiscover = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CBLEDiscover"
QT_MOC_LITERAL(1, 13, 13), // "relay1Changed"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "relay2Changed"
QT_MOC_LITERAL(4, 42, 9), // "connected"
QT_MOC_LITERAL(5, 52, 18), // "temperatureChanged"
QT_MOC_LITERAL(6, 71, 15), // "connectToDevice"
QT_MOC_LITERAL(7, 87, 7), // "address"
QT_MOC_LITERAL(8, 95, 16), // "connectToService"
QT_MOC_LITERAL(9, 112, 18), // "QLowEnergyService*"
QT_MOC_LITERAL(10, 131, 7), // "service"
QT_MOC_LITERAL(11, 139, 19), // "addLowEnergyService"
QT_MOC_LITERAL(12, 159, 14), // "QBluetoothUuid"
QT_MOC_LITERAL(13, 174, 11), // "serviceUuid"
QT_MOC_LITERAL(14, 186, 24), // "serviceDetailsDiscovered"
QT_MOC_LITERAL(15, 211, 31), // "QLowEnergyService::ServiceState"
QT_MOC_LITERAL(16, 243, 8), // "newState"
QT_MOC_LITERAL(17, 252, 28), // "serviceCharacteristicChanged"
QT_MOC_LITERAL(18, 281, 24), // "QLowEnergyCharacteristic"
QT_MOC_LITERAL(19, 306, 1), // "c"
QT_MOC_LITERAL(20, 308, 5), // "value"
QT_MOC_LITERAL(21, 314, 15), // "deviceConnected"
QT_MOC_LITERAL(22, 330, 5), // "start"
QT_MOC_LITERAL(23, 336, 12), // "switchRelay1"
QT_MOC_LITERAL(24, 349, 12), // "switchRelay2"
QT_MOC_LITERAL(25, 362, 11), // "relay1State"
QT_MOC_LITERAL(26, 374, 11), // "relay2State"
QT_MOC_LITERAL(27, 386, 15), // "connectionState"
QT_MOC_LITERAL(28, 402, 11) // "temperature"

    },
    "CBLEDiscover\0relay1Changed\0\0relay2Changed\0"
    "connected\0temperatureChanged\0"
    "connectToDevice\0address\0connectToService\0"
    "QLowEnergyService*\0service\0"
    "addLowEnergyService\0QBluetoothUuid\0"
    "serviceUuid\0serviceDetailsDiscovered\0"
    "QLowEnergyService::ServiceState\0"
    "newState\0serviceCharacteristicChanged\0"
    "QLowEnergyCharacteristic\0c\0value\0"
    "deviceConnected\0start\0switchRelay1\0"
    "switchRelay2\0relay1State\0relay2State\0"
    "connectionState\0temperature"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CBLEDiscover[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       4,  108, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,
       5,    0,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   83,    2, 0x09 /* Protected */,
       8,    1,   86,    2, 0x09 /* Protected */,
      11,    1,   89,    2, 0x09 /* Protected */,
      14,    1,   92,    2, 0x09 /* Protected */,
      17,    2,   95,    2, 0x09 /* Protected */,
      21,    0,  100,    2, 0x09 /* Protected */,

 // methods: name, argc, parameters, tag, flags
      22,    0,  101,    2, 0x02 /* Public */,
      23,    1,  102,    2, 0x02 /* Public */,
      24,    1,  105,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 18, QMetaType::QByteArray,   19,   20,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::Bool,   20,

 // properties: name, type, flags
      25, QMetaType::Bool, 0x00495003,
      26, QMetaType::Bool, 0x00495003,
      27, QMetaType::Bool, 0x00495003,
      28, QMetaType::Float, 0x00495003,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void CBLEDiscover::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CBLEDiscover *_t = static_cast<CBLEDiscover *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->relay1Changed(); break;
        case 1: _t->relay2Changed(); break;
        case 2: _t->connected(); break;
        case 3: _t->temperatureChanged(); break;
        case 4: _t->connectToDevice((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->connectToService((*reinterpret_cast< QLowEnergyService*(*)>(_a[1]))); break;
        case 6: _t->addLowEnergyService((*reinterpret_cast< QBluetoothUuid(*)>(_a[1]))); break;
        case 7: _t->serviceDetailsDiscovered((*reinterpret_cast< QLowEnergyService::ServiceState(*)>(_a[1]))); break;
        case 8: _t->serviceCharacteristicChanged((*reinterpret_cast< const QLowEnergyCharacteristic(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 9: _t->deviceConnected(); break;
        case 10: _t->start(); break;
        case 11: _t->switchRelay1((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->switchRelay2((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyService* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothUuid >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyService::ServiceState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CBLEDiscover::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CBLEDiscover::relay1Changed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CBLEDiscover::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CBLEDiscover::relay2Changed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CBLEDiscover::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CBLEDiscover::connected)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CBLEDiscover::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CBLEDiscover::temperatureChanged)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        CBLEDiscover *_t = static_cast<CBLEDiscover *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->m_relay1Changed; break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->m_relay2Changed; break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->m_connected; break;
        case 3: *reinterpret_cast< float*>(_v) = _t->m_temperature; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        CBLEDiscover *_t = static_cast<CBLEDiscover *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->m_relay1Changed != *reinterpret_cast< bool*>(_v)) {
                _t->m_relay1Changed = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->relay1Changed();
            }
            break;
        case 1:
            if (_t->m_relay2Changed != *reinterpret_cast< bool*>(_v)) {
                _t->m_relay2Changed = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->relay2Changed();
            }
            break;
        case 2:
            if (_t->m_connected != *reinterpret_cast< bool*>(_v)) {
                _t->m_connected = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->connected();
            }
            break;
        case 3:
            if (_t->m_temperature != *reinterpret_cast< float*>(_v)) {
                _t->m_temperature = *reinterpret_cast< float*>(_v);
                Q_EMIT _t->temperatureChanged();
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject CBLEDiscover::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CBLEDiscover.data,
      qt_meta_data_CBLEDiscover,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CBLEDiscover::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CBLEDiscover::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CBLEDiscover.stringdata0))
        return static_cast<void*>(const_cast< CBLEDiscover*>(this));
    return QObject::qt_metacast(_clname);
}

int CBLEDiscover::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CBLEDiscover::relay1Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CBLEDiscover::relay2Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void CBLEDiscover::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void CBLEDiscover::temperatureChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
