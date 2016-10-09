// $Id: barchart.cpp 223 2009-06-12 00:16:18Z robert $
// (c) 2009, Parallel Pixels Ltd.

#include <QGraphicsRectItem>
#include <QLinearGradient>
#include <QBrush>
#include <QFont>
#include <QtAlgorithms>
#include <math.h>

#include "barchart.h"

BarChart::BarChart( const QString& title)
{
    QGraphicsTextItem   *text = new QGraphicsTextItem( title, graphicsItem());
    text->setFont( QFont( "Helvetica", 10, QFont::Bold));
    text->setPos( ( graphicsItem()->boundingRect().width() - text->boundingRect().width()) * 0.5, 0.0);

    mTitleHeight = text->boundingRect().height();
    mBarColor.setRgb( 0, 0, 255);
    mZeroBased = true;
}

BarChart::~BarChart()
{
}

void BarChart::setBarColor( const QColor &color)
{
    mBarColor = color;
}

void BarChart::setZeroBased( const bool zeroBased)
{
    mZeroBased = zeroBased;
}

void BarChart::draw()
{
    QMap< QString, double>::const_iterator      i;
    int             step = 0;
    const qreal     BOTTOMLABELHEIGHT = 25.0;   // px
    const qreal     TOPBARTEXTHEIGHT = 22.0;    // px
    const qreal     LEFTPADDING = 10.0;
    const qreal     RIGHTPADDING = 10.0;

    qreal   box_height = graphicsItem()->boundingRect().height();
    qreal   box_width = graphicsItem()->boundingRect().width();

    QLinearGradient     linearGrad( 0.0, 0.0, 0.0, 1.0);
    linearGrad.setCoordinateMode( QGradient::ObjectBoundingMode);
    QColor      color = mBarColor;
    color.setAlpha( 200);
    linearGrad.setColorAt( 0, color);
    color.setAlpha( 10);
    linearGrad.setColorAt( 1, color);

    // drawing the x and y axis

    // drawing the bars

    qreal       dx = ( box_width - LEFTPADDING - RIGHTPADDING) / mData.count(); // width for one bar

    QList<double>       sList( mData.values());
    qSort( sList);
    double      maxValue = sList[sList.count() - 1];
    double      minValue = sList[0];
    int         j = 1;
    while( minValue < 0.001 && sList.count() > j)
    {
        minValue = sList[j];
        j++;
    }

    if( minValue > 0.0)     // round the min value to the next sensible lower cutoff...
    {
        int    d = (int) log10( minValue);
        double x = minValue / ( pow( 10.0, d));
        minValue = (int) x * ( pow( 10.0, d));
    }

    if( mZeroBased == true)
        minValue = 0.0;

    qreal       maxheight = box_height - mTitleHeight - BOTTOMLABELHEIGHT - TOPBARTEXTHEIGHT + 5.0; // max bar height in pixels

    for( i = mData.constBegin(); i != mData.constEnd(); ++i)
    {
        // actual bar

        double      bvalue = i.value() - minValue;
        if( bvalue < 0.0)
            bvalue = 0.0;

        qreal       value = bvalue * maxheight / ( maxValue - minValue);  // value scaled to pixels
        QGraphicsRectItem   *r = new QGraphicsRectItem( LEFTPADDING + step * dx, box_height - BOTTOMLABELHEIGHT - value, dx - LEFTPADDING, value, graphicsItem());
        r->setBrush( QBrush( linearGrad));

        // bar text
        QGraphicsTextItem   *bt = new QGraphicsTextItem( QString::number( i.value()), graphicsItem());
        qreal       btw = bt->boundingRect().width();
        bt->setPos( LEFTPADDING + step * dx + ( ( dx - LEFTPADDING - btw) * 0.5), box_height - BOTTOMLABELHEIGHT - TOPBARTEXTHEIGHT - value);

        // label
        QString     label = i.key();
        QGraphicsTextItem   *t = new QGraphicsTextItem( label.remove( 0, 2), graphicsItem());
        qreal       ltw = t->boundingRect().width();
        t->setPos( LEFTPADDING + step * dx + ( ( dx - LEFTPADDING - ltw) * 0.5), box_height - BOTTOMLABELHEIGHT);

        step++;
    }
}
