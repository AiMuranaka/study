#include "iconpreviewarea.h"
#include "ui_iconpreviewarea.h"
#include <QGridLayout>

IconPreviewArea::IconPreviewArea(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout *mainLayout = new QGridLayout(this);

    for (int row = 0; row < NumStates; ++row) {
        stateLabels[row] = createHeaderLabel(IconPreviewArea::iconStateNames().at(row));
        mainLayout->addWidget(stateLabels[row], row + 1, 0);
    }
    Q_ASSERT(NumStates == 2);

    for (int column = 0; column < NumModes; ++column) {
        modeLabels[column] = createHeaderLabel(IconPreviewArea::iconModeNames().at(column));
        mainLayout->addWidget(modeLabels[column], 0, column + 1);
    }
    Q_ASSERT(NumModes == 4);

    for (int column = 0; column < NumModes; ++column) {
        for (int row = 0; row < NumStates; ++row) {
            pixmapLabels[column][row] = createPixmapLabel();
            mainLayout->addWidget(pixmapLabels[column][row], row + 1, column + 1);
        }
    }

}

void IconPreviewArea::setIcon(const QIcon &icon)
{
    this->icon = icon;
    updatePixmapLabels();
}

void IconPreviewArea::setSize(const QSize &size)
{
    if (size != this->size) {
        this->size = size;
        updatePixmapLabels();
    }
}

QLabel *IconPreviewArea::createHeaderLabel(const QString &text)
{
    QLabel *label = new QLabel(tr("<b>%1</b>").arg(text));
    label->setAlignment(Qt::AlignCenter);
    return label;
}

QLabel *IconPreviewArea::createPixmapLabel()
{
    QLabel *label = new QLabel;
    label->setEnabled(false);
    label->setAlignment(Qt::AlignCenter);
    label->setFrameShape(QFrame::Box);
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label->setBackgroundRole(QPalette::Base);
    label->setAutoFillBackground(true);
    label->setMinimumSize(132, 132);
    return label;
}

void IconPreviewArea::updatePixmapLabels()
{
    QWindow *window = nullptr;
    if (const QWidget *nativeParent = nativeParentWidget())
        window = nativeParent->windowHandle();
    for (int column = 0; column < NumModes; ++column) {
        for (int row = 0; row < NumStates; ++row) {
            const QPixmap pixmap =
                icon.pixmap(window, size, IconPreviewArea::iconModes().at(column),
                            IconPreviewArea::iconStates().at(row));
            QLabel *pixmapLabel = pixmapLabels[column][row];
            pixmapLabel->setPixmap(pixmap);
            pixmapLabel->setEnabled(!pixmap.isNull());
            QString toolTip;
            if (!pixmap.isNull()) {
                const QSize actualSize = icon.actualSize(size);
                toolTip =
                    tr("Size: %1x%2\nActual size: %3x%4\nDevice pixel ratio: %5")
                        .arg(size.width()).arg(size.height())
                        .arg(actualSize.width()).arg(actualSize.height())
                        .arg(pixmap.devicePixelRatioF());
            }
            pixmapLabel->setToolTip(toolTip);
        }
    }
}
