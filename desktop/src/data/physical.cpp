// $Id: physical.cpp 369 2010-09-25 00:02:33Z boffyflow $
// (c) 2006, Parallel Pixels Ltd.

#include <QtSql>

#include "src/data/physical.h"
#include "src/util/cgeneral.h"

Physical::Physical()
{
    initialize();
}

Physical::Physical( const int id)
{
    initialize();
    mId = id;
    restore( mId);
}

void Physical::initialize()
{
    mId = -1;
    setJulianDay( QDate::currentDate().toJulianDay());
    setRestingHR( -1);
    setWeight( -1.0);
    setBodyFat( -1.0);
    setRating( 0);
}

Physical::~Physical()
{
}

void Physical::restore()
{
    restore( mId);
}

void Physical::restore( const int id)
{
    QSqlQuery   q( "select day,hr,weight,bodyfat,rating from physicals where id=" + QString::number( id));

    if( q.next())
    {
        setJulianDay( q.value( 0).toInt());
        setRestingHR( q.value( 1).toInt());
        setWeight( q.value( 2).toDouble());
        setBodyFat( q.value( 3).toInt() * 0.1);
        setRating( q.value( 4).toInt());

        mId = id;
    }
    else
    {
        mId = -1;
    }
}

void Physical::restoreByJulianDay( int jd)
{
    setJulianDay( jd);

    QSqlQuery   q( "select id,hr,weight,bodyfat,rating from physicals where day=" + QString::number( jd));

    if( q.next())
    {
        mId = q.value( 0).toInt();
        setRestingHR( q.value( 1).toInt());
        setWeight( q.value( 2).toDouble());
        setBodyFat( q.value( 3).toInt() * 0.1);
        setRating( q.value( 4).toInt());
    }
    else
    {
        mId = -1;
    }
}

int Physical::save()
{
    if( mId > 0)
    {
        // update existing Physical

        QSqlQuery       q;

        q.prepare( "update physicals set day=:day,hr=:hr,weight=:weight,bodyfat=:bodyfat,rating=:rating,updated_at=:updated_at where id=" + QString::number( mId));

        q.bindValue( ":day", julianDay());
        q.bindValue( ":hr", restingHR());
        q.bindValue( ":weight", weight());
        q.bindValue( ":bodyfat", cGeneral::rnd( bodyFat() * 10));
        q.bindValue( ":rating", rating());
        q.bindValue( ":updated_at", QDateTime::currentDateTime());

        q.exec();
    }
    else
    {
        // insert new Physical
        QSqlQuery       q;

        q.prepare( "insert into physicals (day,hr,weight,bodyfat,rating,created_at,updated_at) values(:day,:hr,:weight,:bodyfat,:rating,:created_at,:updated_at)");

        q.bindValue( ":day", julianDay());
        q.bindValue( ":hr", restingHR());
        q.bindValue( ":weight", weight());
        q.bindValue( ":bodyfat", cGeneral::rnd( bodyFat() * 10));
        q.bindValue( ":rating", rating());        
        q.bindValue( ":created_at", QDateTime::currentDateTime());
        q.bindValue( ":updated_at", QDateTime::currentDateTime());

        q.exec();
        mId = q.lastInsertId().toInt();
    }

    return mId;
}

void Physical::remove()
{
    QSqlQuery		q( "delete from physicals where id=" + QString::number( mId));

    mId = -1;
}

float Physical::average( const QDate& startDate, const QDate &endDate, const QString &property)
{
    QSqlQuery   q( "select " + property + " from physicals where day>=" + QString::number( startDate.toJulianDay()) + " and day<=" + QString::number( endDate.toJulianDay()));

    float       w = 0.0;
    int         cnt = 0;

    while( q.next())
    {
        double      v = q.value( 0).toDouble();
        w += v;
        if( v > 0.001)
            cnt++;
    }

    if( cnt > 0)
        w = w / cnt;

    return w;
}

float Physical::max( const QDate& startDate, const QDate &endDate, const QString &property)
{
    QSqlQuery   q( "select " + property + " from physicals where day>=" + QString::number( startDate.toJulianDay()) + " and day<=" + QString::number( endDate.toJulianDay()));

    float       maxValue = 0.0;

    while( q.next())
    {
        double      v = q.value( 0).toDouble();
        if( v > maxValue)
            maxValue = v;
    }

    return maxValue;
}

float Physical::min( const QDate& startDate, const QDate &endDate, const QString &property)
{
    QSqlQuery   q( "select " + property + " from physicals where day>=" + QString::number( startDate.toJulianDay()) + " and day<=" + QString::number( endDate.toJulianDay()));

    float       minValue = 1.0e10;

    while( q.next())
    {
        double      v = q.value( 0).toDouble();
        if( v < minValue && v > 0.001)
            minValue = v;
    }

    return minValue;
}

