// $Id: weekgraphicsitem.h 294 2010-03-05 18:37:10Z  $
// (c) 2006, Parallel Pixels Ltd.

#ifndef WEEKGRAPHICSITEM_H
#define WEEKGRAPHICSITEM_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QColor>

const   int     WG_ITEM_TYPE = 0;
const   int     WG_ITEM_DATE = 1;

class WeekGraphicsItem : public QGraphicsRectItem
{
public:

    WeekGraphicsItem( qreal x, qreal y, qreal width, qreal height);

    void hoverEnterEvent( QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent( QGraphicsSceneHoverEvent * event);
    void mousePressEvent( QGraphicsSceneMouseEvent * event);

    void setBackGroundColor( const QColor &color) { mBackGround = color;};
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:

    bool    mInside;
    QColor  mBackGround;
};

#endif // WEEKGRAPHICSITEM_H
