#include "imagedelegate.h"
#include "iconpreviewarea.h"
#include <QComboBox>
ImageDelegate::ImageDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{}

QWidget *ImageDelegate::createEditor(QWidget *parent,
                                     const QStyleOptionViewItem & /* option */,
                                     const QModelIndex &index) const
{
    QComboBox *comboBox = new QComboBox(parent);
    if (index.column() == 1){
        comboBox->addItems(IconPreviewArea::iconModeNames());
    }
    else if (index.column() == 2){
        comboBox->addItems(IconPreviewArea::iconStateNames());
    }
    connect(comboBox, QOverload<int>::of(&QComboBox::activated),
            this, &ImageDelegate::emitCommitData);

    return comboBox;
}

void ImageDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *comboBox = qobject_cast<QComboBox *>(editor);
    if (!comboBox){
        return;
    }
    int pos = comboBox->findText(index.model()->data(index).toString(),
                                 Qt::MatchExactly);
    comboBox->setCurrentIndex(pos);
}

void ImageDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                 const QModelIndex &index) const
{
    QComboBox *comboBox = qobject_cast<QComboBox *>(editor);
    if (!comboBox){
        return;
    }
    model->setData(index, comboBox->currentText());
}

void ImageDelegate::emitCommitData()
{
    emit commitData(qobject_cast<QWidget *>(sender()));
}
