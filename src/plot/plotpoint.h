// $Id: plotpoint.h 370 2010-12-14 23:23:50Z boffyflow $
// (c) 2010, Parallel Pixels Ltd.

#ifndef PLOTPOINT_H
#define PLOTPOINT_H

#include <QString>

class PlotPoint
{
public:

    PlotPoint();
    PlotPoint( const double x, const double y, const QString &xlabel = "", const QString &ylabel = "", const bool flag = true);

    void        setXY( const double x, const double y) { mX = x; mY = y;}
    void        setLabels( const QString &xLabel, const QString &yLabel, const bool flag = true) { mXLabel = xLabel; mYLabel = yLabel; mFlag = flag;}

    double      x() const { return mX;}
    double      y() const { return mY;}
    QString     xLabel() const { return mXLabel;}
    QString     yLabel() const { return mYLabel;}
    bool        flag() const { return mFlag;}

private:

    double      mX;
    double      mY;
    QString     mXLabel;
    QString     mYLabel;
    bool        mFlag;
};

#endif // PLOTPOINT_H
