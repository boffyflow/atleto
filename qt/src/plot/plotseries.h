// $Id: plotseries.h 370 2010-12-14 23:23:50Z boffyflow $
// (c) 2010 Parallel Pixels Ltd.

#ifndef PLOTSERIES_H
#define PLOTSERIES_H

#include <QList>
#include <QString>
#include <QColor>
#include "src/plot/plotpoint.h"

const       int     PLOT_SORT_X = 0;
const       int     PLOT_SORT_Y = 1;

const       int     PLOT_SORT_ASCENDING = 0;
const       int     PLOT_SORT_DESCENDING = 1;

const       int     PLOT_UNIT_INDEX = 0;
const       int     PLOT_UNIT_TIME = 1;
const       int     PLOT_UNIT_DISTANCE = 2;
const       int     PLOT_UNIT_PACE = 3;
const       int     PLOT_UNIT_TSS = 4;
const       int     PLOT_UNIT_TSS_PER_DAY = 5;
const       int     PLOT_UNIT_TSB = 6;
const       int     PLOT_UNIT_WEIGHT = 7;
const       int     PLOT_UNIT_BPM = 8;
const       int     PLOT_UNIT_BODYFAT = 9;
const       int     PLOT_UNIT_BMI = 10;

bool    sortByX( PlotPoint &p1, PlotPoint &p2);
bool    sortByY( PlotPoint &p1, PlotPoint &p2);

class PlotSeries
{
public:

    PlotSeries();

    void    setPoints( const QList<PlotPoint> &points) { mPoints = points;}
    void    addPoint( const PlotPoint &p) { mPoints.append( p);}

    QList<PlotPoint>   points() { return mPoints;}

    void    sort( const int key, const int order = PLOT_SORT_DESCENDING);
    void    computeMinMax();
    void    setMinMax( const double minx, const double maxx, const double miny, const double maxy);
    void    setUnitStringX( const QString &unitx) { mUnitStringX = unitx;}
    void    setUnitStringY( const QString &unity) { mUnitStringY = unity;}
    void    setUnits( const int unitX, const int unitY) { mUnitX = unitX; mUnitY = unitY;}
    void    setZeroBased( const bool zeroBased = true) { mZeroBased = zeroBased;}
    void    setColor( const QColor color = QColor( Qt::black)) { mColor = color;}

    double  minX() { return mMinX;}
    double  maxX() { return mMaxX;}
    double  minY() { return mMinY;}
    double  maxY() { return mMaxY;}
    double  unitX() { return mUnitX;}
    double  unitY() { return mUnitY;}
    QString unitStringX() { return mUnitStringX;}
    QString unitStringY() { return mUnitStringY;}
    bool    zeroBased() { return mZeroBased;}
    QColor  color() { return mColor;}

private:

    QList<PlotPoint>        mPoints;
    double                  mMinX;
    double                  mMaxX;
    double                  mMinY;
    double                  mMaxY;
    int                     mUnitX;
    int                     mUnitY;
    QString                 mUnitStringX;
    QString                 mUnitStringY;
    bool                    mZeroBased;
    QColor                  mColor;
};

#endif // PLOTSERIES_H
