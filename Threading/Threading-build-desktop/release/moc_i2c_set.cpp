/****************************************************************************
** Meta object code from reading C++ file 'i2c_set.h'
**
** Created: Thu 28. Feb 11:38:11 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../28.03.2012/Threading/Threading/i2c_set.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'i2c_set.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_I2C_Set[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,    9,    8,    8, 0x0a,
      44,    8,    8,    8, 0x0a,
      74,   69,    8,    8, 0x0a,
     107,    8,    8,    8, 0x0a,
     122,    8,    8,    8, 0x0a,
     137,    8,    8,    8, 0x08,
     163,    8,    8,    8, 0x08,
     189,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_I2C_Set[] = {
    "I2C_Set\0\0buf\0on_MEMORY_READ_BUF(QByteArray)\0"
    "on_MEMORY_READ_TIMEOUT()\0Time\0"
    "on_TimerGetTime_responsed(tTime)\0"
    "Time_Request()\0on_I2C_ERROR()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_checkBox_17_clicked()\0"
};

void I2C_Set::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        I2C_Set *_t = static_cast<I2C_Set *>(_o);
        switch (_id) {
        case 0: _t->on_MEMORY_READ_BUF((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->on_MEMORY_READ_TIMEOUT(); break;
        case 2: _t->on_TimerGetTime_responsed((*reinterpret_cast< tTime(*)>(_a[1]))); break;
        case 3: _t->Time_Request(); break;
        case 4: _t->on_I2C_ERROR(); break;
        case 5: _t->on_pushButton_3_clicked(); break;
        case 6: _t->on_pushButton_2_clicked(); break;
        case 7: _t->on_checkBox_17_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData I2C_Set::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject I2C_Set::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_I2C_Set,
      qt_meta_data_I2C_Set, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &I2C_Set::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *I2C_Set::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *I2C_Set::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_I2C_Set))
        return static_cast<void*>(const_cast< I2C_Set*>(this));
    return QDialog::qt_metacast(_clname);
}

int I2C_Set::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
