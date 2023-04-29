#ifndef GRAPHIC_H
#define GRAPHIC_H
#include <QGraphicsItem>

class SearchTreeItem : public QGraphicsItem {
public:
    explicit SearchTreeItem(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // GRAPHIC_H
