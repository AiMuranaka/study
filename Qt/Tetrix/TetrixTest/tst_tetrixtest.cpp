#include <QtTest/QtTest>
#include <QCoreApplication>
#include <QMetaType>
#include "../tetrixpiece.h"
Q_DECLARE_METATYPE( TetrixShape )

class TetrixTest : public QObject
{
    Q_OBJECT

private slots:
    void minX_data();
    void minX();
    void maxX_data();
    void maxX();
    void minY_data();
    void minY();
    void maxY_data();
    void maxY();
};

void TetrixTest::minX_data()
{
    QTest::addColumn<TetrixShape>("shapeType");
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

void TetrixTest::minX()
{
    QFETCH(TetrixShape, shapeType);
    QFETCH(int, expected);

    TetrixPiece test;
    test.setShape(shapeType);

    QBENCHMARK {
        QCOMPARE(test.minX(),expected);
    }
}

void TetrixTest::maxX_data()
{
    QTest::addColumn<TetrixShape>("shapeType");
    QTest::addColumn<int>("expected");

    QTest::newRow("NoShape") << NoShape << 0;
    QTest::newRow("ZShape") << ZShape << 0;
    QTest::newRow("SShape") << SShape << 1;
    QTest::newRow("LineShape") << LineShape << 0;
    QTest::newRow("TShape") << TShape << 1;
    QTest::newRow("SquareShape")<< SquareShape << 1;
    QTest::newRow("LShape") << LShape << 0;
    QTest::newRow("MirroredLShape") << MirroredLShape << 1;
}

void TetrixTest::maxX()
{
    QFETCH(TetrixShape, shapeType);
    QFETCH(int, expected);

    TetrixPiece test;
    test.setShape(shapeType);

    QBENCHMARK {
        QCOMPARE(test.maxX(),expected);
    }
}

void TetrixTest::minY_data()
{
    QTest::addColumn<TetrixShape>("shapeType");
    QTest::addColumn<int>("expected");

    QTest::newRow("NoShape") << NoShape << 0;
    QTest::newRow("ZShape") << ZShape << -1;
    QTest::newRow("SShape") << SShape << -1;
    QTest::newRow("LineShape") << LineShape << -1;
    QTest::newRow("TShape") << TShape << 0;
    QTest::newRow("SquareShape")<< SquareShape << 0;
    QTest::newRow("LShape") << LShape << -1;
    QTest::newRow("MirroredLShape") << MirroredLShape << -1;
}

void TetrixTest::minY()
{
    QFETCH(TetrixShape, shapeType);
    QFETCH(int, expected);

    TetrixPiece test;
    test.setShape(shapeType);

    QBENCHMARK {
        QCOMPARE(test.minY(),expected);
    }
}

void TetrixTest::maxY_data()
{
    QTest::addColumn<TetrixShape>("shapeType");
    QTest::addColumn<int>("expected");

    QTest::newRow("NoShape") << NoShape << 0;
    QTest::newRow("ZShape") << ZShape << 1;
    QTest::newRow("SShape") << SShape << 1;
    QTest::newRow("LineShape") << LineShape << 2;
    QTest::newRow("TShape") << TShape << 1;
    QTest::newRow("SquareShape")<< SquareShape << 1;
    QTest::newRow("LShape") << LShape << 1;
    QTest::newRow("MirroredLShape") << MirroredLShape << 1;
}

void TetrixTest::maxY()
{
    QFETCH(TetrixShape, shapeType);
    QFETCH(int, expected);

    TetrixPiece test;
    test.setShape(shapeType);

    QBENCHMARK {
        QCOMPARE(test.maxY(),expected);
    }
}

QTEST_MAIN(TetrixTest)
#include "tst_tetrixtest.moc"
