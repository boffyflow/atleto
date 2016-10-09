// $Id: day.cpp 240 2009-09-11 23:45:30Z robert $
// (c) 2006-2009, Parallel Pixels Ltd.

#include <QtSql>

#include "day.h"
#include "src/data/data.h"

using namespace atleto;

Day::Day()
{
    initialize();
}

Day::Day( const int id)
{
    initialize();
    mId = id;
    restore( mId);
}

void Day::initialize()
{
    mId = -1;
    setNotes( "");
}

Day::~Day()
{
}

QString Day::dateString( const QString &format) const
{
    return mDate.toString( format);
}

void Day::restore()
{
    restore( mId);
}

void Day::restore( const int id)
{
    QSqlQuery   q( "select athlete_id,notes,calday from days where id=" + QString::number( id));

    if( q.next())
    {
        setAthleteId( q.value( 0).toInt());
        setNotes( q.value( 1).toString());
        setDate( q.value( 2).toDate());

        mId = id;
    }
    else
    {
        mId = -1;
    }
}

int Day::save( const int day_id)
{
    // delete Day if it already exists
    if( mId > 0)
        remove();

    // write the Day
    QSqlQuery       q;

    q.prepare( "insert into days (athlete_id,notes,calday) values(:athlete_id,:notes_id,:calday_id)");
    q.bindValue( ":athlete_id", athleteId());
    q.bindValue( ":notes_id", notes());
    q.bindValue( ":calday_id", date());
    q.exec();

    mId = q.lastInsertId().toInt();

    return mId;
}

void Day::remove()
{
    QSqlQuery		q( "delete from days where id=" + QString::number( mId));

    mId = -1;
}
