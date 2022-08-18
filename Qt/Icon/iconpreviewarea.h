#ifndef ICONPREVIEWAREA_H
#define ICONPREVIEWAREA_H

#include <QWidget>
#include <QVector>
#include <QLabel>
#include <QIcon>

QT_BEGIN_NAMESPACE
namespace Ui { class IconPreviewArea; }
QT_END_NAMESPACE

class IconPreviewArea : public QWidget
{
    Q_OBJECT

public:
    explicit IconPreviewArea(QWidget *parent = nullptr);

    void setIcon(const QIcon &icon);
    void setSize(const QSize &size);

    static QVector<QIcon::Mode> iconModes();
    static QVector<QIcon::State> iconStates();
    static QStringList iconModeNames();
    static QStringList iconStateNames();

private:
    QLabel *createHeaderLabel(const QString &text);
    QLabel *createPixmapLabel();
    void updatePixmapLabels();

    enum { NumModes = 4, NumStates = 2};

    QIcon icon;
    QSize size;
    QLabel *stateLabels[NumStates];
    QLabel *modeLabels[NumModes];
    QLabel *pixmapLabels[NumStates][NumModes];
};

QVector<QIcon::Mode> IconPreviewArea::iconModes()
{
    static const QVector<QIcon::Mode> result = {QIcon::Normal, QIcon::Active, QIcon::Disabled, QIcon::Selected};
    return result;
}

QVector<QIcon::State> IconPreviewArea::iconStates()
{
    static const QVector<QIcon::State> result = {QIcon::Off, QIcon::On};
    return result;
}

QStringList IconPreviewArea::iconModeNames()
{
    static const QStringList result = {tr("Normal"), tr("Active"),tr("Disabled"),tr("Selected")};
    return result;
}

QStringList IconPreviewArea::iconStateNames()
{
    static const QStringList result = {tr("Off"),tr("On")};
    return result;
}

#endif // ICONPREVIEWAREA_H
