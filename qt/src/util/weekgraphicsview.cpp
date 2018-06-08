// $Id: weekgraphicsview.cpp 369 2010-09-25 00:02:33Z boffyflow $
// (c) 2006, Parallel Pixels Ltd.

#include "src/util/weekgraphicsview.h"

#include <QGraphicsItem>
#include <QTime>

#include "src/util/weekgraphicsitem.h"
#include "src/util/graphicsbaritem.h"
#include "src/util/graphicsiconitem.h"
#include "src/data/run.h"
#include "src/data/runrace.h"
#include "src/data/physical.h"
#include "src/data/weather.h"
#include "src/data/journalentry.h"
#include "src/util/ctime.h"
#include "src/util/rununits.h"
#include "src/util/weightunits.h"
#include "src/util/temperatureunits.h"

const       qreal       mainHeight = 400.0;
const       qreal       mainWidth = 560.0;

const       qreal       dateRowHeight = 30.0;
const       qreal       runRowHeight = 151.0;
const       qreal       physicalRowHeight = 151.0;
const       qreal       weatherRowHeight = 34.0;
const       qreal       journalRowHeight = 34.0;

WeekGraphicsView::WeekGraphicsView( QWidget *parent) :
        QGraphicsView( parent)
{
    setMinimumSize( mainWidth, mainHeight);

    mScene = new QGraphicsScene( 0.0, 0.0, mainWidth, mainHeight, this);
    mScene->setItemIndexMethod( QGraphicsScene::NoIndex);
    setScene( mScene);

    qreal   w = mainWidth / 7.0;

    QDate       d = QDate::currentDate();

    for( int col = 0; col < 7; col++)
    {
        qreal       y = 0.0;

        QGraphicsSimpleTextItem     *dateItem = new QGraphicsSimpleTextItem( d.toString( "ddd - dd"));
        dateItem->setFont( QFont( "Arial", 9, 80));
        dateItem->setPos( col * w + ( w - dateItem->boundingRect().width()) * 0.5, 5.0);
        mScene->addItem( dateItem);
        mWeekGraphicItems.append( dateItem);

        y += dateRowHeight;

        WeekGraphicsItem        *runItem = new WeekGraphicsItem( col * w, y, w, runRowHeight);
        runItem->setBackGroundColor( QColor( 221, 245, 221));
        runItem->setData( WG_ITEM_TYPE, "run");
        mScene->addItem( runItem);
        mWeekGraphicItems.append( runItem);

        y += runRowHeight;

        WeekGraphicsItem        *phyItem = new WeekGraphicsItem( col * w, y, w, physicalRowHeight);
        phyItem->setBackGroundColor( QColor( 221, 221, 245));
        phyItem->setData( WG_ITEM_TYPE, "physical");
        mScene->addItem( phyItem);
        mWeekGraphicItems.append( phyItem);

        y += physicalRowHeight;

        WeekGraphicsItem        *weatherItem = new WeekGraphicsItem( col * w, y, w, weatherRowHeight);
        weatherItem->setBackGroundColor( QColor( 255, 255, 200));
        weatherItem->setData( WG_ITEM_TYPE, "weather");
        mScene->addItem( weatherItem);
        mWeekGraphicItems.append( weatherItem);

        y += weatherRowHeight;

        WeekGraphicsItem        *journalItem = new WeekGraphicsItem( col * w, y, w, journalRowHeight);
        journalItem->setBackGroundColor( QColor( 245, 245, 245));
        journalItem->setData( WG_ITEM_TYPE, "journal");
        mScene->addItem( journalItem);
        mWeekGraphicItems.append( journalItem);
    }
}

WeekGraphicsView::WeekGraphicsView( QGraphicsScene *scene, QWidget *parent) :
        QGraphicsView( scene, parent)
{
}

void WeekGraphicsView::setFirstDayOfWeek( const QDate &date)
{
    mFirstDayOfWeek = date.addDays( 1 - date.dayOfWeek());

    for( int col  = 0; col < 7; col++)
    {
        for( int row = 0; row < 5; row++)
        {
            QGraphicsItem   *item =(QGraphicsItem *) mWeekGraphicItems.at( col * 5 + row );

            item->setData( WG_ITEM_DATE, mFirstDayOfWeek.addDays( col));

            if( row == 0)
            {
                if( col == 6)
                    ((QGraphicsSimpleTextItem *) item)->setBrush( QBrush( QColor( Qt::red)));
                else
                    ((QGraphicsSimpleTextItem *) item)->setBrush( QBrush( QColor( Qt::black)));

                ((QGraphicsSimpleTextItem *) item)->setText( mFirstDayOfWeek.addDays( col).toString( "ddd - dd") );
            }
        }
    }

    loadDataIntoView();
}

void WeekGraphicsView::loadDataIntoView()
{
    for( int i = 0; i < mDynamicItems.count(); i++)
    {
        mScene->removeItem( mDynamicItems.at( i));
        delete mDynamicItems.at( i);
    }
    mDynamicItems.clear();

    qreal       w = mainWidth / 7.0;
    qreal       colWidth;
    qreal       colHeight;
    qreal       colX;
    qreal       colY;

    // run

    float       maxDist = 0.0;
    QList<Run>      maxRunList = Run::runList( mFirstDayOfWeek, mFirstDayOfWeek.addDays( 6));
    for( int i = 0; i < maxRunList.count(); i++)
        if( maxRunList.at( i).distance() > maxDist)
            maxDist = maxRunList.at( i).distance();

    QStringList     ratingList;
    ratingList << "" << PHYSICAL_RATING_POOR << PHYSICAL_RATING_FAIR << PHYSICAL_RATING_GOOD << PHYSICAL_RATING_VERY_GOOD << PHYSICAL_RATING_EXCELLENT;

    for( int day = 0; day < 7; day++)
    {
        QList<Run>      runList = Run::runList( mFirstDayOfWeek.addDays( day));

        for( int i = 0; i < runList.count(); i++)
        {
            Run     r = runList.at( i);

            colWidth = ( w - 20.0) / runList.count();
            colHeight = (runRowHeight - 25.0) * r.distance() / maxDist;
            colX =  day * w + 10 + i * colWidth;
            colY = dateRowHeight + 5.0 + runRowHeight - 25.0 - colHeight;

            GraphicsBarItem   *ritem = new GraphicsBarItem( colX, colY, colWidth, colHeight);
            RunDistanceString       rs;
            rs.setValue( r.distance());
            ritem->setBackGroundColor( QColor( Qt::green));
            if( r.aveHeartRate() > 0 && r.maxHeartRate() > r.aveHeartRate())
                ritem->setToolTip( r.location() + "\n" + rs.text() + "\n" + cTime::t2str( r.total_time()) + "\n" + rs.pace( r.total_time()) +
                               "\nHeartrate (bpm) average: " + QString::number( r.aveHeartRate()) + ", max: " + QString::number( r.maxHeartRate()));
            else
                ritem->setToolTip( r.location() + "\n" + rs.text() + "\n" + cTime::t2str( r.total_time()) + "\n" + rs.pace( r.total_time()));
            ritem->setData( GB_ITEM_TYPE, "run");
            ritem->setData( GB_ITEM_LABEL, rs.text());
            ritem->setData( GB_ITEM_ID, r.id());

            RunRace     race;
            race.restoreByRunId( r.id());
            ritem->setData( GB_ITEM_RACE, race.id());

            mDynamicItems.append( ritem);
            mScene->addItem( ritem);
        }

        // weight

        Physical        p;
        p.restoreByJulianDay( mFirstDayOfWeek.addDays( day).toJulianDay());
        float           maxWeight = Physical::max( mFirstDayOfWeek, mFirstDayOfWeek.addDays( 6), "weight");
        float           minWeight = Physical::min( mFirstDayOfWeek, mFirstDayOfWeek.addDays( 6), "weight");

        if( p.weight() > 0)
        {
            colWidth = w - 20.0;
            if( ( maxWeight - minWeight) < 0.001)
                colHeight = physicalRowHeight * 0.5;
            else
                colHeight = ( physicalRowHeight - 25.0 - 20.0) * ( p.weight() - minWeight) / ( maxWeight - minWeight) + 20.0;
            colX = day * w + 10;
            colY = dateRowHeight + runRowHeight + 5.0 + physicalRowHeight - 25.0 - colHeight;

            GraphicsBarItem   *pitem = new GraphicsBarItem( colX, colY, colWidth, colHeight);
            WeightString        ws;
            ws.setValue( p.weight());
            pitem->setBackGroundColor( QColor( Qt::blue));
            if( p.bodyFat() > 0.1)
                pitem->setToolTip( ws.text() + "\nBody fat: " + QString::number( p.bodyFat(), 'f', 1) + "%\nRating: " + ratingList.at( p.rating()));
            else
                pitem->setToolTip( ws.text() + "\nRating: " + ratingList.at( p.rating()));
            pitem->setData( GB_ITEM_TYPE, "physical");
            pitem->setData( GB_ITEM_LABEL, ws.text());
            pitem->setData( GB_ITEM_ID, p.id());
            mDynamicItems.append( pitem);
            mScene->addItem( pitem);
        }

        // weather

        Weather     weather;
        weather.restoreByJulianDay( mFirstDayOfWeek.addDays( day).toJulianDay());

        if( weather.id() > 0)
        {
            colWidth = 60.0;
            colHeight = 26.0;
            colX =  day * w + 10;
            colY = dateRowHeight + runRowHeight + physicalRowHeight + 2.0;

            GraphicsIconItem        *witem = new GraphicsIconItem( colX, colY, colWidth, colHeight);
            TemperatureString       ts;
            ts.setValue( weather.temperature());

            witem->setBackGroundColor( QColor( Qt::yellow));
            witem->setData( GI_ITEM_ID, weather.id());
            witem->setData( GI_ITEM_TYPE, "weather");
            witem->setData( GI_ITEM_LABEL, ts.text());
            witem->setData( GI_ITEM_ICON, ":/main/icons/weather" + QString::number( weather.sky()));
            if( weather.notes().isEmpty())
                witem->setToolTip( ts.text());
            else
                witem->setToolTip( ts.text() + "\n" + weather.notes());
            mDynamicItems.append( witem);
            mScene->addItem( witem);
        }

        // journal

        JournalEntry    je;
        je.restoreByJulianDay( mFirstDayOfWeek.addDays( day).toJulianDay());

        if( je.id() > 0)
        {
            colWidth = 60.0;
            colHeight = 26.0;
            colX =  day * w + 10;
            colY = dateRowHeight + runRowHeight + physicalRowHeight + weatherRowHeight + 2.0;

            GraphicsIconItem        *jitem = new GraphicsIconItem( colX, colY, colWidth, colHeight);
            jitem->setBackGroundColor( QColor( Qt::gray));
            jitem->setData( GI_ITEM_ID, je.id());
            jitem->setData( GI_ITEM_TYPE, "journal");
            jitem->setData( GI_ITEM_LABEL, "");
            jitem->setData( GI_ITEM_ICON, ":/main/icons/journal.png");
            jitem->setToolTip( je.entry());
            mDynamicItems.append( jitem);
            mScene->addItem( jitem);
        }
    }

    mScene->update();

    emit dataChanged();
}

void WeekGraphicsView::resizeEvent( QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);
    fitInView( scene()->sceneRect(), Qt::KeepAspectRatio);
}
