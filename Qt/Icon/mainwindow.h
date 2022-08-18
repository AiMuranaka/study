#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QActionGroup>
#include <QButtonGroup>

class IconPreviewArea;
class QTableWidget;
class IconSizeSpinBox;
class QLabel;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

 //   void loadImages(const QStringList &fileNames);

    void show();

private slots:
    void about();
    void changeStyle(bool checked);
    void changeSize(int, bool);
    void triggerChangeSize();
//    void changeIcon();
//    void addSampleImages();
//    void addOtherImages();
    void removeAllImages();
//    void useHighDpiPixmapsChanged(int checkState);
//    void screenChanged();

private:
//    QWidget *createImagesGroupBox();
//    QWidget *createIconSizeGroupBox();
//    QWidget *createHighDpiIconSizeGroupBox();
//    void createActions();
//    void createContextMenu();
//    void checkCurrentStyle();
    void addImages(const QString &directory);

//    IconPreviewArea *previewArea;

//    QTableWidget *imagesTable;

//    QButtonGroup *sizeButtonGroup;
//    IconSizeSpinBox *otherSpinBox;

//    QLabel *devicePixelRatioLabel;
//    QLabel *screenNameLabel;

//    QAction *addOtherImagesAct;
//    QAction *addSampleImagesAct;
//    QAction *removeAllImagesAct;
//    QAction *guessModeStateAct;
//    QAction *nativeFileDialogAct;
//    QActionGroup *styleActionGroup;
};

#endif // MAINWINDOW_H
