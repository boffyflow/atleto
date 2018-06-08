// $Id: monthgraphicsitem.cpp 294 2010-03-05 18:37:10Z  $
// (c) 2006, Parallel Pixels Ltd.

#include <QRectF>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "src/util/monthgraphicsitem.h"

#include "src/gui/runeditor.h"
#include "src/gui/physicaleditor.h"
#include "src/gui/weathereditor.h"
#include "src/gui/journaleditor.h"
#include "src/util/weekgraphicsview.h"


MonthGraphicsItem::MonthGraphicsItem( qreal x, qreal y, qreal width, qreal height)
    : QGraphicsRectItem( x, y, width, height)
{
    setAcceptHoverEvents( true);
    mInside = false;
    mBackGround.setRgb( 255, 255, 255);
    setData( MG_ITEM_HASRUN, false);
}

void MonthGraphicsItem::hoverEnterEvent( QGraphicsSceneHoverEvent *event)
{
    mInside = true;
    update();
}

void MonthGraphicsItem::hoverLeaveEvent( QGraphicsSceneHoverEvent *event)
{
    mInside = false;
    update();
}

void MonthGraphicsItem::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF       r = boundingRect();


    if( !data( MG_ITEM_INMONTH).toBool())
    {
        painter->setPen( QPen( QBrush( QColor( Qt::gray)), 1.0));
        painter->setBrush( QColor( 245, 245, 245));
    }
    else
    {
        painter->setPen( QPen( QBrush( QColor( Qt::black)), 1.0));
        if( mInside)
            painter->setBrush( mBackGround.darker( 105));
        else
            painter->setBrush( mBackGround);
    }

    painter->drawRect( r.x() + 2, r.y() + 2, r.width() - 4, r.height() - 4);

    painter->drawText( r.x() + 4, r.y() + 14, data( MG_ITEM_DAY).toDate().toString( "d  -  ddd"));

    if( data( MG_ITEM_HASRUN).toBool())
        painter->drawPixmap( r.x() + r.width() - 36, r.y() + r.height() - 38, QPixmap( ":/main/icons/runner32.xpm"));
}
