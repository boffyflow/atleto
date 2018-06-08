// $Id: run.cpp 369 2010-09-25 00:02:33Z boffyflow $
// (c) 2006, Parallel Pixels Ltd.

#include <QtSql>

#include "src/data/run.h"
#include "src/util/ctime.h"
#include "src/data/data.h"
#include "src/data/split.h"

#define RUN_ID  "Run"

using namespace atleto;

Run::Run()
{
    initialize();
}

Run::Run( const int id)
{
    initialize();
    mId = id;
    restore( mId);
}

void Run::initialize()
{
    setName( RUN_ID);

    mId = -1;
    setJulianDay( QDate::currentDate().toJulianDay());
    setShoe( "unknown");
    setSurface( "unknown");
    setKindOfWorkout( "unknown");
    setLocation( "unknown");
}

Run::~Run()
{
}

void Run::restore()
{
    restore( mId);
}

void Run::restore( const int id)
{
    Data        data;
    QSqlQuery   q( "select location_id,day,surface_id,runtype_id,shoe_id,starttime,endtime,rating,indoors,notes,device_file from runs where id=" + QString::number( id));

    if( q.next())
    {
        setLocation( data.value( "locations", q.value( 0).toInt()));
        setJulianDay( q.value( 1).toInt());
        setSurface( data.value( "surfaces", q.value( 2).toInt()));
        setKindOfWorkout( data.value( "run_types", q.value( 3).toInt()));
        setShoe( data.value( "shoes", q.value( 4).toInt()));
        setStartTime( q.value( 5).toTime());
        setEndTime( q.value( 6).toTime());
        setRating( q.value( 7).toInt());
        setIndoors( q.value( 8).toBool());
        setComment( q.value( 9).toString());
        setDeviceFile( q.value( 10).toString());

        mId = id;

        q.clear();
        q.prepare( "select dist,t,hr,notes from run_splits where run_id=" + QString::number( id));
        q.exec();

        while( q.next())
        {
            Split           *s = new Split;

            s->setDistance( q.value( 0).toDouble());
            s->setTime( q.value( 1).toDouble());
            s->setHeartRate( q.value( 2).toInt());
            s->setComment( q.value( 3).toString());

            addSplit( s);
        }
    }
    else
    {
        mId = -1;
    }
}

int Run::save( const int run_id)
{
    mId = run_id;
    if( mId > 0)
    {
        // delete all splits from db
        Split::removeRunSplits( mId);

        // update existing run
        QSqlQuery       q;
        Data            data;

        q.prepare( "update runs set day=:day,location_id=:location_id,surface_id=:surface_id,runtype_id=:runtype_id,shoe_id=:shoe_id,starttime=:starttime,endtime=:endtime,rating=:rating,indoors=:indoors,notes=:notes,device_file=:device_file where id=" + QString::number( mId));

        q.bindValue( ":day", julianDay());
        q.bindValue( ":location_id", data.create( "locations", location()));
        q.bindValue( ":surface_id", data.create( "surfaces", surface()));
        q.bindValue( ":runtype_id", data.create( "run_types", kindofworkout()));
        q.bindValue( ":shoe_id", data.exists( "shoes", shoeId()));
        q.bindValue( ":starttime", starttime());
        q.bindValue( ":endtime", endtime());
        q.bindValue( ":rating", rating());
        q.bindValue( ":indoors", indoors());
        q.bindValue( ":notes", comment());
        q.bindValue( ":device_file", deviceFile());

        q.exec();
    }
    else
    {
        // insert new run
        QSqlQuery       q;
        Data            data;

        q.prepare( "insert into runs (day,location_id,surface_id,runtype_id,shoe_id,starttime,endtime,rating,indoors,notes,device_file) values(:day,:location_id,:surface_id,:runtype_id,:shoe_id,:starttime,:endtime,:rating,:indoors,:notes,:device_file)");
        q.bindValue( ":day", julianDay());
        q.bindValue( ":location_id", data.create( "locations", location()));
        q.bindValue( ":surface_id", data.create( "surfaces", surface()));
        q.bindValue( ":runtype_id", data.create( "run_types", kindofworkout()));
        q.bindValue( ":shoe_id", data.exists( "shoes", shoeId()));
        q.bindValue( ":starttime", starttime());
        q.bindValue( ":endtime", endtime());
        q.bindValue( ":rating", rating());
        q.bindValue( ":indoors", indoors());
        q.bindValue( ":notes", comment());
        q.bindValue( ":device_file", deviceFile());

        q.exec();
        mId = q.lastInsertId().toInt();
    }

    for( int i = 0; i < numberOfSplits(); i++)
        split( i)->save( mId);

    return mId;
}

void Run::remove()
{
    Split::removeRunSplits( mId);

    QSqlQuery		q( "delete from runs where id=" + QString::number( mId));

    mId = -1;
}

QList<Run>    Run::runList( const QDate &day)
{
    return Run::runList( day, day);
}

QList<Run>    Run::runList( const QDate &firstDay, const QDate &lastDay)
{
   QList<Run>       runList;
   QString          fday = QString::number( firstDay.toJulianDay());
   QString          lday = QString::number( lastDay.toJulianDay());

   QSqlQuery   q( "select id from runs where day>=" + fday + " and day <=" + lday + " order by day");

   while( q.next())
   {
       Run        r( q.value( 0).toInt());
       runList.append( r);
   }

   return runList;
}

float   Run::total( const QDate &firstDay, const QDate &lastDay, const QString &property)
{
    int         jd1 = firstDay.toJulianDay();
    int         jd2 = lastDay.toJulianDay();
    float       value = 0.0;

    QSqlQuery   q( "select sum(" + property + ") from run_splits where run_id in (select id from runs where day>="
                   + QString::number( jd1) + " and day<=" + QString::number( jd2) + ")");

    if( q.next())
        value = q.value( 0).toDouble();

    return value;
}

QList<int>  Run::years()
{
    QList<int>      years;
    QSqlQuery   q( "select day from runs");

    while( q.next())
    {
        int     y = QDate::fromJulianDay( q.value( 0).toInt()).year();

        if( !years.contains( y))
            years.append( y);
    }

    return years;
}

QDate   Run::firstDay()
{
    QSqlQuery   q( "select min(day) from runs");

    if( q.next())
        return QDate::fromJulianDay( q.value( 0).toInt());

    return QDate::currentDate();
}

QDate   Run::lastDay()
{
    QSqlQuery   q( "select max(day) from runs");

    if( q.next())
        return QDate::fromJulianDay( q.value( 0).toInt());

    return QDate::currentDate();
}

int Run::aveHeartRate() const
{
    return Split::aveHeartRate( QDate::fromJulianDay( julianDay()), QDate::fromJulianDay( julianDay()));
}

int Run::maxHeartRate() const
{
    return Split::maxHeartRate( QDate::fromJulianDay( julianDay()), QDate::fromJulianDay( julianDay()));
}
