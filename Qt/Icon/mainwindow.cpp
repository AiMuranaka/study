
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
#include <QScreen>
#include <QAbstractButton>
#include <QSpinBox>
#include <QFileDialog>
#include <QImageReader>
#include <QTableWidgetItem>
#include <QWindow>
#include <QHeaderView>
#include <QRadioButton>

enum { OtherSize = QStyle::PM_CustomBase };

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

void MainWindow::changeIcon()
{

}

void MainWindow::addSampleImages()
{

}

void MainWindow::addOtherImages()
{

}

void MainWindow::loadImages(const QStringList &fileNames)
{

}

void MainWindow::useHighDpiPixmapsChanged(int checkState)
{

}

void MainWindow::screenChanged()
{


}

QWidget *MainWindow::createImagesGroupBox()
{
    QGroupBox *imagesGroupBox = new QGroupBox(tr("Images"));
    imagesTable = new QTableWidget;

    imagesTable->setSelectionMode(QAbstractItemView::NoSelection);
    imagesTable->setItemDelegate(new ImageDelegate(this));

    const QStringList labels({tr("Image"), tr("Mode"), tr("State")});

    imagesTable->horizontalHeader()->setDefaultSectionSize(90);
    imagesTable->setColumnCount(3);
    imagesTable->setHorizontalHeaderLabels(labels);
    imagesTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    imagesTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    imagesTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    imagesTable->verticalHeader()->hide();

    connect(imagesTable, &QTableWidget::itemChanged,
            this, &MainWindow::changeIcon);

    QVBoxLayout *layout = new QVBoxLayout(imagesGroupBox);
    layout->addWidget(imagesTable);

    return imagesGroupBox;
}

QWidget *MainWindow::createIconSizeGroupBox()
{
    QGroupBox *iconSizeGroupBox = new QGroupBox(tr("Icon Size"));

    sizeButtonGroup = new QButtonGroup(this);
    sizeButtonGroup->setExclusive(true);

    connect(sizeButtonGroup, QOverload<int, bool>::of(&QButtonGroup::buttonToggled),
            this, &MainWindow::changeSize);

    QRadioButton *smallRadioButton = new QRadioButton;
    sizeButtonGroup->addButton(smallRadioButton, QStyle::PM_SmallIconSize);
    QRadioButton *largeRadioButton = new QRadioButton;
    sizeButtonGroup->addButton(largeRadioButton, QStyle::PM_LargeIconSize);
    QRadioButton *toolBarRadioButton = new QRadioButton;
    sizeButtonGroup->addButton(toolBarRadioButton, QStyle::PM_ToolBarIconSize);
    QRadioButton *listViewRadioButton = new QRadioButton;
    sizeButtonGroup->addButton(listViewRadioButton, QStyle::PM_ListViewIconSize);
    QRadioButton *iconViewRadioButton = new QRadioButton;
    sizeButtonGroup->addButton(iconViewRadioButton, QStyle::PM_IconViewIconSize);
    QRadioButton *tabBarRadioButton = new QRadioButton;
    sizeButtonGroup->addButton(tabBarRadioButton, QStyle::PM_TabBarIconSize);
    QRadioButton *otherRadioButton = new QRadioButton(tr("Other:"));
    sizeButtonGroup->addButton(otherRadioButton, OtherSize);

    otherSpinBox = new IconSizeSpinBox;
    otherSpinBox->setRange(8, 256);
    const QString spinBoxToolTip =
        tr("Enter a custom size within %1..%2")
           .arg(otherSpinBox->minimum()).arg(otherSpinBox->maximum());
    otherSpinBox->setValue(64);
    otherSpinBox->setToolTip(spinBoxToolTip);
    otherRadioButton->setToolTip(spinBoxToolTip);

    connect(otherSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
            this, &MainWindow::triggerChangeSize);

    QHBoxLayout *otherSizeLayout = new QHBoxLayout;
    otherSizeLayout->addWidget(otherRadioButton);
    otherSizeLayout->addWidget(otherSpinBox);
    otherSizeLayout->addStretch();

    QGridLayout *layout = new QGridLayout(iconSizeGroupBox);
    layout->addWidget(smallRadioButton, 0, 0);
    layout->addWidget(largeRadioButton, 1, 0);
    layout->addWidget(toolBarRadioButton, 2, 0);
    layout->addWidget(listViewRadioButton, 0, 1);
    layout->addWidget(iconViewRadioButton, 1, 1);
    layout->addWidget(tabBarRadioButton, 2, 1);
    layout->addLayout(otherSizeLayout, 3, 0, 1, 2);
    layout->setRowStretch(4, 1);
    return iconSizeGroupBox;
}

QWidget *MainWindow::createHighDpiIconSizeGroupBox()
{
//    QGroupBox *createHigh
}

void MainWindow::createActions()
{

}

void MainWindow::createContextMenu()
{

}

void MainWindow::checkCurrentStyle()
{

}
