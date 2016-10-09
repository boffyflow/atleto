// $Id: graph.h 372 2013-03-05 22:04:13Z boffyflow $
// (c) 2010, Parallel Pixels Ltd.

#ifndef GRAPH_H
#define GRAPH_H

#include <QString>
#include <QStringList>
#include <QMap>
#include <QList>
#include <QDate>

#include "src/data/queryparameters.h"

class Graph
{
public:

    Graph();
    Graph( const int id);
    ~Graph();

    static      QList<Graph *>    graphList();

    int         id() const { return mId;}
    QString     name() const { return mName;}
    void        setName( const QString &name) { mName = name;}
    QString     templateName() const { return mTemplateName;}
    void        setTemplateName( const QString &tname) { mTemplateName = tname;}

    QueryParameters*    queryParameters() { return mQuery;}
    void                setQueryParameters( QueryParameters *query) { mQuery = query;}

    void        restore();
    void        restore( const int id);
    int         save( const int graph_id = -1);
    void        remove();

private:

    void        initialize();

    int                     mId;
    QString                 mName;
    QueryParameters         *mQuery;
    QString                 mTemplateName;
};

#endif // GRAPH_H
