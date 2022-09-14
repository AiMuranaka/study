#include "widget.h"
#include "slidersgroup.h"
#include <QCheckBox>
#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QStackedWidget>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    horizontalSliders = new SlidersGroup(Qt::Horizontal, tr("Horizontal"));
    verticalSliders = new SlidersGroup(Qt::Vertical, tr("Vertical"));

    stackedWidget = new QStackedWidget;
    stackedWidget -> addWidget(horizontalSliders);
    stackedWidget ->addWidget(verticalSliders);

    createControls(tr("Controls"));

    connect(horizontalSliders, &SlidersGroup::valueChanged,
            verticalSliders, &SlidersGroup::setValue);
    connect(verticalSliders, &SlidersGroup::valueChanged,
            valueSpinBox, &QSpinBox::setValue);
    connect(valueSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
            horizontalSliders, &SlidersGroup::setValue);

    QHBoxLayout *layout = new QHBoxLayout;
    layout ->addWidget(controlsGroup);
    layout->addWidget(stackedWidget);
    setLayout(layout);

    minimumSpinBox->setValue(0);
    maximumSpinBox->setValue(20);
    valueSpinBox->setValue(5);

    setWindowTitle(tr("Sliders"));
}

void Widget::createControls(const QString &title)
{
    controlsGroup = new QGroupBox(title);

    minimumLabel = new QLabel(tr("Minimum value:"));
    maximumLabel = new QLabel(tr("Maximum value:"));
    valueLabel = new QLabel(tr("Current value:"));

    invertedAppearance = new QCheckBox(tr("Inverted appearance"));
    invertedKeyBindings = new QCheckBox(tr("Inverted key bindings"));

    minimumSpinBox = new QSpinBox;
    minimumSpinBox->setRange(-100, 100);
    minimumSpinBox->setSingleStep(1);

    maximumSpinBox = new QSpinBox;
    maximumSpinBox->setRange(-100, 100);
    maximumSpinBox->setSingleStep(1);

    valueSpinBox = new QSpinBox;
    valueSpinBox->setRange(-100, 100);
    valueSpinBox->setSingleStep(1);

    orientationCombo = new QComboBox;
    orientationCombo->addItem(tr("Horizontal slider-like widgets"));
    orientationCombo->addItem(tr("Vertical slider-like widgets"));

    connect(orientationCombo, QOverload<int>::of(&QComboBox::activated),
            stackedWidget, &QStackedWidget::setCurrentIndex);
    connect(minimumSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
            horizontalSliders, &SlidersGroup::setMinimum);
    connect(minimumSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
            verticalSliders, &SlidersGroup::setMinimum);
    connect(maximumSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
            horizontalSliders, &SlidersGroup::setMaximum);
    connect(maximumSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
            verticalSliders, &SlidersGroup::setMaximum);
    connect(invertedAppearance, &QCheckBox::toggled,
            horizontalSliders, &SlidersGroup::invertAppearance);
    connect(invertedAppearance, &QCheckBox::toggled,
            verticalSliders, &SlidersGroup::invertAppearance);
    connect(invertedKeyBindings, &QCheckBox::toggled,
            horizontalSliders, &SlidersGroup::invertKeyBindings);
    connect(invertedKeyBindings, &QCheckBox::toggled,
            verticalSliders, &SlidersGroup::invertKeyBindings);

    QGridLayout *controlsLayout = new QGridLayout;
    controlsLayout->addWidget(minimumLabel, 0, 0);
    controlsLayout->addWidget(maximumLabel, 1, 0);
    controlsLayout->addWidget(valueLabel, 2, 0);
    controlsLayout->addWidget(minimumSpinBox, 0, 1);
    controlsLayout->addWidget(maximumSpinBox, 1, 1);
    controlsLayout->addWidget(valueSpinBox, 2, 1);
    controlsLayout->addWidget(invertedAppearance, 0, 2);
    controlsLayout->addWidget(invertedKeyBindings, 1, 2);
    controlsLayout->addWidget(orientationCombo, 3, 0, 1, 3);
    controlsGroup->setLayout(controlsLayout);
}
