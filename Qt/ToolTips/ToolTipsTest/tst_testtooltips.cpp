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
    QPainterPath testPath;
    shapeItem.setPath(testPath);
    QCOMPARE(shapeItem.path(),testPath);

}

void TestToolTips::test_position()
{
    ShapeItem shapeItem;
    QPoint testPosition;
    shapeItem.setPosition(testPosition);
    QCOMPARE(shapeItem.position(),testPosition);

}
void TestToolTips::test_color()
{
    ShapeItem shapeItem;
    QColor testColor;
    shapeItem.setColor(testColor);
    QCOMPARE(shapeItem.color(),testColor);

}

void TestToolTips::test_tooltip()
{
    ShapeItem shapeItem;
    QString testToolTip;
    shapeItem.setToolTip(testToolTip);
    QCOMPARE(shapeItem.toolTip(),testToolTip);

}
QTEST_APPLESS_MAIN(TestToolTips)

#include "tst_testtooltips.moc"
