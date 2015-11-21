#-------------------------------------------------
#
# Project created by QtCreator 2015-11-17T16:03:19
#
#-------------------------------------------------

QT       += core gui 
QT += gui
QT += core
QT       += network
QT       += xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 14
TEMPLATE = app




SOURCES += main.cpp\
        mainwindow.cpp \
    download.cpp \
    weatherdata.cpp \
    forecastdata.cpp \
    parsedata.cpp

HEADERS  += mainwindow.h \
    download.h \
    weatherdata.h \
    forecastdata.h \
    parsedata.h

FORMS    += mainwindow.ui

DISTFILES +=

RESOURCES += \
    b100.qrc \
    b2.qrc \
    b2mfpt1.qrc \
    b2mfpt2.qrc
