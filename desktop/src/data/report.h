// $Id: report.h 221 2009-06-05 23:57:04Z robert $
// (c) 2009, Parallel Pixels Ltd.

#ifndef REPORT_H
#define REPORT_H

#include <QString>
#include <QDomDocument>
#include <QList>

class Report
{
public:

    static  void                removeAllReports();
    static  QList<Report *>     loadAllReports();

    Report( const QString& name);
    ~Report();

    QString     name() const { return mName;};
    void        setName( const QString& name) { mName = name;};

    int         count() const { return mCounter;};
    void        addCount() { mCounter++;};
    void        setCounter( const int count) { mCounter = count;};
    QString     xmlString() const;
    void        setXmlString( const QString& string);

    QDomDocument    *doc();

    void        setPeriodSettings( const int ptype, const QDate& start, const QDate& end, const int period, const int last = 1, const int lperiod = 0);
    int         periodType() const;
    QDate       startDate() const;
    QDate       endDate() const;
    int         period() const;
    int         lastNumber() const;
    int         lastPeriod() const;

    void        clearDomElements();
//    void        addDomElement( const QString &elem);

    QStringList reportTypes() const;
    void        save();

private:

    int             mCounter;
    QDomDocument    *mXml;
    QString         mName;
};

#endif // REPORT_H
