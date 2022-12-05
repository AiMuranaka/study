#include <QtTest>
#include <QCoreApplication>
#include "../tetrixpiece.h"
#include <QMetaType>
Q_DECLARE_METATYPE( TetrixShape )

class BenchMark : public QObject
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

void BenchMark::minX_data()
{
    QTest::addColumn<TetrixShape>("shapeType");

    QTest::newRow("NoShape") << NoShape;
    QTest::newRow("ZShape") << ZShape;
    QTest::newRow("SShape") << SShape;
    QTest::newRow("LineShape") << LineShape ;
    QTest::newRow("TShape") << TShape;
    QTest::newRow("SquareShape")<< SquareShape;
    QTest::newRow("LShape") << LShape;
    QTest::newRow("MirroredLShape") << MirroredLShape;
}

void BenchMark::minX()
{
    QFETCH(TetrixShape, shapeType);
    TetrixPiece test;
    test.setShape(shapeType);
    QBENCHMARK {
        test.minX();
    }
}
void BenchMark::maxX_data()
{
    QTest::addColumn<TetrixShape>("shapeType");

    QTest::newRow("NoShape") << NoShape;
    QTest::newRow("ZShape") << ZShape;
    QTest::newRow("SShape") << SShape;
    QTest::newRow("LineShape") << LineShape;
    QTest::newRow("TShape") << TShape;
    QTest::newRow("SquareShape")<< SquareShape;
    QTest::newRow("LShape") << LShape;
    QTest::newRow("MirroredLShape") << MirroredLShape;
}

void BenchMark::maxX()
{
    QFETCH(TetrixShape, shapeType);
    TetrixPiece test;
    test.setShape(shapeType);
    QBENCHMARK {
        test.maxX();
    }
}

void BenchMark::minY_data()
{
    QTest::addColumn<TetrixShape>("shapeType");

    QTest::newRow("NoShape") << NoShape;
    QTest::newRow("ZShape") << ZShape;
    QTest::newRow("SShape") << SShape;
    QTest::newRow("LineShape") << LineShape;
    QTest::newRow("TShape") << TShape;
    QTest::newRow("SquareShape")<< SquareShape;
    QTest::newRow("LShape") << LShape;
    QTest::newRow("MirroredLShape") << MirroredLShape;
}

void BenchMark::minY()
{
    QFETCH(TetrixShape, shapeType);
    TetrixPiece test;
    test.setShape(shapeType);
    QBENCHMARK {
        test.minY();
    }
}

void BenchMark::maxY_data()
{
    QTest::addColumn<TetrixShape>("shapeType");

    QTest::newRow("NoShape") << NoShape << 0;
    QTest::newRow("ZShape") << ZShape << 1;
    QTest::newRow("SShape") << SShape << 1;
    QTest::newRow("LineShape") << LineShape << 2;
    QTest::newRow("TShape") << TShape << 1;
    QTest::newRow("SquareShape")<< SquareShape << 1;
    QTest::newRow("LShape") << LShape ;
    QTest::newRow("MirroredLShape") << MirroredLShape ;
}

void BenchMark::maxY()
{
    QFETCH(TetrixShape, shapeType);
    TetrixPiece test;
    test.setShape(shapeType);
    QBENCHMARK {
        test.maxY();
    }
}

QTEST_MAIN(BenchMark)
#include "tst_benchmark.moc"
