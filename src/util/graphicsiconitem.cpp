// $Id: graphicsiconitem.cpp 294 2010-03-05 18:37:10Z  $
// (c) 2009, Parallel Pixels Ltd.

#include <QRectF>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "src/util/graphicsiconitem.h"

#include "src/gui/weathereditor.h"
#include "src/gui/journaleditor.h"
#include "src/util/weekgraphicsview.h"


GraphicsIconItem::GraphicsIconItem( qreal x, qreal y, qreal width, qreal height)
    : QGraphicsRectItem( x, y, width, height)
{
    setAcceptHoverEvents( true);
    mInside = false;
    mBackGround.setRgb( 0, 255, 0);
}

void GraphicsIconItem::hoverEnterEvent( QGraphicsSceneHoverEvent *event)
{
    mInside = true;
    setCursor( Qt::PointingHandCursor);
    update();
}

void GraphicsIconItem::hoverLeaveEvent( QGraphicsSceneHoverEvent *event)
{
    mInside = false;
    unsetCursor();
    update();
}

void GraphicsIconItem::mousePressEvent( QGraphicsSceneMouseEvent * event)
{
    if( data( GI_ITEM_TYPE).toString().compare( "weather") == 0)
    {
        WeatherEditor       we( QDate::currentDate(), data( GI_ITEM_ID).toInt(), scene()->views().at( 0));

        we.exec();
    }
    else if( data( GI_ITEM_TYPE).toString().compare( "journal") == 0)
    {
        JournalEditor       je( QDate::currentDate(), data( GI_ITEM_ID).toInt(), scene()->views().at( 0));

        je.exec();
    }

    ((WeekGraphicsView *) scene()->views().at( 0))->loadDataIntoView();
}

void GraphicsIconItem::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF       r = boundingRect();

    if( data( GI_ITEM_LABEL).toString().isEmpty())
    {
        painter->drawPixmap( r.x() + 16, r.y() + 1, 32, 32, data( GI_ITEM_ICON).toString());
    }
    else
    {
        painter->drawPixmap( r.x() + 1, r.y() + 1, 32, 32, data( GI_ITEM_ICON).toString());
        painter->setFont( QFont( "Arial", 8));
        painter->drawText( r.x() + 36, r.y() + 18, data( GI_ITEM_LABEL).toString());
    }
}
