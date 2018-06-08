// $Id: unitstring.cpp 214 2009-05-28 17:44:45Z robert $
// (c) 2007, Parallel Pixels Ltd.

#include "unitstring.h"

UnitString::UnitString( const QString &str)
{
	QString		val;
	QString		u;

	for( int i = 0; i < str.length(); i++)
	{
		if( str[i].isNumber())
			val += str[i];
		else if( !str[i].isSpace())
			u += str[i];
	}

	mValue = val.toDouble();
	mUnit = u;
}

UnitString::~UnitString()
{
}
