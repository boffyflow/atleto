// $Id: cgeneral.cpp 370 2010-12-14 23:23:50Z boffyflow $
// (c) 2007, Parallel Pixels Ltd.

#include "src/util/cgeneral.h"

#include <cmath>
#include <QRegExp>

int cGeneral::rnd( const double val)
{
   if ( val < 0.0)
      return (int ) ( val - 0.5);
   else
      return (int ) ( val + 0.5);
}

double cGeneral::rnd( const double val, const int digits)
{
	double      div = pow( 10.0, digits);
   int         result = cGeneral::rnd( div * val);

   return (( double) result / div);
}

int cGeneral::numDigits( const int value)
{
    int     n = value;
    int     length = 0;

    while( n)
    {
        length++;
        n /= 10;
    }

    return length;
}

QString
cGeneral::entitize( const QString &s, bool attribute)
{
   QString s2 = s;
 
   s2 = s2.replace( QRegExp( "&" ), "&amp;" );
   s2 = s2.replace( QRegExp( ">" ), "&gt;" );
   s2 = s2.replace( QRegExp( "<" ), "&lt;" );
   if( attribute)
   {
        s2 = s2.replace( QRegExp( "\"" ), "&quot;" );
        s2 = s2.replace( QRegExp( "'" ), "&apos;" );
   }
   return s2;
}

double
cGeneral::bmi( const double weight, const double height)
{
    // weight gets converted from g -> kg
    return( ( weight * 0.001) / ( height * height));
}

// equation is based on Tom Fangrows algorithm (http://www.tomfangrow.com/jsvdot.html)

double cGeneral::vdot( const double dist, const double t)
{
    double      tt = t / 60.0;      // convert seconds to minutes

    double      c = -4.6 + 0.182258 * dist / tt + 0.000104 * dist * dist / tt / tt;                  //c(t) or Oxygen Cost
    double      i = 0.8 + 0.1894393 * exp( -0.012778 * tt) + 0.2989558 * exp( -0.1932605 * tt);     //i(t) or % VO2 Max

    return c / i;
}

// equation is based on Tom Fangrows algorithm (http://www.tomfangrow.com/jsvdot.html)

double cGeneral::vdotTime( const double vdot, const double distance)
{
    double  t = distance * 0.004;           //start with a reasonable guess (t is in minutes!)
    int     n = 0;
    double  e;

    do							//start of iteration loop
    {
        double  c = -4.6 + 0.182258 * distance / t + 0.000104 * distance * distance / t / t;		//c(t) or Oxygen Cost
        double  i = 0.8 + 0.1894393 * exp( -0.012778*t)+		//i(t) or Intensity
                    0.2989558 * exp( -0.1932605 * t);
        e = fabs( c - i * vdot);				//distance between curves
        double  dc = -0.182258 * distance / t / t - 2.0 *.000104 * distance * distance / t / t / t;     //dc(t)/dt or slope of c(t) curve
        double  di = -0.012778 * 0.1894393 * exp( -0.012778*t) -	//di(t)/dt or slope of i(t) curve
                      0.1932605 * 0.2989558 * exp( -0.1932605 * t);
        double  dt = ( c - i * vdot) / ( dc - di * vdot);				//predicted correction
        t -= dt;						//new t value to try
        n++;						//times through loop
    }
    while( n < 10 && e > 0.1);

    return t * 60.0;            // convert t to seconds
}
