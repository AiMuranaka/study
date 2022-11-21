#include <QtTest>
#include <QCoreApplication>
#include "../tetrixpiece.h"

class TetrixTest : public QObject
{
    Q_OBJECT

private slots:
    void test_minX();
    void test_maxX();
    void test_minY();
    void test_maxY();
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

void TetrixTest::test_maxX()
{
    TetrixPiece piece;
    piece.setShape(NoShape);
    QCOMPARE(piece.maxX(), 0);

    piece.setShape(ZShape);
    QCOMPARE(piece.maxX(), 0);

    piece.setShape(SShape);
    QCOMPARE(piece.maxX(), 1);

    piece.setShape(LineShape);
    QCOMPARE(piece.maxX(), 0);

    piece.setShape(TShape);
    QCOMPARE(piece.maxX(), 1);

    piece.setShape(SquareShape);
    QCOMPARE(piece.maxX(), 1);

    piece.setShape(LShape);
    QCOMPARE(piece.maxX(), 0);

    piece.setShape(MirroredLShape);
    QCOMPARE(piece.maxX(), 1);
}

void TetrixTest::test_minY()
{
    TetrixPiece piece;
    piece.setShape(NoShape);
    QCOMPARE(piece.minY(), 0);

    piece.setShape(ZShape);
    QCOMPARE(piece.minY(), -1);

    piece.setShape(SShape);
    QCOMPARE(piece.minY(), -1);

    piece.setShape(LineShape);
    QCOMPARE(piece.minY(), -1);

    piece.setShape(TShape);
    QCOMPARE(piece.minY(), 0);

    piece.setShape(SquareShape);
    QCOMPARE(piece.minY(), 0);

    piece.setShape(LShape);
    QCOMPARE(piece.minY(), -1);

    piece.setShape(MirroredLShape);
    QCOMPARE(piece.minY(), -1);
}

void TetrixTest::test_maxY()
{
    TetrixPiece piece;
    piece.setShape(NoShape);
    QCOMPARE(piece.maxY(), 0);

    piece.setShape(ZShape);
    QCOMPARE(piece.maxY(), 1);

    piece.setShape(SShape);
    QCOMPARE(piece.maxY(), 1);

    piece.setShape(LineShape);
    QCOMPARE(piece.maxY(), 2);

    piece.setShape(TShape);
    QCOMPARE(piece.maxY(), 1);

    piece.setShape(SquareShape);
    QCOMPARE(piece.maxY(), 1);

    piece.setShape(LShape);
    QCOMPARE(piece.maxY(), 1);

    piece.setShape(MirroredLShape);
    QCOMPARE(piece.maxY(), 1);
}


QTEST_MAIN(TetrixTest)

#include "tst_tetrixtest.moc"
