// $Id: plotdata.h 369 2010-09-25 00:02:33Z boffyflow $
// (c) 2010, Parallel Pixels Ltd.

#ifndef PLOTDATA_H
#define PLOTDATA_H

#include <QDate>

// #include "src/data/plot.h"

class PlotData
{
public:

    PlotData();
//    PlotData( const Plot &plot);
    ~PlotData();

//    void    setPlot( const Plot &plot) { mPlot = plot;};
    void    setTimeSpan( const QDate &firstDay, const QDate &lastDay);

    QString svgFile() const;

private:

    QString     yValue( const QDate &day1, const QDate &day2, const int valueType) const;

//    Plot        mPlot;
    QDate       mFirstDay;
    QDate       mLastDay;
};

#endif // PLOTDATA_H
