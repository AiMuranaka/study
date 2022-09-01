#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QWidget>
#include <QLCDNumber>

QT_BEGIN_NAMESPACE
namespace Ui { class DigitalClock; }
QT_END_NAMESPACE

class DigitalClock : public QLCDNumber
{
    Q_OBJECT

public:
    DigitalClock(QWidget *parent = nullptr);

private slots:
    void showTime();
};
#endif // DIGITALCLOCK_H
