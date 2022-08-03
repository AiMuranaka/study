#include <QComboBox>
#include <QGroupBox>
#include <QGridLayout>
#include <QCalendarWidget>
#include <QLabel>
#include <QDateEdit>
#include <QCheckBox>
#ifndef CALENDERWIDGET_H
#define CALENDERWIDGET_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class CalenderWidget; }
QT_END_NAMESPACE
class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);

private slots:
    void localeChanged(int index);
    void firstDayChanged(int index);
    void selectionModeChanged(int index);
    void horizontalHeaderChanged(int index);
    void verticalHeaderChanged(int index);
    void selectedDateChanged();
    void minimumDateChanged(QDate date);
    void maximumDateChanged(QDate date);
    void weekdayFormatChanged();
    void weekendFormatChanged();
    void reformatHeaders();
    void reformatCalendarPage();
    void setGridVisible(bool show);
    void setNavigationBarVisible(bool visibleS);

private:
    void createPreviewGroupBox();
    void createGeneralOptionsGroupBox();
    void createDatesGroupBox();
    void createTextFormatsGroupBox();
    QComboBox *createColorComboBox();

    QGroupBox *previewGroupBox;
    QGridLayout *previewLayout;
    QCalendarWidget *calendar;

    QGroupBox *generalOptionsGroupBox;
    QGridLayout *generalOptionsLayout;

    QGroupBox *datesGroupBox;
    QGridLayout *datesLayout;

    QGroupBox *textFormatGroupBox;
    QGridLayout *textFormatLayout;

    QLabel *localeLabel;
    QLabel *firstDayLabel;
    QCheckBox *firstFridayInBlue;
    QCheckBox *mayFirstCheckBox;
    QComboBox *localeCombo;
    QComboBox *firstDayCombo;
    QGroupBox *textFormatsGroupBox;
    QComboBox *selectionModeCombo;
    QLabel *selectionModeLabel;
    QCheckBox *gridCheckBox;
    QCheckBox *navigationCheckBox;
    QComboBox *horizontalHeaderCombo;
    QLabel *horizontalHeaderLabel;
    QComboBox *verticalHeaderCombo;
    QLabel *verticalHeaderLabel;
    QDateEdit *minimumDateEdit;
    QLabel *minimumDateLabel;
    QDateEdit *currentDateEdit;
    QLabel *currentDateLabel;
    QDateEdit *maximumDateEdit;
    QLabel *maximumDateLabel;
    QComboBox *weekdayColorCombo;
    QLabel *weekdayColorLabel;
    QComboBox *weekendColorCombo;
    QLabel *weekendColorLabel;
    QComboBox *headerTextFormatCombo;
    QLabel *headerTextFormatLabel;
    QCheckBox *firstFridayCheckBox;


};
#endif // CALENDERWIDGET_H
