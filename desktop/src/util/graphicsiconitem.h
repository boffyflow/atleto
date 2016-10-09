// $Id: graphicsiconitem.h 294 2010-03-05 18:37:10Z  $
// (c) 2009, Parallel Pixels Ltd.

#ifndef GRAPHICSICONITEM_H
#define GRAPHICSICONITEM_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QColor>

const   int     GI_ITEM_TYPE = 0;
const   int     GI_ITEM_ID = 1;
const   int     GI_ITEM_LABEL = 2;
const   int     GI_ITEM_ICON = 3;

class GraphicsIconItem : public QGraphicsRectItem
{
public:

    GraphicsIconItem( qreal x, qreal y, qreal width, qreal height);

    void hoverEnterEvent( QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent( QGraphicsSceneHoverEvent * event);
    void mousePressEvent( QGraphicsSceneMouseEvent * event);

    void setBackGroundColor( const QColor &color) { mBackGround = color;};
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:

    bool    mInside;
    QColor  mBackGround;
};

#endif // GRAPHICSICONITEM_H
