#ifndef SORTINGBOX_H
#define SORTINGBOX_H

#include <QWidget>
#include <QToolButton>
#include <QVector>
#include <QPainterPath>
#include "shapeitem.h"
QT_BEGIN_NAMESPACE
namespace Ui { class SortingBox; }
QT_END_NAMESPACE

class SortingBox : public QWidget
{
    Q_OBJECT

public:
    SortingBox(QWidget *parent = nullptr);

protected:
    bool event(QEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void createNewCircle();
    void createNewSquare();
    void createNewTriangle();

private:
    int updateButtonGeometry(QToolButton *button, int x, int y);
    void createShapeItem(const QPainterPath &path, const QString &toolTip,
                         const QPoint &pos, const QColor &color);
    int itemAt(const QPoint &pos);
    void moveItemTo(const QPoint &pos);
    QPoint initialItemPosition(const QPainterPath &path);
    QPoint randomItemPosition();
    QColor initialItemColor();
    QColor randomItemColor();
    QToolButton *createToolButton(const QString &toolTip, const QIcon &icon, const char *member);
    QVector<ShapeItem> shapeItems;
    QPainterPath circlePath;
    QPainterPath squarePath;
    QPainterPath trianglePath;

    QPoint previousPosition;
    ShapeItem *itemInMotion;

    QToolButton *newCircleButton;
    QToolButton *newSquareButton;
    QToolButton *newTriangleButton;
};
#endif // SORTINGBOX_H
