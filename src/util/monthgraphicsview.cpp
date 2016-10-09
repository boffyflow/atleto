// $Id: monthgraphicsview.cpp 294 2010-03-05 18:37:10Z  $
// (c) 2006, Parallel Pixels Ltd.

#include "src/util/monthgraphicsview.h"

#include <QGraphicsItem>
#include <QTime>

#include "src/util/monthgraphicsitem.h"
#include "src/data/run.h"
#include "src/data/physical.h"
#include "src/util/ctime.h"
#include "src/util/rununits.h"
#include "src/util/weightunits.h"


const       qreal       mainHeight = 400.0;
const       qreal       mainWidth = 560.0;

MonthGraphicsView::MonthGraphicsView( QWidget *parent) :
        QGraphicsView( parent)
{
    setMinimumSize( mainWidth, mainHeight);

    mScene = new QGraphicsScene( 0.0, 0.0, mainWidth, mainHeight, this);
    mScene->setItemIndexMethod( QGraphicsScene::NoIndex);
    setScene( mScene);

    qreal   w = mainWidth / 7.0;
    qreal   h = mainHeight / 6.0;

    QDate       d = QDate::currentDate();

    for( int row = 0; row < 6; row++)
    {
        for( int col = 0; col < 7; col++)
        {
            MonthGraphicsItem           *item = new MonthGraphicsItem( col * w, row * h, w, h);

            item->setBackGroundColor( QColor( 221, 245, 221));

            mScene->addItem( item);
            mMonthGraphicItems.append( item);
        }
    }
}

MonthGraphicsView::MonthGraphicsView( QGraphicsScene *scene, QWidget *parent) :
        QGraphicsView( scene, parent)
{
}

void MonthGraphicsView::setFirstDayOfMonth( const QDate &date)
{
    mFirstDayOfMonth = QDate( date.year(), date.month(), 1);
    QDate           startDay = mFirstDayOfMonth.addDays( 1 - mFirstDayOfMonth.dayOfWeek());

    for( int row  = 0; row < 6; row++)
    {
        for( int col = 0; col < 7; col++)
        {
            QDate       d = startDay.addDays( row * 7 + col);

            QGraphicsItem   *item =(QGraphicsItem *) mMonthGraphicItems.at( row * 7 + col);

            item->setData( MG_ITEM_DAY, d);
            if( d.month() != mFirstDayOfMonth.month())
            {
                item->setData( MG_ITEM_INMONTH, false);
                item->setData( MG_ITEM_HASRUN, false);
                item->setToolTip( "");
            }
            else
            {
                item->setData( MG_ITEM_INMONTH, true);

                QList<Run>      runList = Run::runList( d);
                if( runList.count() > 0)
                {
                    item->setData( MG_ITEM_HASRUN, true);
                    float       dist = 0.0;
                    float       total_time = 0.0;
                    for( int i = 0; i < runList.count(); i++)
                    {
                        dist += runList.at( i).distance();
                        total_time += runList.at( i).total_time();
                    }

                    RunDistanceString   rs;
                    rs.setValue( dist);

                    item->setToolTip( rs.text() + "\n" + cTime::t2str( total_time) + "\n" + rs.pace( total_time));
                }
                else
                {
                    item->setData( MG_ITEM_HASRUN, false);
                    item->setToolTip( "");
                }
            }
        }
    }

    mScene->update();
}

void MonthGraphicsView::resizeEvent( QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);
    fitInView( scene()->sceneRect(), Qt::KeepAspectRatio);
}
