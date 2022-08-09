#include <QPainter>
#include <QBrush>
#include <QRect>
#include <QRect>
#include <QPaintEvent>
#include <QToolTip>
#include <QFontDatabase>
#include "characterwidget.h"
#include "ui_characterwidget.h"

CharacterWidget::CharacterWidget(QWidget *parent)
    : QWidget(parent)
{
    calculateSquareSize();
    setMouseTracking(true);
}

void CharacterWidget::updateFont(const QFont &font)
{
    displayFont.setFamily(font.family());
    calculateSquareSize();
    adjustSize();
    update();
}

void CharacterWidget::updateSize(const QString &fontSize)
{
    displayFont.setPointSize(fontSize.toInt());
    calculateSquareSize();
    adjustSize();
    update();
}

QSize CharacterWidget::sizeHint() const
{
    return QSize(columns*squareSize, (65536 / columns) * squareSize);
}

void CharacterWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(event->rect(), QBrush(Qt::white));
    painter.setFont(displayFont);

    QRect redrawRect = event->rect();
    int beginRow = redrawRect.top() / squareSize;
    int endRow = redrawRect.bottom() / squareSize;
    int beginColumn = redrawRect.left() / squareSize;
    int endColumn = redrawRect.right() / squareSize;

    painter.setPen(QPen(Qt::gray));
    for (int row = beginRow; row <= endRow; ++row) {
        for (int column = beginColumn; column <= endColumn; ++column) {
            painter.drawRect(column * squareSize, row * squareSize, squareSize, squareSize);
        }
    }

    QFontMetrics fontMetrics(displayFont);
    painter.setPen(QPen(Qt::black));
    for (int row = beginRow; row <= endRow; ++row) {
        for (int column = beginColumn; column <= endColumn; ++column) {
            int key = row * columns + column;
            painter.setClipRect(column * squareSize, row * squareSize, squareSize, squareSize);

            if (key == lastKey)
                painter.fillRect(column * squareSize + 1, row * squareSize + 1,
                                 squareSize, squareSize, QBrush(Qt::red));

            painter.drawText(column * squareSize + (squareSize / 2) -
                                 fontMetrics.horizontalAdvance(QChar(key)) / 2,
                             row * squareSize + 4 + fontMetrics.ascent(),
                             QString(QChar(key)));
        }
    }
}

void CharacterWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        lastKey = (event->y() / squareSize) * columns + event->x() / squareSize;
        if (QChar(lastKey).category() != QChar::Other_NotAssigned)
            emit characterSelected(QString(QChar(lastKey)));
        update();
    }
    else
        QWidget::mousePressEvent(event);
}

void CharacterWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPoint widgetPosition = mapFromGlobal(event->globalPos());
    uint key = (widgetPosition.y() / squareSize) * columns + widgetPosition.x() / squareSize;

    QString text = QString::fromLatin1("<p>Character: <span style=\"font-size: 24pt; font-family: %1\">").arg(displayFont.family())
                  + QChar(key)
                  + QString::fromLatin1("</span><p>Value: 0x")
                  + QString::number(key, 16);
    QToolTip::showText(event->globalPos(), text, this);
}

void CharacterWidget::calculateSquareSize()
{
   squareSize = qMax(16, 4 + QFontMetrics(displayFont, this).height());
}


void CharacterWidget::updateStyle(const QString &fontStyle)
{
    QFontDatabase fontDatabase;
    const QFont::StyleStrategy oldStrategy = displayFont.styleStrategy();
    displayFont = fontDatabase.font(displayFont.family(), fontStyle, displayFont.pointSize());
    displayFont.setStyleStrategy(oldStrategy);
    calculateSquareSize();
    adjustSize();
    update();
}

void CharacterWidget::updateFontMerging(bool enable)
{
    if (enable)
        displayFont.setStyleStrategy(QFont::PreferDefault);
    else
        displayFont.setStyleStrategy(QFont::NoFontMerging);
    adjustSize();
    update();
}

