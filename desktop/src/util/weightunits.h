// $Id: weightunits.h 294 2010-03-05 18:37:10Z  $
// (c) 2007, Parallel Pixels Ltd. 

#ifndef WEIGHTUNITS_H
#define WEIGHTUNITS_H

#include <QObject>
#include <QSettings>

#include "src/util/units.h"

enum
{
   GRAMS = 0,
   KILOGRAMS,
   POUNDS,
   LAST_WEIGHT
};

static const QString WEIGHT_STRINGS[] = { "g", "kg", "lbs"};
static const QString WEIGHT_SETTINGS = "settings.physical.weight.units";
static const double UNDEFINED_WEIGHT = -1.0;

class WeightUnits : public Units
{
	Q_OBJECT;

	public:

	   WeightUnits();
	   ~WeightUnits();

	   virtual double convert( const double value, const QString& from, const QString& to) const;

       virtual void   restore();
       virtual void   save();

	protected:

	   double   toGrams( const double value, const QString& from) const;
	   double   fromGrams( const double value, const QString& to) const;
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class WeightString
{
public:

	WeightString();
	~WeightString();

	// always base values
	void setValue( const double value);
	double value();

	// always current values
	void setText( const QString& string);
	QString text( int digits = 1, bool append = true);

private:

	double mValue;
};


#endif   // WEIGHTUNITS_H
