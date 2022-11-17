#include <QtTest>

// add necessary includes here

class TestQString : public QObject
{
    Q_OBJECT

private slots:
    void toUpper();
    void toLower();

};

void TestQString::toUpper()
{
    QString str = "Hello";
    QCOMPARE(str.toUpper(), QString("HELLO"));
}

void TestQString::toLower()
{
    QString str = "Hello";
    QCOMPARE(str.toLower(), QString("hello"));
}

QTEST_APPLESS_MAIN(TestQString)

#include "tst_testqstring.moc"
