// $Id: monthgraphicsitem.h 294 2010-03-05 18:37:10Z  $
// (c) 2006, Parallel Pixels Ltd.

#ifndef MONTHGRAPHICSITEM_H
#define MONTHGRAPHICSITEM_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QColor>

const   int     MG_ITEM_DAY = 0;
const   int     MG_ITEM_INMONTH = 1;
const   int     MG_ITEM_HASRUN = 2;

class MonthGraphicsItem : public QGraphicsRectItem
{
public:

    MonthGraphicsItem( qreal x, qreal y, qreal width, qreal height);

    void hoverEnterEvent( QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent( QGraphicsSceneHoverEvent * event);

    void setBackGroundColor( const QColor &color) { mBackGround = color;};
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:

    bool    mInside;
    QColor  mBackGround;
};

#endif // MONTHGRAPHICSITEM_H
