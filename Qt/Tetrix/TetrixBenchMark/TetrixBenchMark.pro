QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_benchmark.cpp \
    ../tetrixpiece.cpp

HEADERS += \
    ../tetrixpiece.h
