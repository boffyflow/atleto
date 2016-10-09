// (c) 2009 Parallel Pixels Ltd.
// $Id: queryparameters.cpp 372 2013-03-05 22:04:13Z boffyflow $

#include "queryparameters.h"

#include <QDomElement>

QueryParameters::QueryParameters()
{
   initialize();
}

void QueryParameters::initialize()
{
    mRange = 0;
    mLastN = 6;
    mLastUnits = 1;
    mCustomFrom = QDate::currentDate().addMonths( -1);
    mCustomTo = QDate::currentDate();
    mFilters = new QMap<int,QString>;
}

QString QueryParameters::toXML() const
{
    QDomDocument    doc;
    QDomElement     root = doc.createElement("Query");
    doc.appendChild( root);

    QDomElement range = doc.createElement( "Range");
    range.setAttribute( "period", mRange);
    range.setAttribute( "lastn", mLastN);
    range.setAttribute( "lastUnits", mLastUnits);
    range.setAttribute( "customFrom", mCustomFrom.toString( Qt::ISODate));
    range.setAttribute( "customTo", mCustomTo.toString( Qt::ISODate));
    root.appendChild( range);

    for( int i = 0; i < mFilters->keys().count(); i++)
    {
        int     key = mFilters->keys().at( i);
        QString value = mFilters->value( key);

        QDomElement filter = doc.createElement( "Filter");
        filter.setAttribute( "type", QString::number( key));
        filter.setAttribute( "value", value);

        root.appendChild( filter);
    }

    return doc.toString();
}

void QueryParameters::restoreFromXML( const QString &xmlString)
{
    QDomDocument        doc;
    if( doc.setContent( xmlString, false))
    {
        QDomElement     e = doc.firstChildElement( "Query");

        restoreFromQDomElement( e);
    }
}

void QueryParameters::restoreFromQDomElement( const QDomElement &docElement)
{
    QDomNodeList    list = docElement.childNodes();

    for( int i = 0; i < list.count(); i++)
    {
        QDomNode        n = list.at( i);
        if( n.isElement())
        {
            QDomElement     e = n.toElement();

            if( e.tagName() == "Range")
            {
                setRange( e.attribute( "period", "0").toInt());
                setLastN( e.attribute( "lastn", "1").toInt());
                setLastUnits( e.attribute( "lastUnits", "2").toInt());
                setCustomFrom( QDate::fromString( e.attribute( "customFrom", "2000-01-01"), Qt::ISODate));
                setCustomTo( QDate::fromString( e.attribute( "customTo", "2000-12-31"), Qt::ISODate));
            }
            if( e.tagName() == "Filter")
            {
                addFilter( e.attribute( "type").toInt(), e.attribute( "value"));
            }
        }
    }
}

void QueryParameters::addFilter( const int index, const QString &value)
{
    mFilters->insert( index, value);
}

QDate QueryParameters::startDate() const
{
    QDate       d;
    QDate       t = QDate::currentDate();

    if( mRange == 0)                        // all dates
        d.setDate( 1900, 1, 1);
    else if( mRange == 1)                   // this week
        d = t.addDays( 1 - t.dayOfWeek());
    else if( mRange == 2)                   // this month
        d.setDate( t.year(), t.month(), 1);
    else if( mRange == 3)                   // this year
        d.setDate( t.year(), 1, 1);
    else if( mRange == 4)                   // last week
        d = t.addDays( 1 - t.dayOfWeek() - 7);
    else if( mRange == 5)                   // last month
        d.setDate( t.addMonths( -1).year(), t.addMonths( -1).month(), 1);
    else if( mRange == 6)                   // last year
        d.setDate( t.addYears( -1).year(), 1, 1);
    else if( mRange == 7)                   // last x periods y
    {
        if( mLastUnits == 0)        // days
            d = t.addDays( 1 - mLastN);
        else if( mLastUnits == 1)   // weeks
            d = t.addDays( 7 - t.dayOfWeek()).addDays( 1 - mLastN * 7);
        else if( mLastUnits == 2)   // months
            d.setDate( t.addMonths( 1 - mLastN).year(), t.addMonths( 1 - mLastN).month(), 1);
        else if( mLastUnits == 3)   // years
            d.setDate( t.addYears( 1 - mLastN).year(), 1, 1);
    }
    else if( mRange == 8)                   // custom dates
        d = mCustomFrom;
    else if( mRange == 9)                   // custom date through
        d = mCustomFrom;

    return d;
}

QDate QueryParameters::endDate() const
{
    QDate       d;
    QDate       t = QDate::currentDate();

    if( mRange == 0)                        // all dates
        d.setDate( 2200, 1, 1);
    else if( mRange == 1)                   // this week
        d = t.addDays( 1 - t.dayOfWeek()).addDays( 6);
    else if( mRange == 2)                   // this month
        d.setDate( t.year(), t.month(), t.daysInMonth());
    else if( mRange == 3)                   // this year
        d.setDate( t.year(), 12, 31);
    else if( mRange == 4)                   // last week
        d = t.addDays( 1 - t.dayOfWeek() - 7).addDays( 6);
    else if( mRange == 5)                   // last month
        d.setDate( t.addMonths( -1).year(), t.addMonths( -1).month(), t.addMonths( -1).daysInMonth());
    else if( mRange == 6)                   // last year
        d.setDate( t.addYears( -1).year(), 12, 31);
    else if( mRange == 7)                   // last x periods y
    {
        if( mLastUnits == 0)        // days
            d = t;
        else if( mLastUnits == 1)   // weeks
            d = t.addDays( 7 - t.dayOfWeek());
        else if( mLastUnits == 2)   // months
            d.setDate( t.year(), t.month(), t.daysInMonth());
        else if( mLastUnits == 3)   // years
            d.setDate( t.year(), 12, 31);
    }
    else if( mRange == 8)                   // custom dates
        d = mCustomTo;
    else if( mRange == 9)                   // custom date through
        d = t;

    return d;

}
