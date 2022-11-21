#include <QtTest>
#include <QCoreApplication>
#include "../tetrixpiece.h"


class TetrixTest : public QObject
{
    Q_OBJECT


private slots:
    void test_minX();
};

void TetrixTest::test_minX()
{
    TetrixPiece piece;
    piece.setShape(NoShape);
    QCOMPARE(piece.minX(), 0);

    piece.setShape(ZShape);
    QCOMPARE(piece.minX(), -1);

    piece.setShape(SShape);
    QCOMPARE(piece.minX(), 0);

    piece.setShape(LineShape);
    QCOMPARE(piece.minX(), 0);

    piece.setShape(TShape);
    QCOMPARE(piece.minX(), -1);

    piece.setShape(SquareShape);
    QCOMPARE(piece.minX(), 0);

    piece.setShape(LShape);
    QCOMPARE(piece.minX(), -1);

    piece.setShape(MirroredLShape);
    QCOMPARE(piece.minX(), 0);

}

QTEST_MAIN(TetrixTest)

#include "tst_tetrixtest.moc"
