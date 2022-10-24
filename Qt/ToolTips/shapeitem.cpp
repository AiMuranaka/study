#include "shapeitem.h"

QPainterPath ShapeItem::path() const
{
    return myPath;
}
QPoint ShapeItem::position() const
{
    return myPosition;
}
