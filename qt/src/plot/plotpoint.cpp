// $Id: plotpoint.cpp 370 2010-12-14 23:23:50Z boffyflow $
// (c) 2010, Parallel Pixels Ltd.

#include "src/plot/plotpoint.h"

PlotPoint::PlotPoint()
{
}

PlotPoint::PlotPoint( const double x, const double y, const QString &xlabel, const QString &ylabel, const bool flag)
{
    mX = x;
    mY = y;
    mXLabel = xlabel;
    mYLabel = ylabel;
    mFlag = flag;
}
