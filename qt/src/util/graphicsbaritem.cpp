// $Id: graphicsbaritem.cpp 370 2010-12-14 23:23:50Z boffyflow $
// (c) 2009, Parallel Pixels Ltd.

#include <QRectF>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLinearGradient>

#include "src/util/graphicsbaritem.h"

#include "src/gui/runviewer.h"
#include "src/gui/physicaleditor.h"
#include "src/util/weekgraphicsview.h"


GraphicsBarItem::GraphicsBarItem( qreal x, qreal y, qreal width, qreal height)
    : QGraphicsRectItem( x, y, width, height)
{
    setAcceptHoverEvents( true);
    mInside = false;
    mBackGround.setRgb( 0, 255, 0);
}

void GraphicsBarItem::hoverEnterEvent( QGraphicsSceneHoverEvent *event)
{
    mInside = true;
    setCursor( Qt::PointingHandCursor);
    update();
}

void GraphicsBarItem::hoverLeaveEvent( QGraphicsSceneHoverEvent *event)
{
    mInside = false;
    unsetCursor();
    update();
}

void GraphicsBarItem::mousePressEvent( QGraphicsSceneMouseEvent * event)
{

    if( data( GB_ITEM_TYPE).toString().compare( "run") == 0)
    {
        RunViewer       *rv = new RunViewer( data( GB_ITEM_ID).toInt(), scene()->views().at( 0));

        rv->show();
    }
    else if( data( GB_ITEM_TYPE).toString().compare( "physical") == 0)
    {
        PhysicalEditor  pe( QDate::currentDate(), data( GB_ITEM_ID).toInt(), scene()->views().at( 0));

        pe.exec();
    }

    ((WeekGraphicsView *) scene()->views().at( 0))->loadDataIntoView();
}

void GraphicsBarItem::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF       r = boundingRect();

    painter->setPen( QPen( QBrush( QColor( Qt::black)), 1.0));

    QLinearGradient     lg( QPointF( r.x(), r.y() + r.height()), QPointF( r.x(), r.y()));

    if( mInside)
    {
        lg.setColorAt( 0.0, mBackGround.lighter( 150));
        lg.setColorAt( 1.0, mBackGround.darker( 150));
    }
    else
    {
        lg.setColorAt( 0.0, mBackGround.lighter( 180));
        lg.setColorAt( 1.0, mBackGround);
    }

    painter->setBrush( lg);

    painter->drawRect( r);
    painter->setFont( QFont( "Arial", 8));
    painter->drawText( r.x(), r.y() + r.height() + 12.0, data( GB_ITEM_LABEL).toString());

    if( data( GB_ITEM_RACE).toInt() > 0)
        painter->drawPixmap( r.x() + 0.5 * r.width() - 16.0, r.y() + 0.5 * r.height() - 16.0, QPixmap( ":/main/icons/trophy.xpm"));
}
