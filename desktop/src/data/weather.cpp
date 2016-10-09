// $Id: weather.cpp 342 2010-03-25 09:13:13Z nebanch $
// (c) 2006, Parallel Pixels Ltd.

#include <QtSql>

#include "src/data/weather.h"

Weather::Weather()
{
    initialize();
}

Weather::Weather( const int id)
{
    initialize();
    mId = id;
    restore( mId);
}

void Weather::initialize()
{
    mId = -1;
    setJulianDay( QDate::currentDate().toJulianDay());
    setSky( -1);
    setTemperature( -1500.0);
    setNotes( "");
}

Weather::~Weather()
{
}

void Weather::restore()
{
    restore( mId);
}

void Weather::restore( const int id)
{
    QSqlQuery   q( "select day,sky,temperature,notes from weathers where id=" + QString::number( id));

    if( q.next())
    {
        setJulianDay( q.value( 0).toInt());
        setSky( q.value( 1).toInt());
        setTemperature( q.value( 2).toDouble());
        setNotes( q.value( 3).toString());

        mId = id;
    }
    else
    {
        mId = -1;
    }
}

void Weather::restoreByJulianDay( int jd)
{
    setJulianDay( jd);

    QSqlQuery   q( "select id,sky,temperature,notes from weathers where day=" + QString::number( jd));

    if( q.next())
    {
        mId = q.value( 0).toInt();
        setSky( q.value( 1).toInt());
        setTemperature( q.value( 2).toDouble());
        setNotes( q.value( 3).toString());
    }
    else
    {
        mId = -1;
    }
}

int Weather::save()
{
    if( mId > 0)
    {
        // update existing Weather

        QSqlQuery       q;

        q.prepare( "update weathers set day=:day,sky=:sky,temperature=:temperature,notes=:notes,updated_at=:updated_at where id=" + QString::number( mId));

        q.bindValue( ":day", julianDay());
        q.bindValue( ":sky", sky());
        q.bindValue( ":temperature", temperature());
        q.bindValue( ":notes", notes());
        q.bindValue( ":updated_at", QDateTime::currentDateTime());

        q.exec();
    }
    else
    {
        // insert new Weather
        QSqlQuery       q;

        q.prepare( "insert into weathers (day,sky,temperature,notes,created_at,updated_at) values(:day,:sky,:temperature,:notes,:created_at,:updated_at)");

        q.bindValue( ":day", julianDay());
        q.bindValue( ":sky", sky());
        q.bindValue( ":temperature", temperature());
        q.bindValue( ":notes", notes());
        q.bindValue( ":created_at", QDateTime::currentDateTime());
        q.bindValue( ":updated_at", QDateTime::currentDateTime());

        q.exec();
        mId = q.lastInsertId().toInt();
    }

    return mId;
}

void Weather::remove()
{
    QSqlQuery		q( "delete from weathers where id=" + QString::number( mId));

    mId = -1;
}

