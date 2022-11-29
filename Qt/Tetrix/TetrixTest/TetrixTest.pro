QT += testlib
QT += gui core
QT += core
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_tetrixtest.cpp \
    ../tetrixpiece.cpp

HEADERS += \
    ../tetrixpiece.h
