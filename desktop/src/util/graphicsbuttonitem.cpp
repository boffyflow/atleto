// $Id: graphicsbuttonitem.cpp 294 2010-03-05 18:37:10Z  $
// (c) 2009, Parallel Pixels Ltd.

#include <QGraphicsScene>
#include <QGraphicsView>

#include "graphicsbuttonitem.h"

#include "src/gui/weathereditor.h"

GraphicsButtonItem::GraphicsButtonItem( const int type)
{
    mType = type;
}

void GraphicsButtonItem::mousePressEvent( QGraphicsSceneMouseEvent *event)
{


    if( mType == WEATHERBUTTON)
    {
        WeatherEditor       wEditor( mDate, scene()->views().at( 0));

        if( wEditor.exec() == QDialog::Accepted)
            parentItem()->update();
    }
    else if( mType == PHYSICALBUTTON)
    {
    }
    else if( mType == JOURNALBUTTON)
    {
    }
}
