// $Id: weekgraphicsitem.cpp 294 2010-03-05 18:37:10Z  $
// (c) 2006, Parallel Pixels Ltd.

#include <QRectF>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "src/util/weekgraphicsitem.h"

#include "src/gui/runeditor.h"
#include "src/gui/physicaleditor.h"
#include "src/gui/weathereditor.h"
#include "src/gui/journaleditor.h"
#include "src/util/weekgraphicsview.h"


WeekGraphicsItem::WeekGraphicsItem( qreal x, qreal y, qreal width, qreal height)
    : QGraphicsRectItem( x, y, width, height)
{
    setAcceptHoverEvents( true);
    mInside = false;
    mBackGround.setRgb( 255, 255, 255);
}

void WeekGraphicsItem::hoverEnterEvent( QGraphicsSceneHoverEvent *event)
{
    mInside = true;
    setCursor( Qt::PointingHandCursor);
    update();
}

void WeekGraphicsItem::hoverLeaveEvent( QGraphicsSceneHoverEvent *event)
{
    mInside = false;
    unsetCursor();
    update();
}

void WeekGraphicsItem::mousePressEvent( QGraphicsSceneMouseEvent * event)
{
    if( data( WG_ITEM_TYPE).toString().compare( "run") == 0)
    {
        RunEditor       re( data( WG_ITEM_DATE).toDate(), -1, scene()->views().at( 0));

        re.exec();
    }
    else if( data( WG_ITEM_TYPE).toString().compare( "physical") == 0)
    {
        Physical            p;
        p.restoreByJulianDay( data( WG_ITEM_DATE).toDate().toJulianDay());
        if( p.id() < 0)
        {
            PhysicalEditor       pe( data( WG_ITEM_DATE).toDate(), -1, scene()->views().at( 0));

            pe.exec();
        }
    }
    else if( data( WG_ITEM_TYPE).toString().compare( "weather") == 0)
    {
        Weather            w;
        w.restoreByJulianDay( data( WG_ITEM_DATE).toDate().toJulianDay());
        if( w.id() < 0)
        {
            WeatherEditor       we( data( WG_ITEM_DATE).toDate(), -1, scene()->views().at( 0));

            we.exec();
        }
    }
    else if( data( WG_ITEM_TYPE).toString().compare( "journal") == 0)
    {
        JournalEntry            j;
        j.restoreByJulianDay( data( WG_ITEM_DATE).toDate().toJulianDay());
        if( j.id() < 0)
        {
            JournalEditor       je( data( WG_ITEM_DATE).toDate(), -1, scene()->views().at( 0));

            je.exec();
        }
    }

   ((WeekGraphicsView *) scene()->views().at( 0))->loadDataIntoView();
}

void WeekGraphicsItem::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF       r = boundingRect();

    painter->setPen( QPen( QBrush( QColor( Qt::gray)), 1.0));

    if( mInside)
        painter->setBrush( mBackGround.darker( 105));
    else
        painter->setBrush( mBackGround);

    painter->drawRect( r);
}
