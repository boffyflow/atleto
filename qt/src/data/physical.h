// $Id: physical.h 369 2010-09-25 00:02:33Z boffyflow $
// (c) 2006, Parallel Pixels Ltd.

#ifndef PHYSICAL_H
#define PHYSICAL_H

#include <QString>
#include <QDate>

const   QString     PHYSICAL_RATING_POOR = "Poor";
const   QString     PHYSICAL_RATING_FAIR = "Fair";
const   QString     PHYSICAL_RATING_GOOD = "Good";
const   QString     PHYSICAL_RATING_VERY_GOOD = "Very good";
const   QString     PHYSICAL_RATING_EXCELLENT = "Excellent";

class Physical
{
public:

    static float average( const QDate &startDate, const QDate &endDate, const QString& property);
    static float max( const QDate &startDate, const QDate &endDate, const QString& property);
    static float min( const QDate &startDate, const QDate &endDate, const QString& property);


    Physical();
    Physical( const int id);
    ~Physical();

    void        setJulianDay( const int jday) { mJulianDay = jday;};
    void        setRestingHR( const int hr) { mRestingHR = hr;};
    void        setWeight( const float weight) { mWeight = weight;};
    void        setBodyFat( const float bodyfat) { mBodyFat = bodyfat;};
    void        setRating( const int rating) { mRating = rating;};

    int         id() const { return mId;};
    int         julianDay() const { return mJulianDay;};
    int         restingHR() const { return mRestingHR;};
    float       weight() const { return mWeight;};
    float       bodyFat() const { return mBodyFat;};
    int         rating() const { return mRating;};

    void        restore();
    void        restore( const int id);
    void        restoreByJulianDay( const int jd);
    int         save();
    void        remove();

private:

    int         mId;
    int         mJulianDay;
    int         mRestingHR;
    float       mWeight;
    float       mBodyFat;
    int         mRating;

    void        initialize();
};

#endif // PHYSICAL_H
