// $Id: lengthunits.cpp 214 2009-05-28 17:44:45Z robert $
// (c) 2007, Parallel Pixels Ltd. 

#include "lengthunits.h"

LengthUnits::LengthUnits()
{
   mUnitmap.insert( LENGTH_STRINGS[KILOMETERS], 0.001);
   mUnitmap.insert( LENGTH_STRINGS[MILES], 0.000621371192);
   mUnitmap.insert( LENGTH_STRINGS[METERS], 1.0);
   mUnitmap.insert( LENGTH_STRINGS[FEET], 3.280839895);
   mUnitmap.insert( LENGTH_STRINGS[YARDS], 1.093613298);
   mUnitmap.insert( LENGTH_STRINGS[CENTIMETERS], 100.0);
   mUnitmap.insert( LENGTH_STRINGS[INCHES], 39.37007874);
   mUnitmap.insert( LENGTH_STRINGS[MILLIMETERS], 1000.0);

   setBase( LENGTH_STRINGS[METERS]);
   setCurrent( LENGTH_STRINGS[METERS]);

   setUType( "Length");
}

LengthUnits::~LengthUnits()
{
}
   
double
LengthUnits::convert( const double value, const QString& src, const QString& dest) const
{
   if( src == dest)
      return value;

   double      src_m = (double ) mUnitmap[ src];
   double      dest_m = (double ) mUnitmap[ dest];
      
   return value * dest_m / src_m;
}

