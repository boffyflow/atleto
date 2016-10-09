// $Id: distancewidget.h 221 2009-06-05 23:57:04Z robert $
// (c) 2009, Parallel Pixels Ltd.

#ifndef DISTANCEWIDGET_H
#define DISTANCEWIDGET_H

#include "src/gui/graphwidget.h"
#include "src/controller/reportcontroller.h"

class DistanceWidget : public GraphWidget
{
public:

    DistanceWidget( QWidget *parent = 0);
    virtual ~DistanceWidget();

    ReportController    *controller();
    void                addElement( QDomDocument *doc);
};

#endif // DISTANCEWIDGET_H
