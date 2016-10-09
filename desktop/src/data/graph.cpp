// $Id: graph.cpp 372 2013-03-05 22:04:13Z boffyflow $
// (c) 2010, Parallel Pixels Ltd.

#include "graph.h"

#include <QApplication>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>
#include <QDomDocument>

Graph::Graph()
{
    initialize();
}

Graph::Graph( const int id)
{
    initialize();
    mId = id;
    restore( mId);
}

Graph::~Graph()
{
    delete mQuery;
}

QList<Graph *>    Graph::graphList()
{
    QList<Graph *>        glist;

    QSqlQuery   q( "select id from graphs");

    while( q.next())
    {
        Graph        *g = new Graph( q.value( 0).toInt());
        glist.append( g);
    }

    return glist;
}

void Graph::initialize()
{
    mId = -1;
    mName = qApp->tr( "untitled");
    mQuery = new QueryParameters();
    mTemplateName = "";
}

void Graph::restore()
{
    restore( mId);
}

void Graph::restore( const int id)
{
    QSqlQuery   q( "select id,name,template,query from graphs where id=" + QString::number( id));

    if( q.next())
    {
        setName( q.value( 1).toString());
        setTemplateName( q.value( 2).toString());
        mQuery->restoreFromXML( q.value( 3).toString());
        mId = id;
    }
    else
    {
        mId = -1;
    }
}

int Graph::save( const int graph_id)
{
    mId = graph_id;
    if( mId > 0)
    {
        // update
        QSqlQuery       q;

        q.prepare( "update graphs set name=:name,template=:template,query=:query where id=" + QString::number( mId));

        q.bindValue( ":name", name());
        q.bindValue( ":template", templateName());
        q.bindValue( ":query", mQuery->toXML());
        q.exec();
    }
    else
    {
        // insert
        QSqlQuery       q;

        q.prepare( "insert into graphs (name,template,query) values(:name,:template,:query)");
        q.bindValue( ":name", name());
        q.bindValue( ":template", templateName());
        q.bindValue( ":query", mQuery->toXML());

        q.exec();
        mId = q.lastInsertId().toInt();
    }

    return mId;
}

void Graph::remove()
{
    QSqlQuery		q( "delete from graphs where id=" + QString::number( mId));

    mId = -1;
}
