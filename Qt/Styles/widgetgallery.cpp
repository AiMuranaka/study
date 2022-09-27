#include "widgetgallery.h"
#include "ui_widgetgallery.h"
#include "norwegianwoodstyle.h"
#include <QHBoxLayout>
#include <QGroupBox>
#include <QTimer>
#include <QStyleFactory>

WidgetGallery::WidgetGallery(QWidget *parent)
    : QDialog(parent)
{
    styleComboBox = new QComboBox;
    const QString defaultStyleName = QApplication::style()->objectName();
    QStringList styleNames = QStyleFactory::keys();
    styleNames.append("NorwegianWood");
    for (int i = 1, size = styleNames.size(); i < size; ++i) {
        if (defaultStyleName.compare(styleNames.at(i), Qt::CaseInsensitive) == 0) {
            styleNames.swapItemsAt(0, i);
            break;
        }
    }
    styleComboBox->addItems(styleNames);

    styleLabel = new QLabel(tr("&Style:"));
    styleLabel->setBuddy(styleComboBox);

    useStylePaletteCheckBox = new QCheckBox(tr("&Use style's standard palette"));
    useStylePaletteCheckBox->setChecked(true);

    disableWidgetsCheckBox = new QCheckBox(tr("&Disable widgets"));

    createTopLeftGroupBox();
//    createTopRightGroupBox();
//    createBottomLeftTabWidget();
//    createBottomRightGroupBox();
//    createProgressBar();

    connect(styleComboBox, &QComboBox::textActivated,
            this, &WidgetGallery::changeStyle);
    connect(useStylePaletteCheckBox, &QCheckBox::toggled,
            this, &WidgetGallery::changePalette);
    connect(disableWidgetsCheckBox, &QCheckBox::toggled,
            topLeftGroupBox, &QGroupBox::setDisabled);
    /*
    connect(disableWidgetsCheckBox, &QCheckBox::toggled,
            topRightGroupBox, &QGroupBox::setDisabled);
    connect(disableWidgetsCheckBox, &QCheckBox::toggled,
            bottomLeftTabWidget, &QGroupBox::setDisabled);
    connect(disableWidgetsCheckBox, &QCheckBox::toggled,
            bottomRightGroupBox, &QGroupBox::setDisabled);
    */

    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(styleLabel);
    topLayout->addWidget(styleComboBox);
    topLayout->addStretch(1);
    topLayout->addWidget(useStylePaletteCheckBox);
    topLayout->addWidget(disableWidgetsCheckBox);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addLayout(topLayout, 0, 0, 1, 2);
    mainLayout->addWidget(topLeftGroupBox, 1, 0);
    /*
    mainLayout->addWidget(topRightGroupBox, 1, 1);
    mainLayout->addWidget(bottomLeftTabWidget, 2, 0);
    mainLayout->addWidget(bottomRightGroupBox, 2, 1);

    mainLayout->addWidget(progressBar, 3, 0, 1, 2);
    */
    mainLayout->setRowStretch(1, 1);
    mainLayout->setRowStretch(2, 1);
    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(1, 1);
    setLayout(mainLayout);

    setWindowTitle(tr("Styles"));
    styleChanged();
}

void WidgetGallery::changeStyle(const QString &styleName)
{
    if (styleName == "NorwegianWood")
        QApplication::setStyle(new NorwegianWoodStyle);
    else
        QApplication::setStyle(QStyleFactory::create(styleName));
}

void WidgetGallery::changePalette()
{
    QApplication::setPalette(useStylePaletteCheckBox->isChecked() ?
        QApplication::style()->standardPalette() : QPalette());
}

void WidgetGallery::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::StyleChange)
        styleChanged();
}

void WidgetGallery::styleChanged()
{
    auto styleName = QApplication::style()->objectName();
    for (int i = 0; i < styleComboBox->count(); ++i) {
        if (QString::compare(styleComboBox->itemText(i), styleName, Qt::CaseInsensitive) == 0) {
            styleComboBox->setCurrentIndex(i);
            break;
        }
    }

    changePalette();
}
void WidgetGallery::advanceProgressBar()
{
    int curVal = progressBar->value();
    int maxVal = progressBar->maximum();
    progressBar->setValue(curVal + (maxVal - curVal) / 100);
}

void WidgetGallery::createTopLeftGroupBox()
{
    topLeftGroupBox = new QGroupBox(tr("Group 1"));

    radioButton1 = new QRadioButton(tr("Radio button 1"));
    radioButton2 = new QRadioButton(tr("Radio button 2"));
    radioButton3 = new QRadioButton(tr("Radio button 3"));
    radioButton1->setChecked(true);

    checkBox = new QCheckBox(tr("Tri-state check box"));
    checkBox->setTristate(true);
    checkBox->setCheckState(Qt::PartiallyChecked);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(radioButton1);
    layout->addWidget(radioButton2);
    layout->addWidget(radioButton3);
    layout->addWidget(checkBox);
    layout->addStretch(1);
    topLeftGroupBox->setLayout(layout);
}

void WidgetGallery::createProgressBar()
{
    progressBar = new QProgressBar;
    progressBar->setRange(0, 10000);
    progressBar->setValue(0);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &WidgetGallery::advanceProgressBar);
    timer->start(1000);
}


