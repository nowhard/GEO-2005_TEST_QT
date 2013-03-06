/****************************************************************************
** Meta object code from reading C++ file 'proto_uso.h'
**
** Created: Thu 28. Feb 11:38:10 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../28.03.2012/Threading/Threading/proto_uso.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'proto_uso.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_proto_uso[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      37,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      32,   10,   10,   10, 0x05,
      61,   57,   10,   10, 0x05,
      99,   10,   10,   10, 0x05,
     118,   10,   10,   10, 0x05,
     141,   10,   10,   10, 0x05,
     166,   10,   10,   10, 0x05,
     191,   10,   10,   10, 0x05,
     217,   10,   10,   10, 0x05,
     244,   10,   10,   10, 0x05,
     276,   10,   10,   10, 0x05,
     288,   10,   10,   10, 0x05,
     304,   10,   10,   10, 0x05,
     319,  316,   10,   10, 0x05,
     333,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     359,  350,   10,   10, 0x0a,
     393,  384,   10,   10, 0x0a,
     437,  423,   10,   10, 0x0a,
     483,  350,   10,   10, 0x0a,
     516,  384,   10,   10, 0x0a,
     554,  384,   10,   10, 0x0a,
     611,  580,   10,   10, 0x0a,
     660,  350,   10,   10, 0x0a,
     687,  384,   10,   10, 0x0a,
     733,  719,   10,   10, 0x0a,
     766,  384,   10,   10, 0x0a,
     819,  798,   10,   10, 0x0a,
     862,  384,   10,   10, 0x0a,
     920,  895,   10,   10, 0x0a,
     974,  384,   10,   10, 0x0a,
    1008,  384,   10,   10, 0x0a,
    1043, 1037,   10,   10, 0x0a,
    1086,   10,   10,   10, 0x0a,
    1098,   10,   10,   10, 0x0a,
    1107,   10,   10,   10, 0x08,
    1138, 1129,   10,   10, 0x08,
    1161,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_proto_uso[] = {
    "proto_uso\0\0DEV_INFO_RESPONSED()\0"
    "GET_ALL_DATA_RESPONSED()\0buf\0"
    "MEMORY_READ_BUF_RESPONSED(QByteArray)\0"
    "DEV_INFO_TIMEOUT()\0GET_ALL_DATA_TIMEOUT()\0"
    "TIMER_GET_TIME_TIMEOUT()\0"
    "TIMER_SET_TIME_TIMEOUT()\0"
    "MEMORY_READ_BUF_TIMEOUT()\0"
    "MEMORY_WRITE_BUF_TIMEOUT()\0"
    "TIMER_GET_TIME_RESPONSED(tTime)\0"
    "CRC_ERROR()\0TIMEOUT_ERROR()\0I2C_ERROR()\0"
    "OK\0Send_OK(bool)\0Port_Connected()\0"
    "dev_addr\0GET_DEV_INFO_REQ(quint8)\0"
    "response\0GET_DEV_INFO_RESP(QByteArray)\0"
    "dev_addr,chnl\0"
    "CHANNEL_SET_PARAMETERS_REQ(quint8,CHANNEL*[])\0"
    "CHANNEL_ALL_GET_DATA_REQ(quint8)\0"
    "CHANNEL_ALL_GET_DATA_RESP(QByteArray)\0"
    "REQUEST_ERROR(QByteArray)\0"
    "dev_addr,port_val_1,port_val_2\0"
    "CHANNEL_SET_DISCRET_OUT_REQ(qint8,quint8,quint8)\0"
    "TIMER_GET_TIME_REQ(quint8)\0"
    "TIMER_GET_TIME_RESP(QByteArray)\0"
    "dev_addr,Time\0TIMER_SET_TIME_REQ(quint8,tTime)\0"
    "TIMER_SET_TIME_RESP(QByteArray)\0"
    "dev_addr,addr,length\0"
    "MEMORY_READ_BUF_REQ(quint8,quint16,quint8)\0"
    "MEMORY_READ_BUF_RESP(QByteArray)\0"
    "dev_addr,addr,length,buf\0"
    "MEMORY_WRITE_BUF_REQ(qint8,quint16,quint8,QByteArray)\0"
    "MEMORY_WRITE_BUF_RESP(QByteArray)\0"
    "ResponseHandling(QByteArray)\0Port,\0"
    "OpenPort(QString,AbstractSerial::BaudRate)\0"
    "ClosePort()\0doWork()\0Device_Not_Response()\0"
    "out_data\0Send_Frame(QByteArray)\0"
    "Recieve_Frame()\0"
};

void proto_uso::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        proto_uso *_t = static_cast<proto_uso *>(_o);
        switch (_id) {
        case 0: _t->DEV_INFO_RESPONSED(); break;
        case 1: _t->GET_ALL_DATA_RESPONSED(); break;
        case 2: _t->MEMORY_READ_BUF_RESPONSED((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->DEV_INFO_TIMEOUT(); break;
        case 4: _t->GET_ALL_DATA_TIMEOUT(); break;
        case 5: _t->TIMER_GET_TIME_TIMEOUT(); break;
        case 6: _t->TIMER_SET_TIME_TIMEOUT(); break;
        case 7: _t->MEMORY_READ_BUF_TIMEOUT(); break;
        case 8: _t->MEMORY_WRITE_BUF_TIMEOUT(); break;
        case 9: _t->TIMER_GET_TIME_RESPONSED((*reinterpret_cast< tTime(*)>(_a[1]))); break;
        case 10: _t->CRC_ERROR(); break;
        case 11: _t->TIMEOUT_ERROR(); break;
        case 12: _t->I2C_ERROR(); break;
        case 13: _t->Send_OK((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->Port_Connected(); break;
        case 15: _t->GET_DEV_INFO_REQ((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 16: _t->GET_DEV_INFO_RESP((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 17: _t->CHANNEL_SET_PARAMETERS_REQ((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< CHANNEL*(*)[]>(_a[2]))); break;
        case 18: _t->CHANNEL_ALL_GET_DATA_REQ((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 19: _t->CHANNEL_ALL_GET_DATA_RESP((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 20: _t->REQUEST_ERROR((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 21: _t->CHANNEL_SET_DISCRET_OUT_REQ((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3]))); break;
        case 22: _t->TIMER_GET_TIME_REQ((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 23: _t->TIMER_GET_TIME_RESP((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 24: _t->TIMER_SET_TIME_REQ((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< tTime(*)>(_a[2]))); break;
        case 25: _t->TIMER_SET_TIME_RESP((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 26: _t->MEMORY_READ_BUF_REQ((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3]))); break;
        case 27: _t->MEMORY_READ_BUF_RESP((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 28: _t->MEMORY_WRITE_BUF_REQ((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< QByteArray(*)>(_a[4]))); break;
        case 29: _t->MEMORY_WRITE_BUF_RESP((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 30: _t->ResponseHandling((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 31: _t->OpenPort((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< AbstractSerial::BaudRate(*)>(_a[2]))); break;
        case 32: _t->ClosePort(); break;
        case 33: _t->doWork(); break;
        case 34: _t->Device_Not_Response(); break;
        case 35: _t->Send_Frame((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 36: _t->Recieve_Frame(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData proto_uso::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject proto_uso::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_proto_uso,
      qt_meta_data_proto_uso, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &proto_uso::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *proto_uso::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *proto_uso::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_proto_uso))
        return static_cast<void*>(const_cast< proto_uso*>(this));
    return QObject::qt_metacast(_clname);
}

int proto_uso::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    }
    return _id;
}

// SIGNAL 0
void proto_uso::DEV_INFO_RESPONSED()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void proto_uso::GET_ALL_DATA_RESPONSED()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void proto_uso::MEMORY_READ_BUF_RESPONSED(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void proto_uso::DEV_INFO_TIMEOUT()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void proto_uso::GET_ALL_DATA_TIMEOUT()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void proto_uso::TIMER_GET_TIME_TIMEOUT()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void proto_uso::TIMER_SET_TIME_TIMEOUT()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void proto_uso::MEMORY_READ_BUF_TIMEOUT()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void proto_uso::MEMORY_WRITE_BUF_TIMEOUT()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void proto_uso::TIMER_GET_TIME_RESPONSED(tTime _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void proto_uso::CRC_ERROR()
{
    QMetaObject::activate(this, &staticMetaObject, 10, 0);
}

// SIGNAL 11
void proto_uso::TIMEOUT_ERROR()
{
    QMetaObject::activate(this, &staticMetaObject, 11, 0);
}

// SIGNAL 12
void proto_uso::I2C_ERROR()
{
    QMetaObject::activate(this, &staticMetaObject, 12, 0);
}

// SIGNAL 13
void proto_uso::Send_OK(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void proto_uso::Port_Connected()
{
    QMetaObject::activate(this, &staticMetaObject, 14, 0);
}
QT_END_MOC_NAMESPACE
