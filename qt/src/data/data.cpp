// $Id: data.cpp 372 2013-03-05 22:04:13Z boffyflow $
// (c) 2006, Parallel Pixels Ltd.

#include <QtSql>

#include "data.h"
//#include "cTime.h"
//#include "cGeneral.h"

using namespace atleto;

int Data::athleteID = 0;

Data::Data()
{
}

Data::~Data()
{
}

void
Data::athleteList( QStringList &athleteList, QStringList &idList)
{
    QSqlQuery		q( "select id,name from athletes order by name");

    while( q.next())
    {
        QString     id = q.value( 0).toString();
        idList.append( id);
        QString     athlete = q.value( 1).toString();
        athleteList.append( athlete);
    }
}

void Data::athlete( QString &name, QDate &dob, double &height, bool &male)
{
    QSqlQuery	    q( "select name,dob,height,male from athletes where id=" + QString::number( athleteID));

    if( q.next())
    {
        name = q.value( 0).toString();
        dob = q.value( 1).toDate();
        height = q.value( 2).toDouble();
        male = q.value( 3).toBool();
    }
    else
    {
        name = "unknown";
        dob.setDate( 1980, 1, 1);
        height = 175;
        male = true;
    }
}


int
Data::num( const QString &type)
{
    QSqlQuery		q( "select count(id) from '" + type + "'");

    if ( q.next())
        return q.value( 0).toInt();
    else
        return 0;
}

int
Data::dayExists( const QDate& day)
{
    int     id = -1;
    QSqlQuery		q( "select id from days where calday='" + day.toString( Qt::ISODate) + "' and athlete_id=" + QString::number( athleteID));

    if ( q.next())
        id = q.value( 0).toInt();

    return id;
}

bool
Data::dayData( const int day_id, QString &notes)
{
    QSqlQuery			q( "select notes from days where id=" + QString::number( day_id));

    if( q.first())
    {
        notes = q.value( 0).toString();

        return true;
    }
    else
    {
        notes = "";

//        qDebug() << "last error: " << q.lastError();
    }

    return false;
}

bool
Data::weatherData( const int day_id, int &sky, float &temperature, QString &comment)
{
    QSqlQuery			q( "select temperature,sky,notes from weathers where day_id=" + QString::number( day_id));

    if( q.first())
    {
        temperature = q.value( 0).toDouble();
        sky = q.value( 1).toInt();
        comment = q.value( 2).toString();

        return true;
    }
    else
    {
        temperature = 0;
        sky = 0;
        comment = "";

//        qDebug() << "last error: " << q.lastError();
    }

    return false;
}

bool
Data::physicalData( const int day_id, float &weight, int &bodyfat, int &restinghr, int &rating)
{
    QSqlQuery			q( "select weight,bodyfat,hr,rating from physicals where day_id=" + QString::number( day_id));

    if( q.first())
    {
        weight = q.value( 0).toDouble();
        bodyfat = q.value( 1).toInt();
        restinghr = q.value( 2).toInt();
        rating = q.value( 3).toInt();

        return true;
    }
    else
    {
        weight = 0.0;
        bodyfat = 0;
        restinghr = 0;
        rating = 0;

//        qDebug() << "last error: " << q.lastError();
    }

    return false;
}

bool
Data::workoutList( const int day_id, const QString& wtype, QList<int> &ids)
{
    QSqlQuery			q( "select id from " + wtype + " where day_id=" + QString::number( day_id));

    while( q.next())
    {
        ids.append( q.value( 0).toInt());
    }

    if( ids.count() == 0)
        return false;

    return true;
}

bool Data::runData( const int id, QString& location, float& distance, float &t)
{
    QSqlQuery       q( "select name from locations where id in (select location_id from runs where id=" + QString::number( id) + ")");

    while( q.next())
    {
        location = q.value( 0).toString();
    }

    q.clear();
    q.prepare( "select sum(dist),sum(t) from run_splits where run_id=" + QString::number( id));
    q.exec();
    while( q.next())
    {
        distance = q.value( 0).toDouble();
        t = q.value( 1).toDouble();
    }

    return true;
}

bool Data::cycleData( const int id)
{
    return true;
}

int Data::insertNotes( const QDate &day, const QString &notes)
{
    int			id = createDay( day);

    QSqlQuery	q( "update days set notes='" + notes + "' where id=" + QString::number( id));

    return id;
}

int Data::insertWeatherData( const QDate &day, const int sky, const float temperature, const QString &comment)
{
    int         wid = -1;
    int         id = createDay( day);

    QSqlQuery       q( "select id from weathers where day_id=" + QString::number( id));

    if( !q.next())		// Weather entry does not exist - create a new Weather entry
    {
        QSqlQuery	wq( "insert into weathers (day_id,temperature,sky,notes) values(" +
                                                QString::number( id) + "," +
                                                QString::number( temperature) + "," +
                                                QString::number( sky) + ",'" +
                                                comment + "')" );
        wid = wq.lastInsertId().toInt();
    }
    else				// Weather entry exists - do an update
    {
        wid = q.value( 0).toInt();
        QSqlQuery	wq( "update weathers set day_id=" +
                            QString::number( id) + ",temperature=" +
                            QString::number( temperature) + ",sky=" +
                            QString::number( sky) + ",notes='" +
                            comment + "' where id=" +
                            QString::number( wid));
    }

    return wid;
}

int Data::insertPhysicalData( const QDate &day, const int rating, const float weight, const int bodyfat, const int hr)
{
    int         pid = -1;
    int         id = createDay( day);

    QSqlQuery			q( "select id from physicals where day_id=" + QString::number( id));

    if( !q.next())		// Physical data does not exist - create a new physicals entry
    {
        QSqlQuery   pq( "insert into physicals (day_id,hr,weight,bodyfat,rating) values(" +
                                                QString::number( id) + "," +
                                                QString::number( hr) + "," +
                                                QString::number( weight) + "," +
                                                QString::number( bodyfat) + "," +
                                                QString::number( rating) + ")");
        pid = pq.lastInsertId().toInt();
    }
    else				// Physical entry exists - do an update
    {
        pid = q.value( 0).toInt();
        QSqlQuery	pq( "update physicals set day_id=" +
                            QString::number( id) + ",hr=" +
                            QString::number( hr) + ",weight=" +
                            QString::number( weight) + ",bodyfat=" +
                            QString::number( bodyfat) + ",rating=" +
                            QString::number( rating) + " where id=" +
                            QString::number( pid));

    }

    return pid;
}

int Data::createDay( const QDate &day)
{
    int         day_id = dayExists( day);

    if( day_id <= 0)
    {
        QSqlQuery	q( "insert into days (athlete_id,calday) values(" + QString::number( athleteID) + ",'" + day.toString( Qt::ISODate) + "')");
        day_id = q.lastInsertId().toInt();
    }

    return day_id;
}

void Data::list( const QString &list_type, QStringList &stringdata, QList<int> &idList, const QString& condition, const bool value)
{
    QString         statement = "select name,id from " + list_type;
    if( !condition.isEmpty())
    {
        QString         bvalue = value ? "true" : "false";
        statement += " where " + condition + "='" + bvalue + "'";
    }
    statement += " order by name";

    QSqlQuery		q( statement);

    while( q.next())
    {
        stringdata.append( q.value( 0).toString());
        idList.append( q.value( 1).toInt());
    }
}

QString Data::value( const QString& table, const int id) const
{
    QString     result;
    QSqlQuery   q( "select name from " + table + " where id=" + QString::number( id));

    if( q.next())
        result = q.value( 0).toString();
    else
        result = "";

    return result;
}

int Data::exists( const QString &table, const QString &name) const
{
    int         id = -1;
    QSqlQuery	q( "select id from " + table + " where name='" + name + "'");

    if ( q.next())
        id = q.value( 0).toInt();

    return id;
}

int Data::create( const QString &table, const QString &name) const
{
    int     id = exists( table, name);

    if( id < 0)
    {
        QSqlQuery	q( "insert into " + table + "(name) values('" + name + "')");
        id = q.lastInsertId().toInt();
    }

    return id;
}

QDate Data::firstDay( const QStringList &tables) const
{
    int             minDay = 10000000;

    for( int i = 0; i < tables.size(); i++)
    {
        QSqlQuery   q( "select min(day) from " + tables.at( i));
        if( q.next())
            if( q.value( 0).toInt() < minDay)
                minDay = q.value( 0).toInt();
    }

    return QDate::fromJulianDay( minDay);
}

QDate Data::lastDay( const QStringList &tables) const
{
    int             maxDay = 0;

    for( int i = 0; i < tables.size(); i++)
    {
        QSqlQuery   q( "select max(day) from " + tables.at( i));
        if( q.next())
            if( q.value( 0).toInt() > maxDay)
                maxDay = q.value( 0).toInt();
    }

    return QDate::fromJulianDay( maxDay);
}

void Data::runTypes( QStringList &runTypes)
{
    QSqlQuery       q( "select distinct name from run_types");

    while( q.next())
        runTypes.append( q.value( 0).toString());
}

