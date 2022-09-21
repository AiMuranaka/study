#include "norwegianwoodstyle.h"

#include <QStyleFactory>
#include <QPainter>
#include <QPushButton>
#include <QComboBox>

NorwegianWoodStyle::NorwegianWoodStyle() :
    QProxyStyle(QStyleFactory::create("windows"))
{
    setObjectName("NorwegianWood");
}

QPalette NorwegianWoodStyle::standardPalette() const
{
    if (!m_standardPalette.isBrushSet(QPalette::Disabled, QPalette::Mid)) {
        QColor brown(212, 140, 95);
        QColor beige(236, 182, 120);
        QColor slightlyOpaqueBlack(0, 0, 0, 63);

        QImage backgroundImage(":/images/woodbackground.png");
        QImage buttonImage(":/images/woodbutton.png");
        QImage midImage = buttonImage.convertToFormat(QImage::Format_RGB32);

        QPainter painter;
        painter.begin(&midImage);
        painter.setPen(Qt::NoPen);
        painter.fillRect(midImage.rect(), slightlyOpaqueBlack);
        painter.end();

        QPalette palette(brown);
        palette.setBrush(QPalette::BrightText, Qt::white);
        palette.setBrush(QPalette::Base, beige);
        palette.setBrush(QPalette::Highlight, Qt::darkGreen);
        setTexture(palette, QPalette::Button, buttonImage);
        setTexture(palette, QPalette::Mid, midImage);
        setTexture(palette, QPalette::Window, backgroundImage);

        QBrush brush = palette.window();
        brush.setColor(brush.color().darker());

        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush);

        m_standardPalette = palette;
    }

    return m_standardPalette;
}

void NorwegianWoodStyle::polish(QWidget *widget)
{
    if (qobject_cast<QPushButton *>(widget)
            || qobject_cast<QComboBox *>(widget))
        widget->setAttribute(Qt::WA_Hover, true);
}

void NorwegianWoodStyle::unpolish(QWidget *widget)
{
    if (qobject_cast<QPushButton *>(widget)
            || qobject_cast<QComboBox *>(widget))
        widget->setAttribute(Qt::WA_Hover, false);
}
