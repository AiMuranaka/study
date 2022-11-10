#ifndef WIGGLYWIDGET_H
#define WIGGLYWIDGET_H
#include <QBasicTimer>
#include <QWidget>

class WigglyWidget : public QWidget
{
    Q_OBJECT

public:
    WigglyWidget(QWidget *parent = nullptr);


//protected:
    void paintEvent(QPaintEvent *event) override;
    void timerEvent(QTimerEvent *event) override;

    void checkStep();

    int getStep()
    {
        return step;
    }
//private:
    QBasicTimer timer;
    QString text;
    int step;


public slots:
    void setText(const QString &newText) { text = newText; }
};

#endif // WIGGLYWIDGET_H
