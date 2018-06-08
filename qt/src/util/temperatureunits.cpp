// $Id: temperatureunits.cpp 294 2010-03-05 18:37:10Z  $
// (c) 2007, Parallel Pixels Ltd. 

#include "src/util/temperatureunits.h"
#include "src/util/cgeneral.h"
#include "src/data/data.h"

using namespace atleto;

TemperatureUnits::TemperatureUnits()
{
   mUnitmap.insert( TEMPERATURE_STRINGS[CELSIUS], 1.0);
   mUnitmap.insert( TEMPERATURE_STRINGS[FAHRENHEIT], 1.0);

   setBase( TEMPERATURE_STRINGS[CELSIUS]);
   setCurrent( TEMPERATURE_STRINGS[CELSIUS]);

   setUType( "Temperature");
}

TemperatureUnits::~TemperatureUnits()
{
}

double
TemperatureUnits::convert( const double value, const QString& from, const QString& to) const
{
   if( from == to)
      return value;

   return fromCelsius( toCelius( value, from), to);
}

double
TemperatureUnits::toCelius( const double value, const QString& from) const
{
   if( from == TEMPERATURE_STRINGS[FAHRENHEIT])
   {
      return ( 5.0 / 9.0) * ( value - 32.0);
   }
   else
   {
      return value;
   }
}

double
TemperatureUnits::fromCelsius( const double value, const QString& to) const
{
   if( to == TEMPERATURE_STRINGS[FAHRENHEIT])
   {
      return ( 9.0 / 5.0) * value + 32.0;
   }
   else
   {
      return value;
   }
}

void
TemperatureUnits::restore()
{
    setCurrent( TEMPERATURE_STRINGS[CELSIUS]);
}

void
TemperatureUnits::save()
{
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

TemperatureString::TemperatureString()
{
	mValue = UNDEFINED_TEMPERATURE;
}

TemperatureString::~TemperatureString()
{
}

void
TemperatureString::setValue( const double value)
{
	mValue = value;
}

void
TemperatureString::setText( const QString& string)
{
	TemperatureUnits		tu;
	QString					input = string;

	QString		tunit = tu.base();	
	if( input.contains( "c") || input.contains( "C"))
	{
		tunit = TEMPERATURE_STRINGS[CELSIUS];
	}

	if( input.contains( "f") || input.contains( "F"))
	{
		tunit = TEMPERATURE_STRINGS[FAHRENHEIT];
	}

	input.remove( "c", Qt::CaseInsensitive);
	input.remove( "f", Qt::CaseInsensitive);

	setValue( tu.convert( input.toDouble(), tunit, tu.base()));
}

double
TemperatureString::value()
{
	return mValue;
}

QString
TemperatureString::text( int digits, bool append)
{
    TemperatureUnits		tu;
    QSettings			settings;
	
    tu.restore();

    double		value = tu.convert( mValue, tu.base(), tu.current());
    QString		result = QString::number( cGeneral::rnd( value, digits));

    if( append)
    {
        result.append( " ");
        result.append( QChar( 176));
        result.append( tu.current());
    }

    if( mValue <= UNDEFINED_TEMPERATURE)
        result = "";

    return result;
}
