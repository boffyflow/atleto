// $Id: weightcontroller.cpp 286 2010-02-19 09:24:49Z  $
// (c) 2009, Parallel Pixels Ltd.

#include "weightcontroller.h"
#include "src/gui/barchart.h"
#include "src/data/physical.h"
#include "src/util/weightunits.h"

WeightController::WeightController()
{
}

WeightController::~WeightController()
{
}

BaseChart* WeightController::graph()
{
    BarChart        *barChart = new BarChart( "Weight [kg]");

    barChart->setBarColor( QColor( 255, 0, 0));
    barChart->setZeroBased( false);

    for( int i = 0; i < mStartDates.count(); i ++)
    {
        WeightString       rs;
        rs.setValue( Physical::average( mStartDates[i], mEndDates[i], "weight"));

        float       value = QString( rs.text( 1, false)).toFloat();

        QString     prefix = QString( "%1").arg( i, 2, 10, QChar( '0'));
        barChart->addValue( prefix + mLabels[i], value);
    }

    barChart->draw();

    return barChart;
}
