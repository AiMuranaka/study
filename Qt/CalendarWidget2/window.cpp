#include <QTextCharFormat>
#include <QDateEdit>
#include <QListView>
#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    createPreviewGroupBox();
    createGeneralOptionsGroupBox();
    createDatesGroupBox();
    createTextFormatsGroupBox();

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(previewGroupBox, 0, 0);
    layout->addWidget(generalOptionsGroupBox, 0, 1);
    layout->addWidget(datesGroupBox, 1, 0);
    layout->addWidget(textFormatsGroupBox, 1, 1);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(layout);

    previewLayout->setRowMinimumHeight(0, calendar->sizeHint().height());
    previewLayout->setColumnMinimumWidth(0, calendar->sizeHint().width());

    setWindowTitle(tr("Calendar Widget"));
}


void Window::createPreviewGroupBox()
{
    previewGroupBox = new QGroupBox(tr("Preview"));

    calendar = new QCalendarWidget;
    calendar->setMinimumDate(QDate(1900, 1, 1));
    calendar->setMaximumDate(QDate(3000, 1, 1));
    calendar->setGridVisible(true);

    connect(calendar, &QCalendarWidget::currentPageChanged,
            this, &Window::reformatCalendarPage);

    previewLayout = new QGridLayout;
    previewLayout->addWidget(calendar, 0, 0, Qt::AlignCenter);
    previewGroupBox->setLayout(previewLayout);
}

void Window::createGeneralOptionsGroupBox()
{
    generalOptionsGroupBox = new QGroupBox(tr("General Options"));

    localeCombo = new QComboBox;
    int curLocaleIndex = -1;
    int index = 0;
    for (int _lang = QLocale::C; _lang <= QLocale::LastLanguage; ++_lang) {
        QLocale::Language lang = static_cast<QLocale::Language>(_lang);
        QList<QLocale::Country> countries = QLocale::countriesForLanguage(lang);
        for (int i = 0; i < countries.count(); ++i) {
            QLocale::Country country = countries.at(i);
            QString label = QLocale::languageToString(lang);
            label += QLatin1Char('/');
            label += QLocale::countryToString(country);
            QLocale locale(lang, country);
            if (this->locale().language() == lang && this->locale().country() == country)
                curLocaleIndex = index;
            localeCombo->addItem(label, locale);
            ++index;
        }
    }
    if (curLocaleIndex != -1)
    localeCombo->setCurrentIndex(curLocaleIndex);
    localeLabel = new QLabel(tr("&Locale"));
    localeLabel->setBuddy(localeCombo);

    firstDayCombo = new QComboBox;

    firstDayCombo->addItem(tr("Sunday"), Qt::Sunday);
    firstDayCombo->addItem(tr("Monday"), Qt::Monday);
    firstDayCombo->addItem(tr("Tuesday"), Qt::Tuesday);
    firstDayCombo->addItem(tr("Wednesday"), Qt::Wednesday);
    firstDayCombo->addItem(tr("Thursday"), Qt::Thursday);
    firstDayCombo->addItem(tr("Friday"), Qt::Friday);
    firstDayCombo->addItem(tr("Saturday"), Qt::Saturday);

    firstDayLabel = new QLabel(tr("Wee&k starts on:"));
    firstDayLabel->setBuddy(firstDayCombo);

    selectionModeCombo = new QComboBox();
    selectionModeLabel = new QLabel(tr("&Slection mode"));
    selectionModeLabel->setBuddy(selectionModeCombo);
    selectionModeCombo->addItem(tr("Single selection"),QCalendarWidget::SingleSelection);
    selectionModeCombo->addItem(tr("No selection"),QCalendarWidget::NoSelection);

    horizontalHeaderCombo = new QComboBox;
    horizontalHeaderCombo->addItem(tr("No horizontal header"), QCalendarWidget::NoHorizontalHeader);
    horizontalHeaderCombo->addItem(tr("Short day names"),QCalendarWidget::ShortDayNames);
    horizontalHeaderCombo->addItem(tr("Single Letter day names"),QCalendarWidget::SingleLetterDayNames);
    horizontalHeaderCombo->addItem(tr("Long day names"),QCalendarWidget::LongDayNames);


    horizontalHeaderLabel = new QLabel(tr("&Horizonal header"));
    horizontalHeaderLabel->setBuddy(horizontalHeaderCombo);

    verticalHeaderCombo = new QComboBox;
    verticalHeaderCombo->addItem(tr("ISO week numbers"),QCalendarWidget::ISOWeekNumbers);
    verticalHeaderCombo->addItem(tr("No Vertical Header"),QCalendarWidget::NoVerticalHeader);
    verticalHeaderLabel = new QLabel(tr("&Vertical header"));
    verticalHeaderLabel->setBuddy(selectionModeCombo);

    gridCheckBox = new QCheckBox(tr("&Grid"));
    gridCheckBox->setCheckState(Qt::CheckState(2));
    navigationCheckBox = new QCheckBox(tr("&Navigation bar"));
    navigationCheckBox->setCheckState(Qt::CheckState(2));


    connect(localeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::localeChanged);
    connect(firstDayCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::firstDayChanged);
    connect(selectionModeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::selectionModeChanged);
    connect(gridCheckBox, &QCheckBox::toggled,
            calendar, &QCalendarWidget::setGridVisible);
    connect(navigationCheckBox, &QCheckBox::toggled,
            calendar, &QCalendarWidget::setNavigationBarVisible);
    connect(horizontalHeaderCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::horizontalHeaderChanged);
    connect(verticalHeaderCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::verticalHeaderChanged);

    firstDayChanged(firstDayCombo->currentIndex());
    selectionModeChanged(selectionModeCombo->currentIndex());
    horizontalHeaderChanged(horizontalHeaderCombo->currentIndex());
    verticalHeaderChanged(verticalHeaderCombo->currentIndex());

    generalOptionsLayout = new QGridLayout;
    generalOptionsLayout->addWidget(localeLabel, 0, 0, Qt::AlignLeft);
    generalOptionsLayout->addWidget(localeCombo, 0, 1, 1, 2);

    generalOptionsLayout->addWidget(firstDayLabel, 1, 0, Qt::AlignLeft);
    generalOptionsLayout->addWidget(firstDayCombo, 1, 1, 1, 2);
    generalOptionsLayout->setColumnStretch(1,4);

    generalOptionsLayout->addWidget(selectionModeLabel, 2, 0, Qt::AlignLeft);
    generalOptionsLayout->addWidget(selectionModeCombo, 2, 1, 1, 2);

    generalOptionsLayout->addWidget(gridCheckBox, 3, 0, Qt::AlignLeft);
    generalOptionsLayout->addWidget(navigationCheckBox, 3, 1,Qt::AlignRight);

    generalOptionsLayout->addWidget(horizontalHeaderLabel, 4, 0, Qt::AlignLeft);
    generalOptionsLayout->addWidget(horizontalHeaderCombo, 4, 1, 1, 2);

    generalOptionsLayout->addWidget(verticalHeaderLabel, 5, 0, Qt::AlignLeft);
    generalOptionsLayout->addWidget(verticalHeaderCombo, 5, 1, 1, 2);


    generalOptionsLayout->setColumnStretch(3,5);
    generalOptionsGroupBox->setLayout(generalOptionsLayout);
}

void Window::createDatesGroupBox()
{
    datesGroupBox = new QGroupBox(tr("Dates"));

    minimumDateEdit = new QDateEdit;
    minimumDateEdit->setDisplayFormat("MMM d yyyy");
    minimumDateEdit->setDateRange(calendar->minimumDate(),
                                  calendar->maximumDate());
    minimumDateEdit->setDate(calendar->minimumDate());

    minimumDateLabel = new QLabel(tr("&Minimum Date:"));
    minimumDateLabel->setBuddy(minimumDateEdit);

    currentDateEdit = new QDateEdit;
    currentDateEdit->setDisplayFormat("MMM d yyyy");
    currentDateEdit->setDate(calendar->selectedDate());
    currentDateEdit->setDateRange(calendar->minimumDate(),
                                  calendar->maximumDate());

    currentDateLabel = new QLabel(tr("&Current Date:"));
    currentDateLabel->setBuddy(currentDateEdit);

    maximumDateEdit = new QDateEdit;
    maximumDateEdit->setDisplayFormat("MMM d yyyy");
    maximumDateEdit->setDateRange(calendar->minimumDate(),
                                  calendar->maximumDate());
    maximumDateEdit->setDate(calendar->maximumDate());

    maximumDateLabel = new QLabel(tr("Ma&ximum Date:"));
    maximumDateLabel->setBuddy(maximumDateEdit);

    connect(currentDateEdit, &QDateEdit::dateChanged,
            calendar, &QCalendarWidget::setSelectedDate);
    connect(calendar, &QCalendarWidget::selectionChanged,
            this, &Window::selectedDateChanged);
    connect(minimumDateEdit, &QDateEdit::dateChanged,
            this, &Window::minimumDateChanged);
    connect(maximumDateEdit, &QDateEdit::dateChanged,
            this, &Window::maximumDateChanged);


    datesLayout = new QGridLayout;
    datesLayout->addWidget(minimumDateLabel, 0, 0, Qt::AlignLeft);
    datesLayout->addWidget(minimumDateEdit, 0, 1, 1, 2);

    datesLayout->addWidget(currentDateLabel, 1, 0, Qt::AlignLeft);
    datesLayout->addWidget(currentDateEdit, 1, 1, 1, 2);

    datesLayout->addWidget(maximumDateLabel, 2, 0, Qt::AlignLeft);
    datesLayout->addWidget(maximumDateEdit, 2, 1, 1, 2);

    datesGroupBox->setLayout(datesLayout);
}

void Window::createTextFormatsGroupBox()
{
    textFormatsGroupBox = new QGroupBox(tr("Text Formats"));

    weekdayColorCombo = new QComboBox;
    weekdayColorCombo = createColorComboBox();
    weekdayColorCombo->setCurrentIndex(
    weekdayColorCombo->findText(tr("Black")));

    weekdayColorLabel = new QLabel(tr("&Weekday color:"));
    weekdayColorLabel->setBuddy(weekdayColorCombo);

    weekendColorCombo = new QComboBox;
    weekendColorCombo = createColorComboBox();
    weekendColorCombo->setCurrentIndex(
    weekendColorCombo->findText(tr("Red")));

    weekendColorLabel = new QLabel(tr("Week&end color:"));
    weekendColorLabel->setBuddy(weekendColorCombo);

    headerTextFormatCombo = new QComboBox;
    headerTextFormatCombo->addItem(tr("Bold"));
    headerTextFormatCombo->addItem(tr("Italic"));
    headerTextFormatCombo->addItem(tr("Plain"));

    headerTextFormatLabel = new QLabel(tr("&Header text:"));
    headerTextFormatLabel->setBuddy(headerTextFormatCombo);

    firstFridayCheckBox = new QCheckBox(tr("&First Friday in blue"));

    mayFirstCheckBox = new QCheckBox(tr("May &1 in red"));

    connect(weekdayColorCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::weekdayFormatChanged);
    connect(weekdayColorCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::reformatCalendarPage);
    connect(weekendColorCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::weekendFormatChanged);
    connect(weekendColorCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::reformatCalendarPage);
    connect(headerTextFormatCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::reformatHeaders);
    connect(firstFridayCheckBox, &QCheckBox::toggled,
            this, &Window::reformatCalendarPage);
    connect(mayFirstCheckBox, &QCheckBox::toggled,
            this, &Window::reformatCalendarPage);

    textFormatLayout = new QGridLayout;
    textFormatLayout->addWidget(weekdayColorLabel, 0, 0, Qt::AlignLeft);
    textFormatLayout->addWidget(weekdayColorCombo, 0, 1, 1, 2);

    textFormatLayout->addWidget(weekendColorLabel, 1, 0, Qt::AlignLeft);
    textFormatLayout->addWidget(weekendColorCombo, 1, 1,  1, 2);

    textFormatLayout->addWidget(headerTextFormatLabel, 2, 0, Qt::AlignLeft);
    textFormatLayout->addWidget(headerTextFormatCombo, 2, 1, 1, 2);

    textFormatLayout->addWidget(firstFridayCheckBox, 3, 0, Qt::AlignLeft);
    textFormatLayout->addWidget(mayFirstCheckBox, 3, 2, Qt::AlignRight);

    textFormatsGroupBox->setLayout(textFormatLayout);

    reformatHeaders();
    reformatCalendarPage();
}

QComboBox *Window::createColorComboBox()
{
    QComboBox *comboBox = new QComboBox;
    comboBox->addItem(tr("Red"), QColor(Qt::red));
    comboBox->addItem(tr("Blue"), QColor(Qt::blue));
    comboBox->addItem(tr("Black"), QColor(Qt::black));
    comboBox->addItem(tr("Magenta"), QColor(Qt::magenta));
    return comboBox;
}

void Window::firstDayChanged(int index)
{
    calendar->setFirstDayOfWeek(Qt::DayOfWeek(firstDayCombo->itemData(index).toInt()));
}

void Window::selectedDateChanged()
{
    currentDateEdit->setDate(calendar->selectedDate());
}

void Window::minimumDateChanged(QDate date)
{
    calendar->setMinimumDate(date);
    maximumDateEdit->setDate(calendar->maximumDate());
}

void Window::maximumDateChanged(QDate date)
{
    calendar->setMaximumDate(date);
    minimumDateEdit->setDate(calendar->minimumDate());
}

void Window::weekdayFormatChanged()
{
    QTextCharFormat format;

    format.setForeground(qvariant_cast<QColor>(weekdayColorCombo->itemData(weekdayColorCombo->currentIndex())));
    calendar->setWeekdayTextFormat(Qt::Monday, format);
    calendar->setWeekdayTextFormat(Qt::Tuesday, format);
    calendar->setWeekdayTextFormat(Qt::Wednesday, format);
    calendar->setWeekdayTextFormat(Qt::Thursday, format);
    calendar->setWeekdayTextFormat(Qt::Friday, format);
}

void Window::weekendFormatChanged()
{
    QTextCharFormat format;

    format.setForeground(qvariant_cast<QColor>(
    weekendColorCombo->itemData(weekendColorCombo->currentIndex())));
    calendar->setWeekdayTextFormat(Qt::Saturday, format);
    calendar->setWeekdayTextFormat(Qt::Sunday, format);
}

void Window::reformatHeaders()
{
    QString text = headerTextFormatCombo->currentText();
    QTextCharFormat format;

    if (text == tr("Bold"))
        format.setFontWeight(QFont::Bold);
    else if (text == tr("Italic"))
        format.setFontItalic(true);
    else if (text == tr("Green"))
        format.setForeground(Qt::green);
    calendar->setHeaderTextFormat(format);
}

void Window::reformatCalendarPage()
{
    QTextCharFormat mayFirstFormat;
    const QDate mayFirst(calendar->yearShown(), 5, 1);

    QTextCharFormat firstFridayFormat;
    QDate firstFriday(calendar->yearShown(), calendar->monthShown(), 1);
    while (firstFriday.dayOfWeek() != Qt::Friday)
        firstFriday = firstFriday.addDays(1);

    if (firstFridayCheckBox->isChecked()) {
        firstFridayFormat.setForeground(Qt::blue);
    } else { // Revert to regular colour for this day of the week.
        Qt::DayOfWeek dayOfWeek(static_cast<Qt::DayOfWeek>(firstFriday.dayOfWeek()));
        firstFridayFormat.setForeground(calendar->weekdayTextFormat(dayOfWeek).foreground());
    }

    calendar->setDateTextFormat(firstFriday, firstFridayFormat);

    // When it is checked, "May First in Red" always takes precedence over "First Friday in Blue".
    if (mayFirstCheckBox->isChecked()) {
        mayFirstFormat.setForeground(Qt::red);
    } else if (!firstFridayCheckBox->isChecked() || firstFriday != mayFirst) {
        // We can now be certain we won't be resetting "May First in Red" when we restore
        // may 1st's regular colour for this day of the week.
        Qt::DayOfWeek dayOfWeek(static_cast<Qt::DayOfWeek>(mayFirst.dayOfWeek()));
        calendar->setDateTextFormat(mayFirst, calendar->weekdayTextFormat(dayOfWeek));
    }

    calendar->setDateTextFormat(mayFirst, mayFirstFormat);
}

void Window::selectionModeChanged(int index)
{
    calendar->setSelectionMode(QCalendarWidget::SelectionMode(index));
}
void Window::horizontalHeaderChanged(int index)
{
    calendar->setHorizontalHeaderFormat(QCalendarWidget::HorizontalHeaderFormat(index));
}

void Window::verticalHeaderChanged(int index)
{
    calendar->setFirstDayOfWeek(Qt::DayOfWeek(
                                firstDayCombo->itemData(index).toInt()));
}

void Window::localeChanged(int index)
{
    QLocale::Language lang = static_cast<QLocale::Language>(index);
    calendar->setLocale(lang);
}

void Window::setGridVisible(bool show)
{
    if(show)
    {
        calendar->isGridVisible();
    }

}

void Window::setNavigationBarVisible(bool visibleS)
{
    if(visibleS)
    {
        calendar->isNavigationBarVisible();
    }

}

