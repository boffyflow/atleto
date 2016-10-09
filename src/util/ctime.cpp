// $Id: ctime.cpp 214 2009-05-28 17:44:45Z robert $
// (c) 2006, Parallel Pixels Ltd.

#include "ctime.h"
#include "cgeneral.h"

QString 
cTime::t2str( const double secs, const bool append)
{
   QString      str = "";
   QString      hs = "", ms = "0:", ss = "00";
   QString      ds = "";

   int         s = cGeneral::rnd( secs);
   int         d = s / 86400, h, m;

   s -= d * 86400;
   h = s / 3600;
   s -= h * 3600;
   m = s / 60;
   s = s % 60;

   if( d)
      ds = QString::number( d) + ":";

   if( h && d && h < 10)
      hs = "0" + QString::number( h) + ":";
   else if( h)
      hs = QString::number( h) + ":";

	if ( m < 10 && h != 0)
      ms = "0" + QString::number( m) + ":";		// pad min with 0
	else if( m)
		ms = QString::number( m) + ":";

	if ( s < 10)
		ss = "0" + QString::number( s);    // pad secs with 0
	else if( s)
		ss = "" + QString::number( s);

   QString     suffix = "";
   if( append)
   {
      if( d == 0)
      {
         if( h == 0)
            suffix = " m:s";
         else
            suffix = " h:m:s";
      }
      else
         suffix = " d:h:m:s";
   }
   
	return ( ds + hs + ms + ss + suffix);
}


QString
cTime::pacestr( const double dist, const double secs, const LengthUnits& units, const bool append)
{
	double		d = units.baseToCurrent( dist);

	QString     suffix = "";

	if( append)
	{
		suffix = " min/" + units.current();
	}

	if( d < 0.001)
		return "0:00" + suffix;

    return cTime::t2str( cGeneral::rnd( secs / d), false) + suffix;
}


QString
cTime::speedstr( const double dist, const double secs, const LengthUnits& units, const bool append)
{
	double      d = 0.0;
	QString     suffix = "";

	if( append)
		suffix = " " + units.current() + "/h";

	d = units.baseToCurrent( dist);

    if( secs < 0.0001)
		d = 0.0;
	else
		d = d * 3600.0 / secs;

   return QString::number( d, 'f', 1) + suffix;

   return "";
}

void
cTime::t2hms( const int time, int& hour, int& min, int& sec)
{
   hour = time / 3600;
   min = ( time - hour * 3600) / 60;
   sec = time - hour * 3600 - min * 60;
}

QString
cTime::time2str( const int time)
{
   QTime    qtime( time / 100, time - time / 100 * 100);
   QString  formatstr = "h:mm";

   return qtime.toString( formatstr);
}

QDate
cTime::id2date( const int id)
{
   int      y = id / 10000;
   int      m = ( id - y * 10000) / 100;
   int      d = id - y * 10000 - m * 100;

   if( QDate::isValid( y, m, d))
   {
      return QDate( y, m, d);
   }
   else
   {
      return QDate();
   }
}

QDate
cTime::id2date( const QString &id)
{
   return id2date( id.toInt());
}

int
cTime::date2id( const QDate &date)
{
   return date.year() * 10000 + date.month() * 100 + date.day();
}

