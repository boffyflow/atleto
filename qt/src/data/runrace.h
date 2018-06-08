// $Id: runrace.h 372 2013-03-05 22:04:13Z boffyflow $
// (c) 2006, Parallel Pixels Ltd.

#ifndef RUNRACE_H
#define RUNRACE_H

#include "race.h"

#include <QDate>

enum
{
   RunRace_1500m = 0,
   RunRace_1Mile,
   RunRace_3Miles,
   RunRace_5K,
   RunRace_5Miles,
   RunRace_10K,
   RunRace_15K,
   RunRace_10Miles,
   RunRace_20K,
   RunRace_Half,
   RunRace_25K,
   RunRace_Marathon,
   RunRace_Open,
};

static const int raceDistances[] = 
{ 
   1500,
   1609,
   4828,
   5000,
   8047,
   10000,
   15000,
   16093,
   20000,
   21100,
   25000,
   42195
};

static const QString raceDistanceStrings[] =
{
   "1500m",
   "1 mile",
   "3 miles",
   "5 km",
   "5 miles",
   "10 km",
   "15 km",
   "10 miles",
   "20 km",
   "Half Marathon",
   "25 km",
   "Marathon"
};

class RunRace : virtual public Race
{
public:

    static    QList<RunRace>    raceList( const QDate &firstDay, const QDate &lastDay);
    static    int               raceDistance( const int distance);

    RunRace();
    RunRace( const int race_id);
    ~RunRace();

    int     id() const { return mId;};
    int     chiptime() const { return mChipTime;};
    int     guntime() const { return mGunTime;};
    int     run_id() const { return mRunId;};
    bool    personalBest() const { return mPersonalBest;};

    void    setChiptime( const int chiptime) { mChipTime = chiptime;};
    void    setGuntime( const int guntime) { mGunTime = guntime;};
    void    setRunId( const int run_id) { mRunId = run_id;};
    void    setPersonalBest( const bool personalBest) { mPersonalBest = personalBest;};

    void    restore();
    void    restore( const int race_id);
    void    restoreByRunId( const int run_id);
    int     save( const int race_id = -1);
    void    remove();

private:

    int     mId;
    int     mChipTime;
    int     mGunTime;
    int     mRunId;
    bool    mPersonalBest;

    void    initialize();
};

#endif
