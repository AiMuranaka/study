QT += testlib
QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testtooltips.cpp \
    ../shapeitem.cpp \

HEADERS += \
    ../shapeitem.h \
