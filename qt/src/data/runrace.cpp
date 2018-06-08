// $Id: runrace.cpp 372 2013-03-05 22:04:13Z boffyflow $
// (c) 2006, Parallel Pixels Ltd.

#include <QtSql>

#include "runrace.h"
#include "run.h"
#include "src/util/cgeneral.h"


RunRace::RunRace()
{
    initialize();
}

RunRace::RunRace( const int race_id)
{
    initialize();
    mId = race_id;
    restore( mId);
}

RunRace::~RunRace()
{
}

void RunRace::initialize()
{
    mId = -1;
    mRunId = -1;
    mChipTime = 0;
    mGunTime = 0;
    mPersonalBest = false;
}

void RunRace::restore()
{
    restore( mId);
}

void RunRace::restore( const int race_id)
{
    QSqlQuery       q( "select run_id,bib,pl_overall,pl_division,num_overall,num_division,guntime,chiptime,division,name from run_races where id=" +
                        QString::number( race_id));

    if( q.next())
    {
        setRunId( q.value( 0).toInt());
        setBib( q.value( 1).toString());
        setPlaceOverall( q.value( 2).toInt());
        setPlaceDivision( q.value( 3).toInt());
        setNumOverall( q.value( 4).toInt());
        setNumDivision( q.value( 5).toInt());
        setGuntime( cGeneral::rnd( q.value( 6).toDouble()));
        setChiptime( cGeneral::rnd( q.value( 7).toDouble()));
        setDivisionName( q.value( 8).toString());
        setRaceName( q.value( 9).toString());

        mId = race_id;
    }
    else
    {
        mId = -1;
    }
}

void RunRace::restoreByRunId( int run_id)
{
    QSqlQuery       q( "select id from run_races where run_id=" + QString::number( run_id));

    if( q.next())
        restore( q.value( 0).toInt());
    else
        mId = -1;
}

int RunRace::save( const int race_id)
{
    mId = race_id;
    if( mId > 0)
    {
        QSqlQuery       q;

        q.prepare( "update run_races set run_id=:run_id,bib=:bib,pl_overall=:pl_overall,pl_division=:pl_division,num_overall=:num_overall,num_division=:num_division,guntime=:guntime,chiptime=:chiptime,division=:division,name=:name where id=" + QString::number( mId));
        q.bindValue( ":run_id", mRunId);
        q.bindValue( ":bib", bib());
        q.bindValue( ":pl_overall", place_overall());
        q.bindValue( ":pl_division", place_division());
        q.bindValue( ":num_overall", num_overall());
        q.bindValue( ":num_division", num_division());
        q.bindValue( ":guntime", guntime());
        q.bindValue( ":chiptime", chiptime());
        q.bindValue( ":division", divisionName());
        q.bindValue( ":name", raceName());
        q.exec();
    }
    else
    {
        QSqlQuery       q;

        q.prepare( "insert into run_races (run_id,bib,pl_overall,pl_division,num_overall,num_division,guntime,chiptime,division,name) values(:run_id,:bib,:pl_overall,:pl_division,:num_overall,:num_division,:guntime,:chiptime,:division,:name)");
        q.bindValue( ":run_id", mRunId);
        q.bindValue( ":bib", bib());
        q.bindValue( ":pl_overall", place_overall());
        q.bindValue( ":pl_division", place_division());
        q.bindValue( ":num_overall", num_overall());
        q.bindValue( ":num_division", num_division());
        q.bindValue( ":guntime", guntime());
        q.bindValue( ":chiptime", chiptime());
        q.bindValue( ":division", divisionName());
        q.bindValue( ":name", raceName());
        q.exec();

        mId = q.lastInsertId().toInt();
    }

    return mId;
}

void RunRace::remove()
{
    QSqlQuery		q( "delete from run_races where id=" + QString::number( mId));

    mRunId = -1;
}

QList<RunRace>    RunRace::raceList( const QDate &firstDay, const QDate &lastDay)
{
    QMap<int,int>   map;
    QList<RunRace>  raceList;
    QString         fday = QString::number( firstDay.toJulianDay());
    QString         lday = QString::number( lastDay.toJulianDay());

    QSqlQuery   q( "select id from run_races where run_id in (select id from runs where day>=" + fday + " and day <=" + lday + ")");

    while( q.next())
    {
        RunRace         race( q.value( 0).toInt());
        Run             run( race.run_id());
        int             d = raceDistance( run.distance());

        if( map.contains( d))
        {

        }
        else
        {
            race.setPersonalBest( true);
            map.insert( d, race.id());
        }

        raceList.append( race);
    }

    return raceList;
}

int RunRace::raceDistance( const int distance)
{
    for( int i = 0; i < RunRace_Open; i++)
    {
        if( ( distance + 50.0) >= raceDistances[i] && ( distance - 50) <= raceDistances[i])
            return i;
    }

    return -1;
}
