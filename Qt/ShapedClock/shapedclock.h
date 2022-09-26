#ifndef SHAPEDCLOCK_H
#define SHAPEDCLOCK_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ShapedClock; }
QT_END_NAMESPACE

class ShapedClock : public QWidget
{
    Q_OBJECT

public:
    ShapedClock(QWidget *parent = nullptr);
    QSize sizeHint() const override;

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    QPoint dragPosition;
};
#endif // SHAPEDCLOCK_H
