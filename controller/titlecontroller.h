// $Id: titlecontroller.h 214 2009-05-28 17:44:45Z robert $
// (c) 2009, Parallel Pixels Ltd.

#ifndef TITLECONTROLLER_H
#define TITLECONTROLLER_H

#include "src/controller/reportcontroller.h"
#include "src/gui/basechart.h"

class TitleController : public ReportController
{
public:
    TitleController();
    virtual ~TitleController();

    virtual BaseChart     *graph();
};

#endif // TITLECONTROLLER_H
