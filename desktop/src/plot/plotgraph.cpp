// $Id: plotgraph.cpp 370 2010-12-14 23:23:50Z boffyflow $
// (c) 2010 Parallel Pixels Ltd.

#include "plotgraph.h"

#include <QPen>
#include <QBrush>

PlotGraph::PlotGraph()
{
    mGraphType = PLOT_GRAPH_HISTOGRAM;
}

PlotGraph::PlotGraph( const PlotSeries &series)
{
    mGraphType = PLOT_GRAPH_HISTOGRAM;
    mSeries = series;
    mSeries.computeMinMax();
}
