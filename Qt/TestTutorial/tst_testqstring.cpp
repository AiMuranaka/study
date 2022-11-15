#include <QtTest>

// add necessary includes here

class TestQString : public QObject
{
    Q_OBJECT

private slots:
    void toUpper();

};

void TestQString::toUpper()
{
    QString str = "Hello";
    QCOMPARE(str.toUpper(), QString("HELLO"));
}

QTEST_APPLESS_MAIN(TestQString)

#include "tst_testqstring.moc"
