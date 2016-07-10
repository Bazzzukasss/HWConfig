#-------------------------------------------------
#
# Project created by QtCreator 2015-10-29T12:44:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HWConfig
TEMPLATE = app


SOURCES += main.cpp \
    HWConfigWindow.cpp \
    HWConfig.cpp

HEADERS  += \
    HWShell.h \
    HWConfigWindow.h \
    HWConfig.h \
    HWConnection.h

FORMS    += hwconfigwindow.ui

RESOURCES += \
    images.qrc
