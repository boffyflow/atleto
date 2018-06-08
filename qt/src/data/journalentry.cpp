// $Id: journalentry.cpp 294 2010-03-05 18:37:10Z  $
// (c) 2006, Parallel Pixels Ltd.

#include <QtSql>

#include "src/data/journalentry.h"

JournalEntry::JournalEntry()
{
    initialize();
}

JournalEntry::JournalEntry( const int id)
{
    initialize();
    mId = id;
    restore( mId);
}

void JournalEntry::initialize()
{
    mId = -1;
    setJulianDay( QDate::currentDate().toJulianDay());
    setEntry( "");
}

JournalEntry::~JournalEntry()
{
}

void JournalEntry::restore()
{
    restore( mId);
}

void JournalEntry::restore( const int id)
{
    QSqlQuery   q( "select day,entry from journal_entries where id=" + QString::number( id));

    if( q.next())
    {
        setJulianDay( q.value( 0).toInt());
        setEntry( q.value( 1).toString());

        mId = id;
    }
    else
    {
        mId = -1;
    }
}

void JournalEntry::restoreByJulianDay( int jd)
{
    setJulianDay( jd);

    QSqlQuery   q( "select id,entry from journal_entries where day=" + QString::number( jd));

    if( q.next())
    {
        mId = q.value( 0).toInt();
        setEntry( q.value( 1).toString());
    }
    else
    {
        mId = -1;
    }
}

int JournalEntry::save()
{
    if( mId > 0)
    {
        // update existing journal entry

        QSqlQuery       q;

        q.prepare( "update journal_entries set day=:day,entry=:entry,updated_at=:updated_at where id=" + QString::number( mId));

        q.bindValue( ":day", julianDay());
        q.bindValue( ":entry", entry());
        q.bindValue( ":updated_at", QDateTime::currentDateTime());

        q.exec();
    }
    else
    {
        // insert new journal entry

        QSqlQuery       q;

        q.prepare( "insert into journal_entries (day,entry,created_at,updated_at) values(:day,:entry,:created_at,:updated_at)");

        q.bindValue( ":day", julianDay());
        q.bindValue( ":entry", entry());
        q.bindValue( ":created_at", QDateTime::currentDateTime());
        q.bindValue( ":updated_at", QDateTime::currentDateTime());

        q.exec();
        mId = q.lastInsertId().toInt();
    }

    return mId;
}

void JournalEntry::remove()
{
    QSqlQuery		q( "delete from journal_entries where id=" + QString::number( mId));

    mId = -1;
}
