#ifndef GRAPHICSCALENTRYITEM_H
#define GRAPHICSCALENTRYITEM_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QColor>

class GraphicsCalEntryItem : public QGraphicsRectItem
{
public:

    GraphicsCalEntryItem( qreal x, qreal y, qreal width, qreal height);

    void hoverEnterEvent( QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent( QGraphicsSceneHoverEvent * event);
    void mousePressEvent( QGraphicsSceneMouseEvent * event);

    void setBackGroundColor( const QColor &color) { mBackGround = color;};
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:

    bool    mInside;
    QColor  mBackGround;
};

#endif // GRAPHICSCALENTRYITEM_H
