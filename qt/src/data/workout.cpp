// $Id: workout.cpp 214 2009-05-28 17:44:45Z robert $
// (c) 2006, Parallel Pixels Ltd.

#include "workout.h"

Workout::Workout()
{
	_name = "";
	_location = "";
	_comment = "";
	mStartTime.setHMS( 12, 0, 0);
	mEndTime.setHMS( 13, 0, 0);
	_rating = GOOD;
	_indoors = false;
   _surface = "";
   _kindofwo = "";
   _ename = "";
}

Workout::~Workout()
{
   _splits.clear();
}

float Workout::distance() const
{
    float       d = 0.0;
    for( int i = 0; i < numberOfSplits(); i++)
        d += _splits[i]->distance();

    return d;
}

float Workout::total_time() const
{
    float       t = 0.0;
    for( int i = 0; i < numberOfSplits(); i++)
        t += _splits[i]->time();

    return t;
}

/*
Workout::Workout( const Workout& workout)
{
   copy( workout);
}

void
Workout::copy( const Workout& workout)
{
   _name = workout._name;
   _location = workout._location;
   _comment = workout._comment;
   mStartTime = workout.mStartTime;
   mEndTime = workout.mEndTime;
   _rating = workout._rating;
   _indoors = workout._indoors;
   _surface = workout._surface;
   _kindofwo = workout._kindofwo;

   removeAllSplits();

   QList<Split *>    list( workout._splits);

   for( int i = 0; i < list.size(); i++)
   {
      Split    *os = list.at( i);
      Split    *s = new Split( *os);
      addSplit( s);
   }
}

bool
Workout::operator ==( const Workout& workout)
{
   if( _name != workout._name) return false;
   if( _location != workout._location) return false;
   if( _comment != workout._comment) return false;
   if( mStartTime != workout.mStartTime) return false;
   if( mEndTime != workout.mEndTime) return false;
   if( _rating != workout._rating) return false;
   if( _indoors != workout._indoors) return false;
   if( _surface != workout._surface) return false;
   if( _kindofwo != workout._kindofwo) return false;

   if( _splits.count() != workout._splits.count()) return false;

   QList<Split *>      list = workout._splits;

   for( int i = 0; i < (int ) _splits.count(); i++)
   {
      Split    *os = (Split *) _splits.at( i);
      Split    *ns = (Split *) list.at( i);

      if( !( *os == *ns)) return false;
   }

   return true;
}
*/

void
Workout::addSplit( Split* split)
{
   _splits.append( split);
}

Split*
Workout::split( int index)
{
   return (Split *) _splits.at( index);
}

int
Workout::numberOfSplits() const
{
   return _splits.count();
}

void
Workout::removeSplit( int index)
{
	if ( index >= 0 && index < (int) _splits.count())
	{
		_splits.removeAt( index);
	}
}

void
Workout::removeAllSplits()
{
   _splits.clear();
}
