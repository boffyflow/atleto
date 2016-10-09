// $Id: plot.cpp 351 2010-03-27 22:42:25Z boffyflow $
// (c) 2010, Parallel Pixels Ltd.

#include <QtSql>

#include "src/data/plot.h"

Plot::Plot()
{
    initialize();
}

Plot::Plot( const int id)
{
    initialize();
    mId = id;
    restore( mId);
}

void Plot::initialize()
{
    mId = -1;
    mName = qApp->tr( "Distance - Weekly");
    mType = PLOT_GRAPH;
    mY1 = PLOT_TYPE_DISTANCE;
    mY2 = PLOT_TYPE_NONE;
    mAggregation = PLOT_AG_WEEKLY;
}

Plot::~Plot()
{
}

QMap<int,QString> Plot::yMap()
{
    QMap<int,QString>     map;

    // do not change the numer <-> string association!

    map[PLOT_TYPE_NONE] = qApp->translate("Plot", "none");
    map[PLOT_TYPE_DISTANCE] = qApp->translate("Plot", "distance");
    map[PLOT_TYPE_TIME] = qApp->translate("Plot", "time");
    map[PLOT_TYPE_PACE] = qApp->translate("Plot", "pace");
    map[PLOT_TYPE_WEIGHT] = qApp->translate("Plot", "weight");
    map[PLOT_TYPE_BMI] = qApp->translate("Plot", "bmi");
    map[PLOT_TYPE_SHOES] = qApp->translate("Plot", "shoes");

    return map;
}

void Plot::restore()
{
    restore( mId);
}

void Plot::restore( const int id)
{
    QSqlQuery       q( "select name,type,y1data,y2data,aggregation from plots where id=" + QString::number( id));

    if( q.next())
    {
        setName( q.value( 0).toString());
        setPlotType( q.value( 1).toInt());
        setY1Data( q.value( 2).toInt());
        setY2Data( q.value( 3).toInt());
        setAggregation( q.value( 4).toInt());

        mId = id;
    }
    else
    {
        mId = -1;
    }
}

int Plot::save()
{
    if( mId > 0)        // plot exists, needs to be updated
    {
        QSqlQuery   q;

        q.prepare( "update plots set name=:name,type=:type,y1data=:y1data,y2data=:y2data,aggregation=:aggregation where id=" + QString::number( mId));

        q.bindValue( ":name", name());
        q.bindValue( ":type", plotType());
        q.bindValue( ":y1data", y1Data());
        q.bindValue( ":y2data", y2Data());
        q.bindValue( ":aggregation", aggregation());

        q.exec();
    }
    else
    {
        QSqlQuery   q;

        q.prepare( "insert into plots (name,type,y1data,y2data,aggregation) values(:name,:type,:y1data,:y2data,:aggregation)");

        q.bindValue( ":name", name());
        q.bindValue( ":type", plotType());
        q.bindValue( ":y1data", y1Data());
        q.bindValue( ":y2data", y2Data());
        q.bindValue( ":aggregation", aggregation());

        q.exec();
        mId = q.lastInsertId().toInt();
    }
    return mId;
}

void Plot::remove()
{
    QSqlQuery		q( "delete from plots where id=" + QString::number( mId));

    mId = -1;
}

QList<Plot> Plot::plotList()
{
    QList<Plot>     list;

    QSqlQuery       q( "select id from plots");

    while( q.next())
    {
        Plot        p( q.value( 0).toInt());
        list.append( p);
    }

    return list;
}
