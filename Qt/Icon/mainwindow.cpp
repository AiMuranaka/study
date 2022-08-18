
#include "mainwindow.h"
#include "iconpreviewarea.h"
#include "iconsizespinbox.h"
#include "imagedelegate.h"
#include <QGridLayout>
#include <QGroupBox>
#include <QMessageBox>
#include <QStyleFactory>
#include <QApplication>
#include <QStyle>
#include <QAbstractButton>
#include <QSpinBox>
#include <QFileDialog>
#include <QImageReader>
#include <QTableWidgetItem>
#include <QWindow>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    createActions();

    QGridLayout *mainLayout = new QGridLayout(centralWidget);

    QGroupBox *previewGroupBox = new QGroupBox(tr("Preview"));
    previewArea = new IconPreviewArea(previewGroupBox);
    QVBoxLayout *previewLayout = new QVBoxLayout(previewGroupBox);
    previewLayout->addWidget(previewArea);

    mainLayout->addWidget(previewGroupBox, 0, 0, 1, 2);
    mainLayout->addWidget(createImagesGroupBox(), 1, 0);
    QVBoxLayout *vBox = new QVBoxLayout;
    vBox->addWidget(createIconSizeGroupBox());
    vBox->addWidget(createHighDpiIconSizeGroupBox());
    vBox->addItem(new QSpacerItem(0, 0, QSizePolicy::Ignored, QSizePolicy::MinimumExpanding));
    mainLayout->addLayout(vBox, 1, 1);
    createContextMenu();

    setWindowTitle(tr("Icons"));
    checkCurrentStyle();
    sizeButtonGroup->button(OtherSize)->click();
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Icons"),
                       tr("The <b>Icons</b> example illustrates how Qt renders an icon in "
                          "different modes (active, normal, disabled, and selected) and "
                          "states (on and off) based on a set of images."));
}

void MainWindow::changeStyle(bool checked)
{
    if (!checked)
        return;

    const QAction *action = qobject_cast<QAction *>(sender());

    QStyle *style = QStyleFactory::create(action->data().toString());
    Q_ASSERT(style);
    QApplication::setStyle(style);

    const QList<QAbstractButton*> buttons = sizeButtonGroup->buttons();
    for (QAbstractButton *button : buttons) {
        const QStyle::PixelMetric metric = static_cast<QStyle::PixelMetric>(sizeButtonGroup->id(button));
        const int value = style->pixelMetric(metric);
        switch (metric) {
        case QStyle::PM_SmallIconSize:
            button->setText(tr("Small (%1 x %1)").arg(value));
            break;
        case QStyle::PM_LargeIconSize:
            button->setText(tr("Large (%1 x %1)").arg(value));
            break;
        case QStyle::PM_ToolBarIconSize:
            button->setText(tr("Toolbars (%1 x %1)").arg(value));
            break;
        case QStyle::PM_ListViewIconSize:
            button->setText(tr("List views (%1 x %1)").arg(value));
            break;
        case QStyle::PM_IconViewIconSize:
            button->setText(tr("Icon views (%1 x %1)").arg(value));
            break;
        case QStyle::PM_TabBarIconSize:
            button->setText(tr("Tab bars (%1 x %1)").arg(value));
            break;
        default:
            break;
        }
    }

    triggerChangeSize();
}

void MainWindow::changeSize(int id, bool checked)
{
    if (!checked)
        return;

    const bool other = id == int(OtherSize);
    const int extent = other
            ? otherSpinBox->value()
            : QApplication::style()->pixelMetric(static_cast<QStyle::PixelMetric>(id));

    previewArea->setSize(QSize(extent, extent));
    otherSpinBox->setEnabled(other);
}

void MainWindow::triggerChangeSize()
{
    changeSize(sizeButtonGroup->checkedId(), true);
}

void MainWindow::addImages(const QString &directory)
{
    QFileDialog fileDialog(this, tr("Open Images"), directory);
    QStringList mimeTypeFilters;
    const QList<QByteArray> mimeTypes = QImageReader::supportedMimeTypes();
    for (const QByteArray &mimeTypeName : mimeTypes)
        mimeTypeFilters.append(mimeTypeName);
    mimeTypeFilters.sort();
    fileDialog.setMimeTypeFilters(mimeTypeFilters);
    fileDialog.selectMimeTypeFilter(QLatin1String("image/png"));
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setFileMode(QFileDialog::ExistingFiles);
    if (!nativeFileDialogAct->isChecked())
        fileDialog.setOption(QFileDialog::DontUseNativeDialog);
    if (fileDialog.exec() == QDialog::Accepted)
        loadImages(fileDialog.selectedFiles());

    const QFileInfo fileInfo(fileName);
    const QString imageName = fileInfo.baseName();
    const QString fileName2x = fileInfo.absolutePath()
            + QLatin1Char('/') + imageName + QLatin1String("@2x.") + fileInfo.suffix();
    const QFileInfo fileInfo2x(fileName2x);
    const QImage image(fileName);
    const QString toolTip =
            tr("Directory: %1\nFile: %2\nFile@2x: %3\nSize: %4x%5")
            .arg(QDir::toNativeSeparators(fileInfo.absolutePath()), fileInfo.fileName())
            .arg(fileInfo2x.exists() ? fileInfo2x.fileName() : tr("<None>"))
            .arg(image.width()).arg(image.height());
    QTableWidgetItem *fileItem = new QTableWidgetItem(imageName);
    fileItem->setData(Qt::UserRole, fileName);
    fileItem->setIcon(QPixmap::fromImage(image));
    fileItem->setFlags((fileItem->flags() | Qt::ItemIsUserCheckable) & ~Qt::ItemIsEditable);
    fileItem->setToolTip(toolTip);

    QIcon::Mode mode = QIcon::Normal;
    QIcon::State state = QIcon::Off;
    if (guessModeStateAct->isChecked()) {
        if (imageName.contains(QLatin1String("_act"), Qt::CaseInsensitive))
            mode = QIcon::Active;
        else if (imageName.contains(QLatin1String("_dis"), Qt::CaseInsensitive))
            mode = QIcon::Disabled;
        else if (imageName.contains(QLatin1String("_sel"), Qt::CaseInsensitive))
            mode = QIcon::Selected;

        if (imageName.contains(QLatin1String("_on"), Qt::CaseInsensitive))
            state = QIcon::On;

        imagesTable->setItem(row, 0, fileItem);
        QTableWidgetItem *modeItem =
                new QTableWidgetItem(IconPreviewArea::iconModeNames().at(IconPreviewArea::iconModes().indexOf(mode)));
        modeItem->setToolTip(toolTip);
        imagesTable->setItem(row, 1, modeItem);
        QTableWidgetItem *stateItem =
                new QTableWidgetItem(IconPreviewArea::iconStateNames().at(IconPreviewArea::iconStates().indexOf(state)));
        stateItem->setToolTip(toolTip);
        imagesTable->setItem(row, 2, stateItem);
        imagesTable->openPersistentEditor(modeItem);
        imagesTable->openPersistentEditor(stateItem);

        fileItem->setCheckState(Qt::Checked);
    }
}

void MainWindow::removeAllImages()
{
    imagesTable->setRowCount(0);
    changeIcon();
}

void MainWindow::show()
{
    QMainWindow::show();
    connect(windowHandle(), &QWindow::screenChanged, this, &MainWindow::screenChanged);
    screenChanged();
}
