// $Id: barchart.h 223 2009-06-12 00:16:18Z robert $
// (c) 2009, Parallel Pixels Ltd.

#ifndef BARCHART_H
#define BARCHART_H

#include "src/gui/basechart.h"

class BarChart : public BaseChart
{
public:

    BarChart( const QString& title);
    virtual ~BarChart();

    void setBarColor( const QColor &color);
    void setZeroBased( const bool zeroBased);
    virtual void draw();

private:

    void        update();

    qreal       mTitleHeight;
    QColor      mBarColor;
    bool        mZeroBased;
};

#endif // BARCHART_H
