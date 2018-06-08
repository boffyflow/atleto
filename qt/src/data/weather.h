// (c)2007 Parallel Pixels Ltd. 
// $Id: weather.h 294 2010-03-05 18:37:10Z  $

#ifndef WEATHER_H
#define WEATHER_H

#include <QDate>

class Weather
{
public:

    Weather();
    Weather( const int id);
    ~Weather();

    void        setJulianDay( const int jday) { mJulianDay = jday;};
    void        setSky( const int sky) { mSky = sky;};
    void        setTemperature( const float temperature) { mTemperature = temperature;};
    void        setNotes( const QString &notes) { mNotes = notes;};

    int         id() const { return mId;};
    int         julianDay() const { return mJulianDay;};
    int         sky() const { return mSky;};
    float       temperature() const { return mTemperature;};
    QString     notes() const { return mNotes;};

    void        restore();
    void        restore( const int id);
    void        restoreByJulianDay( const int jd);
    int         save();
    void        remove();

private:

    int         mId;
    int         mJulianDay;
    int         mSky;
    float       mTemperature;
    QString     mNotes;

    void        initialize();
};

#endif  // WEATHER_H
