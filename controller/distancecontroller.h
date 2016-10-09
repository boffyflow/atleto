// $Id: distancecontroller.h 214 2009-05-28 17:44:45Z robert $
// (c) 2009, Parallel Pixels Ltd.

#ifndef DISTANCECONTROLLER_H
#define DISTANCECONTROLLER_H

#include "src/controller/reportcontroller.h"
#include "src/gui/basechart.h"

class DistanceController : public ReportController
{
public:

    DistanceController();
    virtual ~DistanceController();

    virtual BaseChart     *graph();
};

#endif // DISTANCECONTROLLER_H
