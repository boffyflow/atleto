// $Id: shoestatscontroller.h 245 2009-09-26 00:05:28Z robert $
// (c) 2009, Parallel Pixels Ltd.

#ifndef SHOESTATSCONTROLLER_H
#define SHOESTATSCONTROLLER_H

#include "src/controller/reportcontroller.h"
#include "src/gui/basechart.h"

class ShoeStatsController : public ReportController
{
public:
    ShoeStatsController();
    virtual ~ShoeStatsController();

    virtual BaseChart     *graph();
};

#endif // SHOESTATSCONTROLLER_H
