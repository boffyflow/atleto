// $Id: journalentry.h 294 2010-03-05 18:37:10Z  $
// (c) 2006, Parallel Pixels Ltd.

#ifndef JOURNALENTRY_H
#define JOURNALENTRY_H

#include <QString>
#include <QDate>

class JournalEntry
{
public:

    JournalEntry();
    JournalEntry( const int id);
    ~JournalEntry();

    void        setJulianDay( const int jday) { mJulianDay = jday;};
    void        setEntry( const QString &entry) { mEntry = entry;};

    int         id() const { return mId;};
    int         julianDay() const { return mJulianDay;};
    QString     entry() const { return mEntry;};

    void        restore();
    void        restore( const int id);
    void        restoreByJulianDay( const int jd);
    int         save();
    void        remove();

private:

    int         mId;
    int         mJulianDay;
    QString     mEntry;

    void        initialize();
};

#endif // JOURNALENTRY_H
