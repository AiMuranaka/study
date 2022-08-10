#ifndef CHARACTERWIDGET_H
#define CHARACTERWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class CharacterWidget; }
QT_END_NAMESPACE

class CharacterWidget : public QWidget
{
    Q_OBJECT

public:
    CharacterWidget(QWidget *parent = nullptr);
    QSize sizeHint() const override;

public slots:
    void updateFont(const QFont &font);
    void updateSize(const QString &fontSize);
    void updateStyle(const QString &fontStyle);
    void updateFontMerging(bool enable);

signals:
    void characterSelected(const QString &character);

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:

    void calculateSquareSize();

    QFont displayFont;
    int columns = 16;
    int lastKey = -1;
    int squareSize = 0;
};
#endif
