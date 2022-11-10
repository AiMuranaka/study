#include "tst_wigglytest.cpp"
#include "dialog.h"
#include <QtTest>
#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    WigglyTest wigglyTest;
    QTest::qExec(&wigglyTest);
    return a.exec();
}
