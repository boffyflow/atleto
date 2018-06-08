// (c) 2010 Parallel Pixels Ltd.
// $Id: queryfilter.h 370 2010-12-14 23:23:50Z boffyflow $

#ifndef QUERYFILTER_H
#define QUERYFILTER_H

#include <QObject>
#include <QList>

class QBoxLayout;

enum
{
    FILTER_LOCATION = 1,
    FILTER_DISTANCE,
    FILTER_TIME,
    FILTER_RUNTYPE
};


class QueryFilter : public QObject
{
Q_OBJECT

public:

    QueryFilter( const int type);

    int         filterType() const { return mFilterType;}
    QBoxLayout  *layout() { return mLayout;}

    QString     result() const;
    void        setValueString( const QString &valueString);

signals:

    void        filterRemoved( int filterType);

private:

    void                createLocationFilter();
    void                createDistanceFilter();
    void                createRunTypeFilter();

    int                 mFilterType;
    QBoxLayout          *mLayout;
    QList<QWidget *>    mWidgets;

private slots:

    void                removeFilter();
};

#endif // QUERYFILTER_H
