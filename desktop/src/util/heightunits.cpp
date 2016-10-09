// $Id: heightunits.cpp 370 2010-12-14 23:23:50Z boffyflow $
// (c) 2007, Parallel Pixels Ltd. 

#include "heightunits.h"

#include "cgeneral.h"
#include "ctime.h"

HeightUnits::HeightUnits()
{
   mUnitmap.remove( LENGTH_STRINGS[YARDS]);
   mUnitmap.remove( LENGTH_STRINGS[MILES]);
   mUnitmap.remove( LENGTH_STRINGS[KILOMETERS]);

   setCurrent( LENGTH_STRINGS[METERS]);
   setBase( LENGTH_STRINGS[METERS]);

   setUType( "Run");
}

HeightUnits::~HeightUnits()
{
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

HeightString::HeightString()
{
    mValue = UNDEFINED_LENGTH;
}

HeightString::~HeightString()
{
}

void
HeightString::setValue( const double value)
{
    mValue = value;
}

void
HeightString::setText( const QString& string)
{
    HeightUnits		hu;

    QString		input = string;

    QString		hunit = hu.current();
    if( input.toLower().contains( LENGTH_STRINGS[MILLIMETERS]))
    {
        hunit = LENGTH_STRINGS[MILLIMETERS];
    }
    else if( input.toLower().contains( LENGTH_STRINGS[CENTIMETERS]))
    {
        hunit = LENGTH_STRINGS[CENTIMETERS];
    }
    else if( input.toLower().contains( LENGTH_STRINGS[INCHES]))
    {
        hunit = LENGTH_STRINGS[INCHES];
    }
    else if( input.toLower().contains( LENGTH_STRINGS[FEET]))
    {
        hunit = LENGTH_STRINGS[FEET];
    }
    else if( input.toLower().contains( LENGTH_STRINGS[METERS]))
    {
        hunit = LENGTH_STRINGS[METERS];
    }

    input.remove( QRegExp( "[a-zA-Z]"));	// remove all characters

    setValue( hu.convert( input.toDouble(), hunit, hu.base()));
}

QString
HeightString::text( int digits, bool append) const
{
    HeightUnits		hu;

    double		value = hu.convert( mValue, hu.base(), hu.current());

    QString		result = QString::number( cGeneral::rnd( value, digits));

    if( append)
    {
        result.append( " ");
        result.append( hu.current());
    }

    return result;
}

