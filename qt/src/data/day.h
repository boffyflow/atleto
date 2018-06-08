// (c)2007 Parallel Pixels Ltd. 
// $Id: day.h 240 2009-09-11 23:45:30Z robert $

#ifndef DAY_H
#define DAY_H

#include <QDate>

class Day
{
public:

    Day();
    Day( const int id);
    ~Day();

    void        setAthleteId( const int athlete_id) { mAthleteId = athlete_id;};
    void        setNotes( QString notes) { mNotes = notes;};
    void        setDate( QDate date) { mDate = date;};

    int         id() const { return mId;};
    int         athleteId() const { return mAthleteId;};
    QString		notes() const { return mNotes;};
    QDate       date() const { return mDate;};
    QString     dateString( const QString &format) const;

    void        restore();
    void        restore( const int id);
    int         save( const int day_id);
    void        remove();

private:

    int         mId;
    int         mAthleteId;
    QString		mNotes;
    QDate       mDate;

    void        initialize();
};

#endif
