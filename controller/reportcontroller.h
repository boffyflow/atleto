// $Id: reportcontroller.h 214 2009-05-28 17:44:45Z robert $
// (c) 2009, Parallel Pixels Ltd.

#ifndef REPORTCONTROLLER_H
#define REPORTCONTROLLER_H

#include <QList>
#include <QDate>
#include <QString>
#include <QGraphicsItem>

#include "src/gui/basechart.h"

class ReportController
{

public:

    ReportController();
    virtual ~ReportController();

    void            setDates( const int ptype, const QDate& fromDate, const QDate& toDate);

    virtual BaseChart    *graph() = 0;

    QString         periodString() const;

protected:

    int             mType;
    QList<QDate>    mStartDates;
    QList<QDate>    mEndDates;
    QList<QString>  mLabels;

};

#endif // REPORTCONTROLLER_H
