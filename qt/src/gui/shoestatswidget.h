// $Id: shoestatswidget.h 240 2009-09-11 23:45:30Z robert $
// (c) 2009, Parallel Pixels Ltd.

#ifndef SHOESTATSWIDGET_H
#define SHOESTATSWIDGET_H

#include "src/gui/graphwidget.h"
#include "src/controller/reportcontroller.h"

class ShoeStatsWidget : public GraphWidget
{
public:

    ShoeStatsWidget( QWidget *parent = 0);
    virtual ~ShoeStatsWidget();

    ReportController    *controller();
    void                addElement( QDomDocument *doc);
};

#endif // SHOESTATSWIDGET_H
