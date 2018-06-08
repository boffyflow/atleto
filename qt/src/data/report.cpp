// $Id: report.cpp 223 2009-06-12 00:16:18Z robert $
// (c) 2009, Parallel Pixels Ltd.

#include <QtSql>

#include "report.h"

Report::Report( const QString& name) :
        mName( name)
{
    mCounter = 0;

    mXml = new QDomDocument( "AtletoReport");

    QDomElement root = mXml->createElement( "Report");
    mXml->appendChild(root);
}

Report::~Report()
{
    delete mXml;
}

QString Report::xmlString() const
{
    return mXml->toString( -1);
}

void Report::setXmlString( const QString& string)
{
    mXml->setContent( string);
}

void Report::removeAllReports()
{
    QSqlQuery   q( "delete from reports");
}

void Report::save()
{
    QSqlQuery		q;

    q.prepare( "insert into reports (name,data,count) values (:name,:data,:count)");
    q.bindValue( ":name", name());
    q.bindValue( ":data", xmlString());
    q.bindValue( ":count", count());
    q.exec();
}

QList<Report *> Report::loadAllReports()
{
    QList<Report *>     list;

    QSqlQuery		q( "select name,data,count from reports order by count");

    while( q.next())
    {
        Report      *r = new Report( q.value( 0).toString());
        r->setXmlString( q.value( 1).toString());
        r->setCounter( q.value( 2).toInt());

        list.append( r);
    }

    return list;
}

void Report::setPeriodSettings( const int ptype, const QDate &start, const QDate &end, const int period, const int last, const int lperiod)
{
    QDomElement     reportElem = mXml->firstChildElement( "Report");
    reportElem.setAttribute( "periodtype", ptype);
    reportElem.setAttribute( "date_start", start.toString( Qt::ISODate));
    reportElem.setAttribute( "date_end", end.toString( Qt::ISODate));
    reportElem.setAttribute( "period", period);
    reportElem.setAttribute( "last_num", last);
    reportElem.setAttribute( "last_period", lperiod);
}

int Report::periodType() const
{
    return mXml->firstChildElement( "Report").attribute( "periodtype", "0").toInt();
}

QDate Report::startDate() const
{
    return QDate::fromString( mXml->firstChildElement( "Report").attribute( "date_start", "2000-01-01"), Qt::ISODate);
}

QDate Report::endDate() const
{
    return QDate::fromString( mXml->firstChildElement( "Report").attribute( "date_end", "2000-01-01"), Qt::ISODate);
}

int Report::period() const
{
    return mXml->firstChildElement( "Report").attribute( "period", "0").toInt();
}

int Report::lastNumber() const
{
    return mXml->firstChildElement( "Report").attribute( "last_num", "1").toInt();
}

int Report::lastPeriod() const
{
    return mXml->firstChildElement( "Report").attribute( "last_period", "1").toInt();
}

QStringList Report::reportTypes() const
{
    QStringList     list;

    QDomElement     root = mXml->firstChildElement( "Report");

    QDomNode        n = root.firstChild();
    while( !n.isNull())
    {
        if( n.isElement())
            list.append( n.toElement().tagName());
        n = n.nextSibling();
    }

    return list;
}

void Report::clearDomElements()
{
    QDomElement     root = mXml->firstChildElement( "Report");

    QDomNode        n = root.firstChild();
    while( !n.isNull())
    {
        root.removeChild( n);
        n = root.firstChild();
    }
}

QDomDocument *Report::doc()
{
    return mXml;
}
