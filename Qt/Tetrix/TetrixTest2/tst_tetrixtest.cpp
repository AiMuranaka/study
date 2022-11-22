#include <QtTest>
#include <QCoreApplication>
#include "../tetrixpiece.h"

class TetrixTest : public QObject
{
    Q_OBJECT

private slots:
    void minX_data();
    void test_minX();
};

void TetrixTest::minX_data()
{
    QTest::addColumn<QString>("expected");
    QTest::addColumn<int>("result");

    TetrixPiece test;
    test.setShape(NoShape);
    QTest::newRow("positive value") << test.minX() << 0;

    test.setShape(ZShape);
    QTest::newRow("ZShape") << test.minX() << -1;

    test.setShape(SShape);
    QTest::newRow("SShape") << test.minX() << 0;

    test.setShape(LineShape);
    QTest::newRow("LineShape") << test.minX() << 0;

    test.setShape(TShape);
    QTest::newRow("TShape") << test.minX() << -1;

    test.setShape(SquareShape);
    QTest::newRow("SquareShape") << test.minX() << 0;

    test.setShape(LShape);
    QTest::newRow("LShape") << test.minX() << -1;

    test.setShape(MirroredLShape);
    QTest::newRow("MirroredLShape") << test.minX() << 0;


}

void TetrixTest::test_minX()
{
     QFETCH(QString, expected);
     QFETCH(int, result);

     QCOMPARE(expected.toInt(), result);
}
QTEST_MAIN(TetrixTest)

#include "tst_tetrixtest.moc"
