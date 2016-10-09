// $Id: reportcontroller.cpp 220 2009-06-04 23:42:36Z robert $
// (c) 2009, Parallel Pixels Ltd.

#include "reportcontroller.h"
#include "src/gui/periodwidget.h"

ReportController::ReportController()
{
}

ReportController::~ReportController()
{
}

void ReportController::setDates( const int ptype, const QDate& fromDate, const QDate& toDate)
{
    mType = ptype;

    if( mType == REPORT_TYPE_DAILY)
    {
        for( int i = 0; i <= fromDate.daysTo( toDate); i++)
        {
            QDate       d = fromDate.addDays( i);
            mStartDates.append( d);
            mEndDates.append( d);
            mLabels.append( d.toString( "d.M"));
        }
    }
    if( mType == REPORT_TYPE_WEEKLY)
    {
        QDate   d1 = fromDate;
        int     daysToEnd = d1.daysTo( toDate);
        QDate   d2;

        while( daysToEnd >= 0)
        {
            if( daysToEnd <= ( 7 - d1.dayOfWeek()))
                d2 = d1.addDays( daysToEnd);
            else
                d2 = d1.addDays( 7 - d1.dayOfWeek());

            mStartDates.append( d1);
            mEndDates.append( d2);
            mLabels.append( QString::number( d1.weekNumber()));

            d1 = d2.addDays( 1);
            daysToEnd = d1.daysTo( toDate);
        }
    }
    if( mType == REPORT_TYPE_MONTHLY)
    {
        QDate   d1 = fromDate;
        int     daysToEnd = d1.daysTo( toDate);
        QDate   d2 = toDate;

        while( daysToEnd >= 0)
        {
            if( d2.month() == d1.month() && d2.year() == d1.year())
                d2.setDate( toDate.year(), toDate.month(), toDate.day());
            else
                d2.setDate( d1.year(), d1.month(), d1.daysInMonth());

            mStartDates.append( d1);
            mEndDates.append( d2);
            mLabels.append( d1.toString( "MMM"));

            d1 = d2.addDays( 1);
            daysToEnd = d1.daysTo( toDate);
        }
    }
    if( mType == REPORT_TYPE_YEARLY)
    {
        QDate   d1 = fromDate;
        int     daysToEnd = d1.daysTo( toDate);
        QDate   d2 = toDate;

        while( daysToEnd >= 0)
        {
            if( d2.year() != d1.year())
                d2.setDate( d1.year(), 12, 31);
            else
                d2.setDate( toDate.year(), toDate.month(), toDate.day());

            mStartDates.append( d1);
            mEndDates.append( d2);
            mLabels.append( d1.toString( "yy"));

            d1 = d2.addDays( 1);
            daysToEnd = d1.daysTo( toDate);
        }
    }
}

QString ReportController::periodString() const
{
    if( mType == REPORT_TYPE_DAILY)
        return QString( "Daily");
    else if( mType == REPORT_TYPE_WEEKLY)
        return QString("Weekly");
    else if( mType == REPORT_TYPE_MONTHLY)
        return QString( "Monthly");
    else if( mType == REPORT_TYPE_YEARLY)
        return QString("Yearly");
    else
        return QString( "");
}
