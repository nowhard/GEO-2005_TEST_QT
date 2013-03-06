#-------------------------------------------------
#
# Project created by QtCreator 2011-04-14T20:35:49
#
#-------------------------------------------------

QT       += core gui

TARGET = Threading
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog_com.cpp \
    proto_uso.cpp \
    i2c_set.cpp


HEADERS  += mainwindow.h \
    dialog_com.h \
    proto_uso.h \
    i2c_set.h

FORMS    += mainwindow.ui \
    dialog_com.ui \
    i2c_set.ui

INCLUDEPATH += ./serial_src/qserialdevice
INCLUDEPATH += ./serial_src/qserialdeviceenumerator

QMAKE_LIBDIR += ./libs
LIBS += -lqserialdevice\
        -lqserialdeviceenumerator
