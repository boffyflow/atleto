#include "athlete.h"
#include <QtSql>

Athlete* Athlete::instance = NULL;

Athlete::Athlete()
{
    // mName = QString();
    mHeight = 1.85;
}

Athlete* Athlete::getInstance()
{
    if( !instance ) instance = new Athlete();
    return instance;
}

void Athlete::newAthlete()
{
    Athlete* athlete = Athlete::getInstance();
    athlete->setName("new Athlete");
    athlete->setHeight( 1.80);
    athlete->setDoB( QDate(1970, 1, 1));
    athlete->setGender( true );
}

void Athlete::setAthleteById(int id)
{
    QSqlQuery q( "SELECT name,dob,height,male "
                 "FROM athletes "
                 "WHERE id=:id");

    q.bindValue(":id", id );
    q.exec();

    if( q.next())
    {
        Athlete *athlete = Athlete::getInstance();
        athlete->setId( id );
        athlete->setName( q.value( 0).toString() );
        athlete->setDoB( q.value( 1).toDate() );
        athlete->setHeight( q.value( 2).toDouble() );
        athlete->setGender( q.value( 3).toBool() );
    }
    else
    {
        Athlete::newAthlete();
    }
}

void Athlete::setAthleteByName(QString name)
{
    QSqlQuery q( "SELECT id,name,dob,height,male "
                 "FROM athletes "
                 "WHERE name=:name");

    q.bindValue(":name", name);
    q.exec();

    if( q.next())
    {
        Athlete *athlete = Athlete::getInstance();
        athlete->setId( q.value( 0).toInt() );
        athlete->setName( q.value( 1).toString() );
        athlete->setDoB( q.value( 2).toDate() );
        athlete->setHeight( q.value( 3).toDouble() );
        athlete->setGender( q.value( 4).toBool() );
    }
    else
    {
        Athlete::newAthlete();
    }
}

void Athlete::saveAthlete()
{
    Athlete *athlete = Athlete::getInstance();

    QString qName = athlete->getName();
    QString qDate = athlete->getDoB().toString("yyyy-MM-dd");
    QString qHeight = QString::number(athlete->getHeight());
    QString qGender = athlete->isMale() ? "true" : "false";
    QString qId = QString::number(athlete->getId());

    QSqlQuery q( "UPDATE athletes "
                 "SET name='"+qName +"',"
                     "dob ='"+qDate+"',"
                     "height ="+qHeight +","
                     "male ='"+qGender+"' "
                 "WHERE id = "+qId );

    q.exec();
}

void Athlete::insertNewAthlete()
{
    Athlete *athlete = Athlete::getInstance();

    QString qName = athlete->getName();
    QString qDate = athlete->getDoB().toString("yyyy-MM-dd");
    QString qHeight = QString::number(athlete->getHeight());
    QString qGender = athlete->isMale() ? "true" : "false";
    QString qId = QString::number(athlete->getId());

    QSqlQuery q( "INSERT INTO athletes (name, dob, height, male) "
                 "VALUES ('"+qName +"',"
                         "'"+qDate+"',"
                            +qHeight +","
                         "'"+qGender+"')" );

    // q.exec();
}
