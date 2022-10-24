#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QDateTimeEdit;
class QDoubleSpinBox;
class QGroupBox;
class QLabel;
class QSpinBox;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

public slots:
    void changePrecision(int decimals);
    void setFormatString(const QString &formatString);

private:
    void createSpinBoxes();
    void createDateTimeEdits();
    void createDoubleSpinBoxes();

    QDateTimeEdit *meetingEdit;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *priceSpinBox;
    QDoubleSpinBox *scaleSpinBox;
    QGroupBox *spinBoxesGroup;
    QGroupBox *editsGroup;
    QGroupBox *doubleSpinBoxesGroup;
    QLabel *meetingLabel;
    QSpinBox *groupSeparatorSpinBox;
    QDoubleSpinBox *groupSeparatorSpinBox_d;
};
#endif // WIDGET_H
