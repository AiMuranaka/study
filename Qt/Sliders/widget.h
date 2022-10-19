#ifndef WIDGET_H
#define WIDGET_H

#include <QStackedWidget>
#include <QCheckBox>
#include <QGroupBox>
#include <QLabel>
#include <QSpinBox>
#include <QScrollBar>
#include <QComboBox>
#include <QWidget>
class SlidersGroup;
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

private:
    void createControls(const QString &title);

    SlidersGroup *horizontalSliders;
    SlidersGroup *verticalSliders;
    QStackedWidget *stackedWidget;

    QGroupBox *controlsGroup;
    QLabel *minimumLabel;
    QLabel *maximumLabel;
    QLabel *valueLabel;
    QCheckBox *invertedAppearance;
    QCheckBox *invertedKeyBindings;
    QSpinBox *minimumSpinBox;
    QSpinBox *maximumSpinBox;
    QSpinBox *valueSpinBox;
    QComboBox *orientationCombo;
};
#endif // WIDGET_H
