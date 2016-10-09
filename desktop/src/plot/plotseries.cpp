// $Id: plotseries.cpp 369 2010-09-25 00:02:33Z boffyflow $
// (c) 2010 Parallel Pixels Ltd.

#include "plotseries.h"
#include <QtAlgorithms>

PlotSeries::PlotSeries()
{
}

bool sortByXAscending( PlotPoint &p1, PlotPoint &p2)
{
    return p1.x() < p2.x();
}

bool sortByXDescending( PlotPoint &p1, PlotPoint &p2)
{
    return p1.x() > p2.x();
}

bool sortByYAscending( PlotPoint &p1, PlotPoint &p2)
{
    return p1.y() < p2.y();
}

bool sortByYDescending( PlotPoint &p1, PlotPoint &p2)
{
    return p1.y() > p2.y();
}


void PlotSeries::sort( const int key, const int order)
{
    if( key == PLOT_SORT_X)
    {
        if( order == PLOT_SORT_ASCENDING)
            qSort( mPoints.begin(), mPoints.end(), sortByXAscending);
        else if ( order == PLOT_SORT_DESCENDING)
            qSort( mPoints.begin(), mPoints.end(), sortByXDescending);
    }
    else if( key == PLOT_SORT_Y)
    {
        if( order == PLOT_SORT_ASCENDING)
            qSort( mPoints.begin(), mPoints.end(), sortByYAscending);
        else if( order == PLOT_SORT_DESCENDING)
            qSort( mPoints.begin(), mPoints.end(), sortByYDescending);
    }
}

void PlotSeries::computeMinMax()
{
    mMinX = mMaxX = mPoints.at( 0).x();
    mMinY = mMaxY = mPoints.at( 0).y();

    for( int i = 1; i < mPoints.size(); i++)
    {
        if( mPoints.at( i).x() < mMinX)
            mMinX = mPoints.at( i).x();
        if( mPoints.at( i).x() > mMaxX)
            mMaxX = mPoints.at( i).x();

        if( mPoints.at( i).y() < mMinY)
            mMinY = mPoints.at( i).y();
        if( mPoints.at( i).y() > mMaxY)
            mMaxY = mPoints.at( i).y();
    }
}

void PlotSeries::setMinMax( const double minx, const double maxx, const double miny, const double maxy)
{
    mMinX = minx;
    mMaxX = maxx;
    mMinY = miny;
    mMaxY = maxy;
}
