// $Id: race.h 294 2010-03-05 18:37:10Z  $
// (c) 2006, Parallel Pixels Ltd.

#ifndef RACE_H
#define RACE_H

#include <QString>

class Race
{
public:

   Race();
   virtual ~Race();

   QString  raceName() const { return mRaceName;};
   QString  bib() const { return mBib;};
   QString  divisionName() const { return mDivisionName;};
   int      place_overall() const { return mPlace_overall;};
   int      num_overall() const { return mNum_overall;};
   int      place_division() const { return mPlace_division;};
   int      num_division() const { return mNum_division;};

   void     setRaceName( const QString &name) { mRaceName = name;};
   void     setBib( const QString& bib) { mBib = bib;};
   void     setDivisionName( const QString& divName) { mDivisionName = divName;};
   void     setPlaceOverall( const int place_overall) { mPlace_overall = place_overall;};
   void     setNumOverall( const int num_overall) { mNum_overall = num_overall;};
   void     setPlaceDivision( const int place_division) { mPlace_division = place_division;};
   void     setNumDivision( const int num_division) { mNum_division = num_division;};

private:

    QString     mRaceName;
    QString	mBib;
    QString	mDivisionName;
    int		mPlace_overall;
    int		mNum_overall;
    int		mPlace_division;
    int		mNum_division;
};

#endif


