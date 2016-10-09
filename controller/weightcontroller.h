// $Id: weightcontroller.h 223 2009-06-12 00:16:18Z robert $
// (c) 2009, Parallel Pixels Ltd.

#ifndef WEIGHTCONTROLLER_H
#define WEIGHTCONTROLLER_H

#include "reportcontroller.h"

class WeightController : public ReportController
{
public:
    WeightController();
    virtual ~WeightController();

    virtual BaseChart     *graph();
};

#endif // WEIGHTCONTROLLER_H
