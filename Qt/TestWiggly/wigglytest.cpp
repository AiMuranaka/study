#include <QtTest>
#include "wigglywidget.h"

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
    double sineTable = 360;
    double metricsHeight = 120;

    double result = 108;
    double actual = test.drawTextHeight(sineTable, metricsHeight);

    qFuzzyCompare(actual, result);

}


#include "tst_wigglytest.moc"
