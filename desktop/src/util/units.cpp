// $Id: units.cpp 214 2009-05-28 17:44:45Z robert $
// (c) 2007, Parallel Pixels Ltd. 

#include "units.h"

Units::Units()
{
}

Units::~Units()
{
}

double
Units::currentToBase( const double value) const
{
   return convert( value, mCurrent, mBase);
}

double
Units::baseToCurrent( const double value) const
{
   return convert( value, mBase, mCurrent);
}
