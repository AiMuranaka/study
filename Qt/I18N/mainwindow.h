#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAction;
class QGroupBox;
class QLabel;
class QListWidget;
class QMenu;
class QRadioButton;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    void createGroupBox();

    QWidget *centralWidget;
    QLabel *label;
    QGroupBox *groupBox;
    QListWidget *listWidget;
    QRadioButton *perspectiveRadioButton;
    QRadioButton *isometricRadioButton;
    QRadioButton *obliqueRadioButton;
    QMenu *fileMenu;
    QAction *exitAction;
};

#endif