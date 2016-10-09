// $Id: temperatureunits.h 294 2010-03-05 18:37:10Z  $
// (c) 2007, Parallel Pixels Ltd. 

#ifndef TEMPERATUREUNITS_H
#define TEMPERATUREUNITS_H

#include <QObject>
#include <QSettings>

#include "src/util/units.h"

enum
{
   CELSIUS = 0,
   FAHRENHEIT,
   LAST_TEMPERATURE
};

static const QString TEMPERATURE_STRINGS[] = { "C", "F"};
static const QString TEMPERATURE_SETTINGS = "temperature_units";
static const double UNDEFINED_TEMPERATURE = -1000.0;

class TemperatureUnits : public Units
{
Q_OBJECT;

public:

   TemperatureUnits();
   ~TemperatureUnits();

   virtual double convert( const double value, const QString& from, const QString& to) const;

   virtual void   restore();
   virtual void   save();

protected:

   double   toCelius( const double value, const QString& from) const;
   double   fromCelsius( const double value, const QString& to) const;
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class TemperatureString
{
public:

	TemperatureString();
	~TemperatureString();

	// always base values
	void setValue( const double value);
	double value();

	// always current values
	void setText( const QString& string);
	QString text( int digits = 1, bool append = true);

private:

	double mValue;
};

#endif  // TEMPERATUREUNITS_H


