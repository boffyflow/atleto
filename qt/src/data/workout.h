// $Id: workout.h 360 2010-05-15 06:14:12Z boffyflow $
// (c) 2006, Parallel Pixels Ltd.

#ifndef WORKOUT_H
#define WORKOUT_H

#include <QList>
#include <QTime>

#include "split.h"

enum
{
   POOR = 1,
   FAIR = 2,
   GOOD = 3,
   VERY_GOOD = 4,
   EXCELLENT = 5
};

class Workout
{
public:

    Workout();
//   Workout( const Workout& workout);
    virtual ~Workout();

//   bool     operator ==( const Workout& workout);
//   void     copy( const Workout& workout);

    void     addSplit( Split* split);
    Split*   split( int index);

    int      numberOfSplits() const;
    void     removeSplit( int index);
    void     removeAllSplits();

    void    setName( const QString& name) { _name = name;};
    void    setLocation( const QString& location) { _location = location;};
    void    setJulianDay( const int jday) { mJulianDay = jday;};
    void     setStartTime( const QTime &start) { mStartTime = start;};
    void     setEndTime( const QTime &end) { mEndTime = end;};
    void     setIndoors( const bool indoors) { _indoors = indoors;};
    void     setRating( const int rating) { _rating = rating;};
    void     setComment( const QString& comment) { _comment = comment;};
    void     setKindOfWorkout( const QString& workout) { _kindofwo = workout;};
    void     setSurface( const QString& surface) { _surface = surface;};
    void    setDeviceFile( const QString& deviceFile) { mDeviceFile = deviceFile;};

    QString  name() const { return _name;};
    QString  comment() const { return _comment;};
    QString  location() const { return _location;};
    int     julianDay() const { return mJulianDay;};
    bool     indoors() const { return _indoors;};
    QTime    endtime() const { return mEndTime;};
    QTime    starttime() const { return mStartTime;};
    int      rating() const { return _rating;};
    QString  kindofworkout() const { return _kindofwo;};
    QString  surface() const { return _surface;};
    float    distance() const;
    float    total_time() const;
    QString  deviceFile() const { return mDeviceFile;};
   
    virtual QString  equipid() const { return "-1";};
   
private:

    QString     _name;
    QString     _location;
    int         mJulianDay;
    QTime	mStartTime;
    QTime	mEndTime;
    QString     _comment;
    int         _rating;
    bool        _indoors;
    QString     _kindofwo;
    QString     _surface;
    QString     _ename;
    QString     mDeviceFile;

protected:

    QList<Split *>   _splits;
};

#endif
