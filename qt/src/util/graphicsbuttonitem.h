// $Id: graphicsbuttonitem.h 294 2010-03-05 18:37:10Z  $
// (c) 2009, Parallel Pixels Ltd.

#ifndef GRAPHICSBUTTONITEM_H
#define GRAPHICSBUTTONITEM_H

#include <QGraphicsProxyWidget>
#include <QDate>

const int WEATHERBUTTON = 0;
const int PHYSICALBUTTON = 1;
const int JOURNALBUTTON = 2;


class GraphicsButtonItem : public QGraphicsProxyWidget
{
public:

    GraphicsButtonItem( const int type = WEATHERBUTTON);

    void	mousePressEvent ( QGraphicsSceneMouseEvent * event);

    void        setDate( const QDate &day) { mDate = day;};

private:

    int     mType;
    QDate   mDate;
};

#endif // GRAPHICSBUTTONITEM_H
