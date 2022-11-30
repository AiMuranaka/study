#include "wigglytest.cpp"
#include <QtTest>
#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    WigglyTest wigglyTest;
    QTest::qExec(&wigglyTest);
    return a.exec();
}
