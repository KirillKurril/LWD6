#include "graphic.h"


#include "searchtreeitem.h"
#include <QPainter>

SearchTreeItem::SearchTreeItem(QGraphicsItem *parent) : QGraphicsItem(parent) {}

QRectF SearchTreeItem::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void SearchTreeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QRectF rec = boundingRect();
    painter->drawRect(rec);
}

