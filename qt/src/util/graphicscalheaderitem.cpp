// $Id: graphicscalheaderitem.cpp 294 2010-03-05 18:37:10Z  $
// (c) 2009, Parallel Pixels Ltd.

#include "GraphicsCalHeaderItem.h"

#include <QRectF>
#include <QColor>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QLabel>
#include <QGraphicsProxyWidget>

#include "src/data/weather.h"
#include "src/gui/temperatureunits.h"
#include "src/util/graphicsbuttonitem.h"


GraphicsCalHeaderItem::GraphicsCalHeaderItem( qreal x, qreal y, qreal width, qreal height)
    : QGraphicsRectItem( x, y, width, height)
{
    setAcceptHoverEvents( true);
    mInside = false;
    mBackGround.setRgb( 255, 255, 255);

    mDateLabel = new QGraphicsProxyWidget();
    QLabel      *dateLabel = new QLabel( "ddd - MMM dd");
    dateLabel->setStyleSheet( "font: 80 9pt \"Arial\";background-color: transparent;");
    mDateLabel->setWidget( dateLabel);
    mDateLabel->setParentItem( this);
    mDateLabel->setPos( boundingRect().x() + 4.0, boundingRect().y() + 3.0);

    mWeatherButton = new GraphicsButtonItem( WEATHERBUTTON);
    mWeatherButton->setWidget( new QPushButton( "Weather"));
    mWeatherButton->setParentItem( this);
    mWeatherButton->setPos( boundingRect().x() + 2.0, boundingRect().y() + 22.0);
    mWeatherButton->setVisible( false);

    mPhysicalButton = new GraphicsButtonItem( PHYSICALBUTTON);
    mPhysicalButton->setWidget( new QPushButton( "Physical"));
    mPhysicalButton->setParentItem( this);
    mPhysicalButton->setPos( boundingRect().x() + 2.0, boundingRect().y() + 47.0);
    mPhysicalButton->setVisible( false);

    mJournalButton = new GraphicsButtonItem( JOURNALBUTTON);
    mJournalButton->setWidget( new QPushButton( "Journal"));
    mJournalButton->setParentItem( this);
    mJournalButton->setPos( boundingRect().x() + 2.0, boundingRect().y() + 72.0);
    mJournalButton->setVisible( false);
}

void GraphicsCalHeaderItem::hoverEnterEvent( QGraphicsSceneHoverEvent *event)
{
    mInside = true;
    mWeatherButton->setVisible( true);
    mPhysicalButton->setVisible( true);
    mJournalButton->setVisible( true);
    update();
}

void GraphicsCalHeaderItem::hoverLeaveEvent( QGraphicsSceneHoverEvent *event)
{
    mInside = false;
    if( mWeatherButton->data( 0).toInt() < 0)
        mWeatherButton->setVisible( false);
    mPhysicalButton->setVisible( false);
    mJournalButton->setVisible( false);
    update();
}

void GraphicsCalHeaderItem::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF       r = boundingRect();

    painter->setPen( QPen( QBrush( QColor( Qt::gray)), 1.0));

    if( mInside)
        painter->setBrush( mBackGround.darker( 105));
    else
        painter->setBrush( mBackGround);

    painter->drawRoundedRect( r, 7.5, 7.5);
}

void GraphicsCalHeaderItem::setDate( const QDate &date)
{
    mDate = date;

    QLabel      *label = (QLabel *) mDateLabel->widget();
    label->setText( date.toString( "ddd - MMM d" ));


    mWeatherButton->setDate( date);
    Weather     w;
    w.restoreByJulianDay( date.toJulianDay());

    QPushButton     *p = (QPushButton *) mWeatherButton->widget();
    mWeatherButton->setData( 0, w.id());
    if( w.id() > 0)
    {
        mWeatherButton->setVisible( true);
        TemperatureString       ts;
        ts.setValue( w.temperature());
        p->setText( ts.text());
        QString     iconName = ":/main/icons/weather" + QString::number( w.sky());
        p->setIcon( QIcon( iconName));
    }
    else
    {
        mWeatherButton->setVisible( false);
        p->setText( "Weather");
        p->setIcon( QIcon( ""));
    }
}

