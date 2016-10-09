// $Id: distancecontroller.cpp 214 2009-05-28 17:44:45Z robert $
// (c) 2009, Parallel Pixels Ltd.

#include "distancecontroller.h"

#include "src/gui/barchart.h"
#include "src/data/split.h"
#include "src/util/rununits.h"

DistanceController::DistanceController()
{
}

DistanceController::~DistanceController()
{
}

BaseChart* DistanceController::graph()
{
    BarChart        *barChart = new BarChart( "Distance [km]");

    for( int i = 0; i < mStartDates.count(); i ++)
    {
        RunDistanceString       rs;
        rs.setValue( Split::sum( mStartDates[i], mEndDates[i], "dist"));

        float       value = QString( rs.text( 1, false)).toFloat();

        QString     prefix = QString( "%1").arg( i, 2, 10, QChar( '0'));
        barChart->addValue( prefix + mLabels[i], value);
    }

    barChart->draw();

    return barChart;
}
