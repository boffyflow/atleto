// $Id: shoestatscontroller.cpp 250 2009-10-23 23:21:18Z robert $
// (c) 2009, Parallel Pixels Ltd.

#include <QGraphicsRectItem>
#include <QFont>

#include "shoestatscontroller.h"

ShoeStatsController::ShoeStatsController()
{
}

ShoeStatsController::~ShoeStatsController()
{
}

BaseChart* ShoeStatsController::graph()
{
    BaseChart           *chart = new BaseChart();
    QGraphicsRectItem   *r = (QGraphicsRectItem *) chart->graphicsItem();
    qreal               btw;

    QGraphicsTextItem   *title = new QGraphicsTextItem( "Shoe Statistics", chart->graphicsItem());
    title->setFont( QFont( "Helvetica", 10, QFont::Bold));
    btw = title->boundingRect().width();
    title->setPos( ( r->boundingRect().width() -  btw) * 0.5, 0.0);

    qreal               pieDiameter = 200.0;
    for( int i = 0; i < 5; i++)
    {
        QGraphicsEllipseItem    *pieElem = new QGraphicsEllipseItem(  10.0, title->boundingRect().height(), pieDiameter, pieDiameter, chart->graphicsItem());
        pieElem->setStartAngle( i * (5760 / 5));
        pieElem->setSpanAngle( 5760 / 5);
    }

    for( int i = 0; i < 3; i++)
    {
        QGraphicsEllipseItem    *pieElem = new QGraphicsEllipseItem(  410.0, title->boundingRect().height(), pieDiameter, pieDiameter, chart->graphicsItem());
        pieElem->setStartAngle( i * (5760 / 3));
        pieElem->setSpanAngle( 5760 / 3);
    }

    r->setRect( 0.0, 0.0, 800.0, title->boundingRect().height() + pieDiameter + 10.0);

    return chart;
}
