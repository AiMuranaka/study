#include "shapeitem.h"

QPainterPath ShapeItem::path() const
{
    return myPath;
}
void ShapeItem::setPath(const QPainterPath &path)
{
    myPath = path;
}

QPoint ShapeItem::position() const
{
    return myPosition;
}
void ShapeItem::setPosition(const QPoint &position)
{
    myPosition = position;
}

QColor ShapeItem::color() const
{
    return myColor;
}
void ShapeItem::setColor(const QColor &color)
{
    myColor = color;
}

QString ShapeItem::toolTip() const
{
    return myToolTip;
}
void ShapeItem::setToolTip(const QString &toolTip)
{
    myToolTip = toolTip;
}


