/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu 28. Feb 11:38:06 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../28.03.2012/Threading/Threading/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      38,   11,   11,   11, 0x08,
      69,   64,   11,   11, 0x08,
      89,   64,   11,   11, 0x08,
     110,   11,   11,   11, 0x08,
     150,  132,   11,   11, 0x08,
     189,   11,   11,   11, 0x08,
     204,   11,   11,   11, 0x08,
     224,   11,   11,   11, 0x08,
     244,   11,   11,   11, 0x08,
     268,   11,   11,   11, 0x08,
     292,   11,   11,   11, 0x08,
     316,   11,   11,   11, 0x08,
     338,   11,   11,   11, 0x08,
     362,   11,   11,   11, 0x08,
     388,   11,   11,   11, 0x08,
     417,  412,   11,   11, 0x08,
     446,   11,   11,   11, 0x0a,
     470,   11,   11,   11, 0x0a,
     498,   11,   11,   11, 0x0a,
     513,   11,   11,   11, 0x0a,
     532,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_pushButton_2_clicked()\0"
    "on_action_COM_triggered()\0mess\0"
    "MessageReadOK(bool)\0MessageWriteOK(bool)\0"
    "MessageNotConnected()\0OK,ID,Description\0"
    "Display_Dev_Info(bool,quint16,QString)\0"
    "Get_All_Data()\0UnactiveInterface()\0"
    "ActivateInterface()\0on_action_2_triggered()\0"
    "on_action_3_triggered()\0on_action_5_triggered()\0"
    "on_checkBox_clicked()\0on_pushButton_clicked()\0"
    "on_Enable_Graph_Clicked()\0"
    "on_Change_Graph_Color()\0arg1\0"
    "on_spinBox_valueChanged(int)\0"
    "on_dev_info_responsed()\0"
    "on_dev_get_data_responsed()\0on_CRC_ERROR()\0"
    "on_TIMEOUT_ERROR()\0on_Port_Connected()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_2_clicked(); break;
        case 1: _t->on_action_COM_triggered(); break;
        case 2: _t->MessageReadOK((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->MessageWriteOK((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->MessageNotConnected(); break;
        case 5: _t->Display_Dev_Info((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 6: _t->Get_All_Data(); break;
        case 7: _t->UnactiveInterface(); break;
        case 8: _t->ActivateInterface(); break;
        case 9: _t->on_action_2_triggered(); break;
        case 10: _t->on_action_3_triggered(); break;
        case 11: _t->on_action_5_triggered(); break;
        case 12: _t->on_checkBox_clicked(); break;
        case 13: _t->on_pushButton_clicked(); break;
        case 14: _t->on_Enable_Graph_Clicked(); break;
        case 15: _t->on_Change_Graph_Color(); break;
        case 16: _t->on_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->on_dev_info_responsed(); break;
        case 18: _t->on_dev_get_data_responsed(); break;
        case 19: _t->on_CRC_ERROR(); break;
        case 20: _t->on_TIMEOUT_ERROR(); break;
        case 21: _t->on_Port_Connected(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
