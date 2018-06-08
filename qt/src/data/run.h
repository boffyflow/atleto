// (c)2007 Parallel Pixels Ltd. 
// $Id: run.h 370 2010-12-14 23:23:50Z boffyflow $

#ifndef RUN_H
#define RUN_H

#include "workout.h"
#include "runrace.h"

#include <QDate>

class Units;

class Run : public Workout
{
public:

    Run();
    Run( const int id);
    ~Run();

    static      QList<Run>    runList( const QDate &day);
    static      QList<Run>    runList( const QDate &firstDay, const QDate &lastDay);
    static      float         total( const QDate &firstDay, const QDate &lastDay, const QString &property);
    static      QList<int>    years();
    static      QDate         firstDay();
    static      QDate         lastDay();

    int         aveHeartRate() const;
    int         maxHeartRate() const;

    void        setShoe( QString shoe) { mShoe = shoe;}
    void        removeRace();

    QString	shoeId() const { return mShoe;}
    int         id() const { return mId;}

    void        restore();
    void        restore( const int id);
    int         save( const int run_id = -1);
    void        remove();

private:

    int         mId;
    QString	mShoe;  // note that this is only the id of a shoe

    void        initialize();
};

#endif
