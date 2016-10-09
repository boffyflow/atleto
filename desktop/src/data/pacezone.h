// (c)2007 Parallel Pixels Ltd.
// $Id: pacezone.h 294 2010-03-05 18:37:10Z  $

#ifndef PACEZONE_H
#define PACEZONE_H

#include <QStringList>

const int        RACE_TIME_3K = 0;
const int        RACE_TIME_5K = 1;
const int        RACE_TIME_10K = 2;

class PaceZone
{
public:

    PaceZone();

    static      QStringList     zones( const int race_type, const float secs);
};

#endif // PACEZONE_H
