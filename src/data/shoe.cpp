// $Id: shoe.cpp 369 2010-09-25 00:02:33Z boffyflow $
// (c) 2006-2009, Parallel Pixels Ltd.

#include <QtSql>

#include "shoe.h"
#include "src/data/data.h"

using namespace atleto;

Shoe::Shoe()
{
    initialize();
}

Shoe::Shoe( const int id)
{
    initialize();
    mId = id;
    restore( mId);
}

void Shoe::initialize()
{
    mId = -1;
    setNotes( "");
}

Shoe::~Shoe()
{
}

double Shoe::mileage()
{
    double      mileage = 0.0;

    QSqlQuery   q( "select sum(dist) from run_splits where run_id in (select id from runs where shoe_id=" + QString::number( mId) + ")");

    if( q.next())
    {
        mileage = q.value( 0).toDouble();
    }

    return mileage + startMileage();
}

void Shoe::restore()
{
    restore( mId);
}

void Shoe::restore( const int id)
{
    QSqlQuery   q( "select name,brand,model,size,notes,start_use,end_use,inuse,start_mileage,max_mileage from shoes where id=" + QString::number( id));

    if( q.next())
    {
        setName( q.value( 0).toString());
        setBrand( q.value( 1).toString());
        setModel( q.value( 2).toString());
        setSize( q.value( 3).toString());
        setNotes( q.value( 4).toString());
        setUseStart( q.value( 5).toDate());
        setUseEnd( q.value( 6).toDate());
        setActive( q.value( 7).toBool());
        setStartMileage( q.value( 8).toDouble());
        setMaxMileage( q.value( 9).toDouble());

        mId = id;
    }
    else
    {
        mId = -1;
    }
}

int Shoe::save( const int Shoe_id)
{
    mId = Shoe_id;
    if( mId > 0)
    {
        // update an existing shoe
        QSqlQuery       q;

        q.prepare( "update shoes set name=:name,brand=:brand,model=:model,size=:size,notes=:notes,start_use=:start_use,end_use=:end_use,inuse=:inuse,start_mileage=:start_mileage,max_mileage=:max_mileage where id=" + QString::number( mId));
        q.bindValue( ":name", name());
        q.bindValue( ":brand", brand());
        q.bindValue( ":model", model());
        q.bindValue( ":size", size());
        q.bindValue( ":notes", notes());
        q.bindValue( ":start_use", useStart());
        q.bindValue( ":end_use", useEnd());
        q.bindValue( ":inuse", active());
        q.bindValue( ":start_mileage", startMileage());
        q.bindValue( ":max_mileage", maxMileage());

        q.exec();
    }
    else
    {
        // write the a new Shoe
        QSqlQuery       q;

        q.prepare( "insert into shoes (name,brand,model,size,notes,start_use,end_use,inuse,start_mileage,max_mileage) values(:name,:brand,:model,:size,:notes,:start_use,:end_use,:inuse,:start_mileage,:max_mileage)");
        q.bindValue( ":name", name());
        q.bindValue( ":brand", brand());
        q.bindValue( ":model", model());
        q.bindValue( ":size", size());
        q.bindValue( ":notes", notes());
        q.bindValue( ":start_use", useStart());
        q.bindValue( ":end_use", useEnd());
        q.bindValue( ":inuse", active());
        q.bindValue( ":start_mileage", startMileage());
        q.bindValue( ":max_mileage", maxMileage());

        q.exec();

        mId = q.lastInsertId().toInt();
    }

    return mId;
}

void Shoe::remove()
{
    QSqlQuery		q( "delete from shoes where id=" + QString::number( mId));

    mId = -1;
}

 QList<Shoe>    Shoe::shoeList()
 {
    QList<Shoe>     shoeList;

    QSqlQuery   q( "select id from shoes");

    while( q.next())
    {
        Shoe        s( q.value( 0).toInt());
        shoeList.append( s);
    }

    return shoeList;
 }
