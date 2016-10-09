#include "graphicscalentryitem.h"

#include <QRectF>
#include <QGraphicsSceneHoverEvent>

GraphicsCalEntryItem::GraphicsCalEntryItem( qreal x, qreal y, qreal width, qreal height)
    : QGraphicsRectItem( x, y, width, height)
{
    setAcceptHoverEvents( true);
    mInside = false;
    mBackGround.setRgb( 255, 255, 255);
}

void GraphicsCalEntryItem::hoverEnterEvent( QGraphicsSceneHoverEvent *event)
{
    mInside = true;
    update();
}

void GraphicsCalEntryItem::hoverLeaveEvent( QGraphicsSceneHoverEvent *event)
{
    mInside = false;
    update();
}

void GraphicsCalEntryItem::mousePressEvent( QGraphicsSceneMouseEvent * event)
{
//   InputDialog     dialog;

//    dialog.exec();
}

void GraphicsCalEntryItem::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF       r = boundingRect();

    painter->setPen( QPen( QBrush( QColor( Qt::gray)), 1.0));

    if( mInside)
        painter->setBrush( mBackGround.darker( 105));
    else
        painter->setBrush( mBackGround);

    painter->drawRoundedRect( r, 7.5, 7.5);

    painter->setPen( Qt::DotLine);
    for( int i = 1; i < 24; i++)
    {
        qreal       ypos = r.height() / 24.0;

        painter->drawLine( r.x() + 2.0, r.y() + i * ypos, r.x() + r.width() - 2.0, r.y() + i * ypos);
    }
}
