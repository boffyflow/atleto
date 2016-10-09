// $Id: titlewidget.h 221 2009-06-05 23:57:04Z robert $
// (c) 2009, Parallel Pixels Ltd.

#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include "src/gui/graphwidget.h"
#include "src/controller/reportcontroller.h"

class TitleWidget : public GraphWidget
{
public:

    TitleWidget( QWidget *parent = 0);
    virtual ~TitleWidget();

    ReportController    *controller();
    void                addElement( QDomDocument *doc);
};

#endif // TITLEWIDGET_H
