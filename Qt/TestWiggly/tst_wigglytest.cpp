#include <QtTest>
#include "wigglywidget.h"
// add necessary includes here

class WigglyTest : public QObject
{
    Q_OBJECT

public:
    WigglyTest();
    ~WigglyTest();

private slots:
    void test_case1();
    void net_price();

};

WigglyTest::WigglyTest()
{

}

WigglyTest::~WigglyTest()
{

}

void WigglyTest::test_case1()
{
    WigglyWidget test;
 //   test.timerEvent();

}

//QTEST_APPLESS_MAIN(WigglyTest)

#include "tst_wigglytest.moc"
