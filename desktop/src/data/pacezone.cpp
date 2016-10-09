// (c)2007 Parallel Pixels Ltd.
// $Id: pacezone.cpp 294 2010-03-05 18:37:10Z  $

#include "pacezone.h"

#include <QtSql>

PaceZone::PaceZone()
{
}

QStringList     PaceZone::zones( const int race_type, const float secs)
{
    QString     raceString = "race3K_";
    if( race_type == RACE_TIME_5K)
        raceString = "race5K_";
    else if( race_type == RACE_TIME_10K)
        raceString = "race10K_";

    QString     maxRacePace = raceString + "max";
    QString     minRacePace = raceString + "min";


    QSqlQuery   q1( "select name from pz_names");

    QStringList     pnames;
    while( q1.next())
    {
        pnames.append( q1.value( 0).toString());
    }

    QSqlQuery   q2( "select pzi,pz2_max,pz2_min,pz3_max,pz3_min,pz4_max,pz4_min,pz6_max,pz6_min,pz8_max,pz8_min,pz10_max,pz10_min from pace_zones where "\
                   + minRacePace + "<=" + QString::number( secs) + " and " + maxRacePace + ">=" + QString::number( secs));

    QStringList     list;

    if( q2.next())
    {
        list.append( q2.value( 0).toString());
        list.append( pnames.at(1) + "," + q2.value(2).toString() + "," + q2.value( 1).toString());
        list.append( pnames.at(2) + "," + q2.value(4).toString() + "," + q2.value( 3).toString());
        list.append( pnames.at(3) + "," + q2.value(6).toString() + "," + q2.value( 5).toString());
        list.append( pnames.at(5) + "," + q2.value(8).toString() + "," + q2.value( 7).toString());
        list.append( pnames.at(7) + "," + q2.value(10).toString() + "," + q2.value( 9).toString());
        list.append( pnames.at(9) + "," + q2.value(12).toString() + "," + q2.value( 11).toString());
    }

    return list;
}
