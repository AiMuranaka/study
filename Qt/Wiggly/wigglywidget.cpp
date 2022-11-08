#include <QFontMetrics>
#include <QPainter>
#include <QTimerEvent>
#include "wigglywidget.h"

WigglyWidget::WigglyWidget(QWidget *parent)
    : QWidget(parent), step(0)
{
    setBackgroundRole(QPalette::Midlight);
    setAutoFillBackground(true);

    QFont newFont = font();
    newFont.setPointSize(newFont.pointSize() + 20);
    setFont(newFont);

    timer.start(5000, this);
    //timer.start(60, this);
}

void WigglyWidget::paintEvent(QPaintEvent * /* event */)
{
    static constexpr int sineTable[16] = {
        0, 38, 71, 92, 100, 92, 71, 38, 0, -38, -71, -92, -100, -92, -71, -38
    };

    QFontMetrics metrics(font());
    int x = (width() - metrics.horizontalAdvance(text)) / 2;
    int y = (height() + metrics.ascent() - metrics.descent()) / 2;
    QColor color;

    qDebug("x : %d  ,y : %d", x, y);
    qDebug("文字数: %d",text.size());

    QPainter painter(this);
    for (int i = 0; i < text.size(); ++i) {        
        int index = (step + i) % 16;
        qDebug("index: %d",index);

        color.setHsv((15 - index) * 16, 255, 191);
        painter.setPen(color);
        painter.drawText(x, y - ((sineTable[index] * metrics.height()) / 400),
                         QString(text[i]));

        qDebug("表示される　x座標 : %d  ,y座標 : %d", x, y - ((sineTable[index] * metrics.height()) / 400));
        qDebug("表示される文字: %s",qPrintable(QString(text[i])));
        x += metrics.horizontalAdvance(text[i]);
    }
}

void WigglyWidget::timerEvent(QTimerEvent *event)
{
    int timerID = timer.timerId();
    //timerID = NULL;
    if (event->timerId() == timerID) {
        ++step;
        update();
    } else {
        QWidget::timerEvent(event);
        qDebug("else\n");
    }
}

void WigglyWidget::checkStep()
{
    qDebug("step : %d",step);
}

