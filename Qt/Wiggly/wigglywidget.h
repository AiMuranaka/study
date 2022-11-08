#ifndef WIGGLYWIDGET_H
#define WIGGLYWIDGET_H
#include <QBasicTimer>
#include <QWidget>

class WigglyWidget : public QWidget
{
    Q_OBJECT

public:
    WigglyWidget(QWidget *parent = nullptr);

public slots:
    void setText(const QString &newText) { text = newText; }

protected:
    void paintEvent(QPaintEvent *event) override;
    void timerEvent(QTimerEvent *event) override;

    void checkStep();

private:
    QBasicTimer timer;
    QString text;
    int step;
};

#endif // WIGGLYWIDGET_H
