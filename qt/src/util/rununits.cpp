// $Id: rununits.cpp 370 2010-12-14 23:23:50Z boffyflow $
// (c) 2007, Parallel Pixels Ltd. 

#include "rununits.h"

#include "cgeneral.h"
#include "ctime.h"
#include "src/data/settings.h"

RunUnits::RunUnits()
{
   mUnitmap.remove( LENGTH_STRINGS[FEET]);
   mUnitmap.remove( LENGTH_STRINGS[CENTIMETERS]);
   mUnitmap.remove( LENGTH_STRINGS[INCHES]);
   mUnitmap.remove( LENGTH_STRINGS[MILLIMETERS]);

   QString      unitstr = Settings::value( "run_distance_units");

   if( unitstr.isEmpty())
       setCurrent( LENGTH_STRINGS[KILOMETERS]);
   else
       setCurrent( Settings::value( "run_distance_units"));
   setBase( LENGTH_STRINGS[METERS]);

   setUType( "Run");
}

RunUnits::~RunUnits()
{
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

RunDistanceString::RunDistanceString()
{
    mValue = UNDEFINED_LENGTH;
}

RunDistanceString::RunDistanceString( const double value)
{
    mValue = value;
}

RunDistanceString::~RunDistanceString()
{
}

void
RunDistanceString::setValue( const double value)
{
    mValue = value;
}

void
RunDistanceString::setText( const QString& string)
{
    RunUnits		ru;
    QString             input = string;
    QString		Runit = ru.current();

    if( input.toLower().contains( LENGTH_STRINGS[KILOMETERS]))
    {
        Runit = LENGTH_STRINGS[KILOMETERS];
    }
    else if( input.toLower().contains( LENGTH_STRINGS[MILES]))
    {
        Runit = LENGTH_STRINGS[MILES];
    }
    else if( input.toLower().contains( LENGTH_STRINGS[YARDS]))
    {
        Runit = LENGTH_STRINGS[YARDS];
    }
    else if( input.toLower().contains( LENGTH_STRINGS[METERS]))
    {
        Runit = LENGTH_STRINGS[METERS];
    }

    input.remove( QRegExp( "[a-zA-Z]"));	// remove all characters

    setValue( ru.convert( input.toDouble(), Runit, ru.base()));
}

QString
RunDistanceString::text( int digits, bool append) const
{
	RunUnits		ru;
	QSettings		settings;

	double		value = ru.convert( mValue, ru.base(), ru.current());

	QString		result = QString::number( cGeneral::rnd( value, digits));

	if( append)
	{
		result.append( " ");
		result.append( ru.current());
	}

	return result;
}

QString
RunDistanceString::pace( const double secs, bool append) const
{
    RunUnits                ru;
	
    return cTime::pacestr( mValue, secs, ru, append);
}

QString
RunDistanceString::speed( const double secs, bool append) const
{
    RunUnits                ru;

    return cTime::speedstr( mValue, secs, ru, append);
}

double RunDistanceString::curValue() const
{
    RunUnits    ru;

    return ru.convert( mValue, ru.base(), ru.current());
}

double RunDistanceString::paceValue( const double secs) const
{
    return secs / curValue();
}
