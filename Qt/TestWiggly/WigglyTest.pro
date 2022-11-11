QT += testlib
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  \
    main.cpp \
    tst_wigglytest.cpp \
    wigglywidget.cpp

HEADERS += \
    wigglywidget.h

SUBDIRS += \
    Wiggly.pro

DISTFILES += \
    WigglyTest.pro.user
