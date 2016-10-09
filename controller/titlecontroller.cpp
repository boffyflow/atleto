// $Id: titlecontroller.cpp 225 2009-06-26 23:41:51Z robert $
// (c) 2009, Parallel Pixels Ltd.

#include <QGraphicsRectItem>
#include <QFont>

#include "titlecontroller.h"

TitleController::TitleController()
{
}

TitleController::~TitleController()
{
}

BaseChart* TitleController::graph()
{
    BaseChart           *chart = new BaseChart();
    QGraphicsRectItem   *r = (QGraphicsRectItem *) chart->graphicsItem();
    qreal               btw;

    r->setRect( 0.0, 0.0, 800.0, 55.0);

    QGraphicsTextItem   *title = new QGraphicsTextItem( "Atleto Report", chart->graphicsItem());
    title->setFont( QFont( "Helvetica", 12, QFont::Bold));
    btw = title->boundingRect().width();
    title->setPos( ( r->boundingRect().width() -  btw) * 0.5, 0.0);

    QGraphicsTextItem   *subtitle = new QGraphicsTextItem( "Period: " + periodString() + " from " + mStartDates.first().toString( "d-MMM-yyyy") + " to " + mEndDates.last().toString( "d-MMM-yyyy"), chart->graphicsItem());
    subtitle->setFont( QFont( "Helvetica", 10));
    btw = subtitle->boundingRect().width();
    subtitle->setPos( ( r->boundingRect().width() -  btw) * 0.5, title->boundingRect().height() - 5.0);

    r->setRect( 0.0, 0.0, 800.0, title->boundingRect().height() + subtitle->boundingRect().height());

    return chart;
}
