// $Id: weightunits.cpp 294 2010-03-05 18:37:10Z  $
// (c) 2007, Parallel Pixels Ltd. 

#include "weightunits.h"

#include "src/util/cgeneral.h"

WeightUnits::WeightUnits()
{
   setUType( "Weight");

   mUnitmap.insert( WEIGHT_STRINGS[GRAMS], 1.0);
   mUnitmap.insert( WEIGHT_STRINGS[KILOGRAMS], 0.001);
   mUnitmap.insert( WEIGHT_STRINGS[POUNDS], 0.00220462);

   setBase( WEIGHT_STRINGS[GRAMS]);
   setCurrent( WEIGHT_STRINGS[KILOGRAMS]);
}

WeightUnits::~WeightUnits()
{
}
 
double
WeightUnits::convert( const double value, const QString& from, const QString& to) const
{
   if( from == to)
      return value;

   return fromGrams( toGrams( value, from), to);
}

double
WeightUnits::toGrams( const double value, const QString& src) const
{
   if( src == WEIGHT_STRINGS[GRAMS])
      return value;

   double      base_m = (double ) mUnitmap[WEIGHT_STRINGS[GRAMS]];
   double      src_m = (double ) mUnitmap[ src];

   return value * base_m / src_m;
}

double
WeightUnits::fromGrams( const double value, const QString& dest) const
{
   if( dest == WEIGHT_STRINGS[GRAMS])
      return value;

   double      base_m = (double ) mUnitmap[WEIGHT_STRINGS[GRAMS]];
   double      src_m = (double ) mUnitmap[ dest];

   return value * src_m / base_m;
}

void
WeightUnits::save()
{
}

void
WeightUnits::restore()
{
    setCurrent( WEIGHT_STRINGS[KILOGRAMS]);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

WeightString::WeightString()
{
	mValue = UNDEFINED_WEIGHT;
}

WeightString::~WeightString()
{
}

void
WeightString::setValue( const double value)
{
	mValue = value;
}

void
WeightString::setText( const QString& string)
{
	WeightUnits		wu;
	QSettings		settings;

    wu.restore();

	QString				input = string;

	QString		wunit = wu.current();	
	if( input.toLower().contains( WEIGHT_STRINGS[KILOGRAMS]))
	{
		wunit = WEIGHT_STRINGS[KILOGRAMS];
	}
	else if( input.toLower().contains( WEIGHT_STRINGS[GRAMS]))
	{
		wunit = WEIGHT_STRINGS[GRAMS];
	}
	else if( input.toLower().contains( WEIGHT_STRINGS[POUNDS]))
	{
		wunit = WEIGHT_STRINGS[POUNDS];
	}

	input.remove( QRegExp( "[a-zA-Z]"));	// remove all characters

	setValue( wu.convert( input.toDouble(), wunit, wu.base()));
}

double
WeightString::value()
{
	return mValue;
}

QString
WeightString::text( int digits, bool append)
{
	WeightUnits		wu;
	QSettings		settings;

    wu.restore();

	double		value = wu.convert( mValue, wu.base(), wu.current());

	QString		result = QString::number( cGeneral::rnd( value, digits));

	if( append)
	{
		result.append( " ");
		result.append( wu.current());
	}

	return result;
}
