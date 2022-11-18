#include <QtTest>
#include "../shapeitem.h"

class TestToolTips : public QObject
{
    Q_OBJECT

private slots:
    void test_path();
    void test_position();
    void test_color();
    void test_tooltip();
};

void TestToolTips::test_path()
{
    ShapeItem shapeItem;
    QPainterPath testPath = QPainterPath(QPoint(1,1));
    shapeItem.setPath(testPath);
    QCOMPARE(shapeItem.path(),QPainterPath(QPoint(1,1)));
}

void TestToolTips::test_position()
{
    ShapeItem shapeItem;
    QPoint testPosition = QPoint(1,1);
    shapeItem.setPosition(testPosition);
    QCOMPARE(shapeItem.position(),QPoint(1,1));
}

void TestToolTips::test_color()
{
    ShapeItem shapeItem;
    QColor testColor = Qt::red;
    shapeItem.setColor(testColor);
    QCOMPARE(shapeItem.color(),Qt::red);
}

void TestToolTips::test_tooltip()
{
    ShapeItem shapeItem;
    QString testToolTip ="Test";
    shapeItem.setToolTip(testToolTip);
    QCOMPARE(shapeItem.toolTip(),"Test");
}

QTEST_APPLESS_MAIN(TestToolTips)
#include "tst_testtooltips.moc"
