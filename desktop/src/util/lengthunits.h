// $Id: lengthunits.h 370 2010-12-14 23:23:50Z boffyflow $
// (c) 2007, Parallel Pixels Ltd. 


#ifndef LENGTHUNITS_H
#define LENGTHUNITS_H

#include <QObject>
#include <QSettings>

#include "units.h"

enum
{
   KILOMETERS = 0,
   MILES,
   METERS,
   FEET,
   YARDS,
   CENTIMETERS,
   INCHES,
   MILLIMETERS,
   LAST_LENGTH
};

static const QString LENGTH_STRINGS[] = { "km", "mi", "m", "feet", "yards", "cm", "inches", "mm"};
static const double UNDEFINED_LENGTH = -1.0;

class LengthUnits : public Units
{
Q_OBJECT;

public:

   LengthUnits();
   ~LengthUnits();

   virtual double convert( const double value, const QString& from, const QString& to) const;
};

#endif // LENGTHUNITS_H




