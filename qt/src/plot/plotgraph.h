// $Id: plotgraph.h 370 2010-12-14 23:23:50Z boffyflow $
// (c) 2010 Parallel Pixels Ltd.

#ifndef PLOTGRAPH_H
#define PLOTGRAPH_H

#include <QObject>
#include "src/plot/plotseries.h"

const int       PLOT_GRAPH_HISTOGRAM = 0;
const int       PLOT_GRAPH_LINE = 1;

class PlotGraph : QObject
{
    Q_OBJECT
public:

    PlotGraph();
    PlotGraph( const PlotSeries &series);

    PlotSeries&     series() { return mSeries;}
    int             graphType() const { return mGraphType;}

    void    setSeries( const PlotSeries &series) { mSeries = series;}
    void    setGraphType( const int gtype) { mGraphType = gtype;}

signals:

public slots:


private:

    PlotSeries      mSeries;
    int             mGraphType;
};

#endif // PLOTGRAPH_H
