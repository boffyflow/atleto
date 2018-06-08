// $Id: split.cpp 370 2010-12-14 23:23:50Z boffyflow $
// (c) 2006, Parallel Pixels Ltd.

#include <QtSql>

#include "split.h"
#include "src/util/cgeneral.h"

Split::Split()
{
   mDistance = 0.0;
   mTime = 0.0;
   mHeartrate = 0;
   mComment = "";
}

Split::Split( const float dist, const float time, const int hr, const QString& comment)
{
   mDistance = dist;
   mTime = time;
   mHeartrate = hr;
   mComment = comment;
}

Split::~Split()
{
}

Split::Split( const Split &split)
{
    mDistance = split.mDistance;
    mTime = split.mTime;
    mHeartrate = split.mHeartrate;
    mComment = split.mComment;
}

bool
Split::operator ==( const Split& split)
{
   if( mDistance  != split.mDistance ||
       mTime      != split.mTime ||
       mHeartrate != split.mHeartrate ||
       mComment   != split.mComment)
       return false;

   return true;
}

int Split::save( const int run_id)
{
    QSqlQuery		q;

    q.prepare( "insert into run_splits (dist,t,hr,notes,run_id) values (:dist,:t,:hr,:notes,:run_id)");
    q.bindValue( ":dist", distance());
    q.bindValue( ":t", time());
    q.bindValue( ":hr", heartrate());
    q.bindValue( ":notes", comment());
    q.bindValue( ":run_id", run_id);
    q.exec();

    return q.lastInsertId().toInt();
}

void Split::removeRunSplits( const int run_id)
{
    QSqlQuery	q( "delete from run_splits where run_id=" + QString::number( run_id));
}

float Split::sum( const QDate& startDate, const QDate &endDate, const QString &property)
{
    QSqlQuery   q( "select sum("+ property + ") from run_splits where run_id in (select id from runs where day>=" +
                    QString::number( startDate.toJulianDay()) + " and day<=" +
                    QString::number( endDate.toJulianDay()) + ")");

    if( q.next())
        return q.value( 0).toDouble();
    else
        return 0.0;
}

int Split::maxHeartRate(const QDate &startDate, const QDate &endDate)
{
    QSqlQuery   q( "select max(hr) from run_splits where run_id in (select id from runs where day>=" +
                    QString::number( startDate.toJulianDay()) + " and day<=" +
                    QString::number( endDate.toJulianDay()) + ")");

    if( q.next())
        return q.value( 0).toInt();
    else
        return 0;
}

int Split::aveHeartRate(const QDate &startDate, const QDate &endDate)
{
    QSqlQuery   q( "select hr,t from run_splits where run_id in (select id from runs where day>=" +
                    QString::number( startDate.toJulianDay()) + " and day<=" +
                    QString::number( endDate.toJulianDay()) + ")");

    float       aveHR = 0.0;
    float       total_time = 0.0;
    bool        cannot_average = false;

    while( q.next())
    {
        int     hr = q.value( 0).toInt();
        if( hr == 0)
        {
            cannot_average = true;
            break;
        }

        float   t = q.value( 1).toFloat();

        if( hr > 0)
        {
            aveHR += hr * t;
            total_time += t;
        }
    }

    if( cannot_average)
        return 0;

    return cGeneral::rnd( aveHR / total_time);
}
