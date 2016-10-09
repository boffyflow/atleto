// $Id: graphicsrunitem.h 294 2010-03-05 18:37:10Z  $
// (c) 2009, Parallel Pixels Ltd.

#ifndef GRAPHICSRUNITEM_H
#define GRAPHICSRUNITEM_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QColor>

class GraphicsBarItem : public QGraphicsRectItem
{
public:

    GraphicsBarItem( qreal x, qreal y, qreal width, qreal height);

    void hoverEnterEvent( QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent( QGraphicsSceneHoverEvent * event);
    void mousePressEvent( QGraphicsSceneMouseEvent * event);

    void setBackGroundColor( const QColor &color) { mBackGround = color;};
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:

    bool    mInside;
    QColor  mBackGround;
};

#endif // GRAPHICSRUNITEM_H
