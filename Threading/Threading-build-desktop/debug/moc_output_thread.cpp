/****************************************************************************
** Meta object code from reading C++ file 'output_thread.h'
**
** Created: Wed 20. Feb 17:12:53 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Threading/output_thread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'output_thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Output_Thread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      41,   32,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Output_Thread[] = {
    "Output_Thread\0\0OK\0Send_OK(bool)\0"
    "out_data\0Send(QByteArray)\0"
};

void Output_Thread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Output_Thread *_t = static_cast<Output_Thread *>(_o);
        switch (_id) {
        case 0: _t->Send_OK((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->Send((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Output_Thread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Output_Thread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Output_Thread,
      qt_meta_data_Output_Thread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Output_Thread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Output_Thread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Output_Thread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Output_Thread))
        return static_cast<void*>(const_cast< Output_Thread*>(this));
    return QThread::qt_metacast(_clname);
}

int Output_Thread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Output_Thread::Send_OK(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
