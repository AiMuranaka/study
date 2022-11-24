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
    QTest::addColumn<TetrixPiece>("shape");
    QTest::addColumn<int>("expected");

    QTest::newRow("NoShape") << NoShape << 0;

    QTest::newRow("ZShape") << ZShape << -1;

    QTest::newRow("SShape") << SShape << 0;

    QTest::newRow("LineShape") << LineShape << 0;

    QTest::newRow("TShape") << TShape << -1;

    QTest::newRow("SquareShape")<< SquareShape << 0;

    QTest::newRow("LShape") << LShape << -1;

    QTest::newRow("MirroredLShape") << MirroredLShape << 0;
}

void TetrixTest::test_minX()
{
     QFETCH(TetrixPiece, shape);
     QFETCH(int, expected);

     QCOMPARE(shape.minX(),expected);
}
QTEST_MAIN(TetrixTest)

#include "tst_tetrixtest.moc"
