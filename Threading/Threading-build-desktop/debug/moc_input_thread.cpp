/****************************************************************************
** Meta object code from reading C++ file 'input_thread.h'
**
** Created: Thu 21. Feb 11:08:00 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Threading/input_thread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'input_thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Input_Thread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   14,   13,   13, 0x05,
      41,   38,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      54,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Input_Thread[] = {
    "Input_Thread\0\0data\0isRead(QByteArray)\0"
    "ok\0ReadOK(bool)\0ReadPort()\0"
};

void Input_Thread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Input_Thread *_t = static_cast<Input_Thread *>(_o);
        switch (_id) {
        case 0: _t->isRead((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->ReadOK((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->ReadPort(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Input_Thread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Input_Thread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Input_Thread,
      qt_meta_data_Input_Thread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Input_Thread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Input_Thread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Input_Thread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Input_Thread))
        return static_cast<void*>(const_cast< Input_Thread*>(this));
    return QThread::qt_metacast(_clname);
}

int Input_Thread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Input_Thread::isRead(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Input_Thread::ReadOK(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
