// $Id: basechart.cpp 225 2009-06-26 23:41:51Z robert $
// (c) 2009, Parallel Pixels Ltd.

#include <QBrush>
#include <QPen>

#include "src/gui/basechart.h"

BaseChart::BaseChart()
{
    mRectItem = new QGraphicsRectItem( 0.0, 0.0, 800.0, 300.0);
    mRectItem->setPen( QPen( QColor( 0, 0, 255, 255)));
    mRectItem->setBrush( QBrush( QColor( 255, 0, 0, 5)));
}

BaseChart::~BaseChart()
{
    delete mRectItem;
}

void BaseChart::addValue( const QString &label, const double value)
{
    mData[label] = value;
}
