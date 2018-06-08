// (c) 2009 Parallel Pixels Ltd.
// $Id: queryparameters.h 372 2013-03-05 22:04:13Z boffyflow $

#ifndef QUERYPARAMETERS_H
#define QUERYPARAMETERS_H

#include <QDate>
#include <QString>
#include <QMap>

class QDomElement;

class QueryParameters
{
public:

    QueryParameters();

    void        initialize();
    void        restoreFromXML( const QString &xmlString);
    void        restoreFromQDomElement( const QDomElement &docElement);

    int         range() const { return mRange;}
    int         lastN() const { return mLastN;}
    int         lastUnits() const { return mLastUnits;}
    QDate       customFrom() const { return mCustomFrom;}
    QDate       customTo() const { return mCustomTo;}

    void        setRange( const int range) { mRange = range;}
    void        setLastN( const int lastN) { mLastN = lastN;}
    void        setLastUnits( const int lastUnits) { mLastUnits = lastUnits;}
    void        setCustomFrom( const QDate customFrom) { mCustomFrom = customFrom;}
    void        setCustomTo( const QDate customTo) { mCustomTo = customTo;}

    void                addFilter( const int index, const QString &value);
    void                removeAllFilters() { mFilters->clear();}
    QMap<int,QString>*  filters() { return mFilters;}

    QString     toXML() const;
    QDate       startDate() const;
    QDate       endDate() const;

private:
    int                 mRange;
    int                 mLastN;
    int                 mLastUnits;
    QDate               mCustomFrom;
    QDate               mCustomTo;
    QMap<int,QString>   *mFilters;
};

#endif // QUERYPARAMETERS_H
