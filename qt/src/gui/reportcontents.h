// $Id: reportcontents.h 214 2009-05-28 17:44:45Z robert $
// (c) 2009, Parallel Pixels Ltd.

#ifndef REPORTCONTENTS_H
#define REPORTCONTENTS_H

#include <QtGui/QDialog>
#include <QGraphicsScene>

#include "src/gui/basechart.h"
#include "src/controller/reportcontroller.h"

namespace Ui {
    class ReportContents;
}

class ReportContents : public QDialog
{
    Q_OBJECT
    Q_DISABLE_COPY(ReportContents)

public:

    explicit ReportContents(QWidget *parent = 0);
    virtual ~ReportContents();

    void    addController( ReportController *controller);

protected:

    virtual void changeEvent(QEvent *e);

private:

    Ui::ReportContents          *m_ui;
    QGraphicsScene              mScene;
    QList<ReportController *>   mControllers;

    void    addChart( BaseChart *chart);
};

#endif // REPORTCONTENTS_H
