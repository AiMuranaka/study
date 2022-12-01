QT += testlib
QT += gui core
QT += core

CONFIG += qt console warn_on depend_includepath testcase
CONFIG += qt warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_tetrixtest.cpp \
    ../tetrixpiece.cpp

HEADERS += \
    ../tetrixpiece.h
