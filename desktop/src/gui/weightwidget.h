// $Id: weightwidget.h 223 2009-06-12 00:16:18Z robert $
// (c) 2009, Parallel Pixels Ltd.

#ifndef WEIGHTWIDGET_H
#define WEIGHTWIDGET_H

#include "src/gui/graphwidget.h"
#include "src/controller/reportcontroller.h"

class WeightWidget : public GraphWidget
{
public:

    WeightWidget( QWidget *parent = 0);
    virtual ~WeightWidget();

    ReportController    *controller();
    void                addElement( QDomDocument *doc);
};

#endif // WEIGHTWIDGET_H
