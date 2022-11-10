QT += testlib
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_wigglytest.cpp \
    dialog.cpp \
    main.cpp \
    wigglywidget.cpp

HEADERS += \
    dialog.h \
    wigglywidget.h

SUBDIRS += \
    Wiggly.pro

DISTFILES += \
    Wiggly.pro.user \
    WigglyTest.pro.user
