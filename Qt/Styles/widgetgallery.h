#ifndef WIDGETGALLERY_H
#define WIDGETGALLERY_H

#include <QDialog>
#include <QCheckBox>
#include <QLabel>
#include <QComboBox>
#include <QGroupBox>
#include <QSpinBox>
#include <QRadioButton>
#include <QTableWidget>
#include <QDateTimeEdit>
#include <QTextEdit>
#include <QDial>
#include <QProgressBar>

QT_BEGIN_NAMESPACE
namespace Ui { class WidgetGallery; }
QT_END_NAMESPACE

class WidgetGallery : public QDialog
{
    Q_OBJECT

public:
    WidgetGallery(QWidget *parent = nullptr);

protected:
    void changeEvent(QEvent *) override;

private slots:
    void changeStyle(const QString &styleName);
    void styleChanged();
    void changePalette();
    void advanceProgressBar();

private:
    void createTopLeftGroupBox();
    void createTopRightGroupBox();
    void createBottomLeftTabWidget();
    void createBottomRightGroupBox();
    void createProgressBar();

    QLabel *styleLabel;
    QComboBox *styleComboBox;
    QCheckBox *useStylePaletteCheckBox;
    QCheckBox *disableWidgetsCheckBox;

    QGroupBox *topLeftGroupBox;
    QRadioButton *radioButton1;
    QRadioButton *radioButton2;
    QRadioButton *radioButton3;
    QCheckBox *checkBox;

    QGroupBox *topRightGroupBox;
    QPushButton *defaultPushButton;
    QPushButton *togglePushButton;
    QPushButton *flatPushButton;

    QTabWidget *bottomLeftTabWidget;
    QTableWidget *tableWidget;
    QTextEdit *textEdit;

    QGroupBox *bottomRightGroupBox;
    QLineEdit *lineEdit;
    QSpinBox *spinBox;
    QDateTimeEdit *dateTimeEdit;
    QSlider *slider;
    QScrollBar *scrollBar;
    QDial *dial;

    QProgressBar *progressBar;
};
#endif // WIDGETGALLERY_H
