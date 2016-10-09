// $Id: graphicsrunitem.cpp 294 2010-03-05 18:37:10Z  $
// (c) 2009, Parallel Pixels Ltd.

#include <QRectF>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "graphicsrunitem.h"

#include "src/gui/runeditor.h"


GraphicsRunItem::GraphicsRunItem( qreal x, qreal y, qreal width, qreal height)
    : QGraphicsRectItem( x, y, width, height)
{
    setAcceptHoverEvents( true);
    mInside = false;
    mBackGround.setRgb( 0, 255, 0);
}

void GraphicsRunItem::hoverEnterEvent( QGraphicsSceneHoverEvent *event)
{
    mInside = true;
    update();
}

void GraphicsRunItem::hoverLeaveEvent( QGraphicsSceneHoverEvent *event)
{
    mInside = false;
    update();
}

void GraphicsRunItem::mousePressEvent( QGraphicsSceneMouseEvent * event)
{
    RunEditor       re( QDate::currentDate(), data( 1).toInt(), scene()->views().at( 0));

    re.exec();
}

void GraphicsRunItem::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF       r = boundingRect();

    painter->setPen( QPen( QBrush( QColor( Qt::black)), 1.0));

    if( mInside)
        painter->setBrush( mBackGround.darker( 110));
    else
        painter->setBrush( mBackGround);

    painter->drawRect( r);
    painter->setFont( QFont( "Arial", 8));
    painter->drawText( r.x(), r.y() + r.height() + 12.0, data( 0).toString());
}
