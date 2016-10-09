// $Id: ctime.h 214 2009-05-28 17:44:45Z robert $
// (c) 2006, Parallel Pixels Ltd.

#ifndef CTIME_H
#define CTIME_H

#include <QString>
#include <QDate>

#include "lengthunits.h"

class cTime
{
public:

   static QString    t2str( const double secs, const bool append = true);
   static QString    pacestr( const double dist, const double secs, const LengthUnits& units, const bool append = true);
   static QString    speedstr( const double dist, const double secs, const LengthUnits& units, const bool append = true);

   static void t2hms( const int time, int& hour, int& min, int& sec);
   static QString time2str( const int time);

   static QDate id2date( const int id);
   static QDate id2date( const QString &id);
   static int   date2id( const QDate &date);
};

#endif


