#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class AnalogClock; }
QT_END_NAMESPACE

class AnalogClock : public QWidget
{
    Q_OBJECT

public:
    AnalogClock(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};
#endif // ANALOGCLOCK_H
