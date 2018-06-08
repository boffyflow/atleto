// $Id: plot.cpp 370 2010-12-14 23:23:50Z boffyflow $
// (c) 2010 Parallel Pixels Ltd.

#include "plot.h"
#include "ui_plot.h"

#include "src/plot/plotgraph.h"
#include "src/util/cgeneral.h"
#include "src/util/ctime.h"

#include <math.h>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

Plot::Plot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Plot)
{
    ui->setupUi( this);

    mScene = new QGraphicsScene( QRectF( 0.0, 0.0, 580.0, 400.0));

    ui->plotView->setScene( mScene);
    ui->plotView->viewport()->resize( mScene->sceneRect().width(), mScene->sceneRect().height()); // required to set initial size of graph correctly

    mRotationAngleXAxis = 30;
    mHorizontalGridLines = true;
}

Plot::~Plot()
{
    delete ui;
    delete mScene;

    clear();
}

void Plot::clear()
{
    for( int i = 0; i < mGraphs.count(); i++)
        delete mGraphs.at( i);

    mGraphs.clear();
}

void Plot::resizeEvent( QResizeEvent *event)
{
    ui->plotView->fitInView( ui->plotView->scene()->sceneRect(), Qt::KeepAspectRatio);
}

void Plot::setTitle( const QString &title)
{
    ui->titleLabel->setText( title);
}

void Plot::addGraph( PlotGraph *graph)
{
    mGraphs.append( graph);
}

void Plot::draw()
{
    // delete all items before drawing

    mScene->clear();

    qreal       left_offset = computeLeftWidth();
    qreal       right_offset = computeRightWidth() + 2;
    qreal       bottom_offset = computeBottomHeight();

    QGraphicsRectItem        *leftitem = drawLeftRect( left_offset, mScene->height() - bottom_offset);
    leftitem->setPos( 0, 0);
    mScene->addItem( leftitem);

    QGraphicsRectItem        *centeritem = drawCenterRect( mScene->width() - left_offset - right_offset, mScene->height() - bottom_offset);
    centeritem->setPos( leftitem->boundingRect().width() + 1, 0);
    mScene->addItem( centeritem);

    QGraphicsRectItem        *rightitem = drawRightRect( right_offset, mScene->height() - bottom_offset);
    rightitem->setPos( leftitem->boundingRect().width() + centeritem->boundingRect().width() + 2, 0);
    mScene->addItem( rightitem);

    QGraphicsRectItem        *bottomitem = drawBottomRect( mScene->width() - left_offset - right_offset, bottom_offset);
    bottomitem->setPos( leftitem->boundingRect().width() + 1, centeritem->boundingRect().height() + 1);
    mScene->addItem( bottomitem);
}

QGraphicsRectItem* Plot::drawLeftRect( const qreal width, const qreal height)
{     
    QGraphicsRectItem       *outlineItem = new QGraphicsRectItem();

    outlineItem->setRect( 0, 0, width, height);
    outlineItem->setPen( QPen( Qt::white));
    outlineItem->setBrush( QBrush( Qt::white));

    if( mGraphs.count() < 1)
        return outlineItem;

    qreal   step = computeYStep( 0);

    if( mGraphs.at( 0)->graphType() == PLOT_GRAPH_HISTOGRAM)
    {
        qreal   step_pixels = step * height / ( mGraphs.at( 0)->series().maxY());

        qreal   ticy = cGeneral::rnd( mGraphs.at( 0)->series().minY() / step) * step;
        if( ticy < mGraphs.at( 0)->series().minY())
            ticy += step;

        qreal   ticy_pixels = height *  ticy / ( mGraphs.at( 0)->series().maxY());

        while( ticy_pixels < height)
        {
            // tics
            QGraphicsLineItem   *litem = new QGraphicsLineItem( width, height - ticy_pixels, width - PLOT_TIC_LENGTH, height - ticy_pixels, outlineItem);
            litem->setPen( QPen( mGraphs.at( 0)->series().color()));

            // label
            QGraphicsTextItem     *titem = new QGraphicsTextItem( "", outlineItem);
            titem->setDefaultTextColor( mGraphs.at( 0)->series().color());
            if( mGraphs.at( 0)->series().unitY() == PLOT_UNIT_PACE)
                titem->setPlainText( cTime::t2str( ticy, false));
            else
                titem->setPlainText( QString::number( ticy) + " " + mGraphs.at( 0)->series().unitStringY());
            titem->setPos( width - titem->boundingRect().width() - 6, height - ticy_pixels - 0.5 * titem->boundingRect().height());

            ticy_pixels += step_pixels;
            ticy += step;
        }
    }
    else if( mGraphs.at( 0)->graphType() == PLOT_GRAPH_LINE)
    {
        qreal   h = height - 10;

        qreal   step_pixels = step * h / ( mGraphs.at( 0)->series().maxY() - mGraphs.at( 0)->series().minY());

        qreal   ticy = cGeneral::rnd( mGraphs.at( 0)->series().minY() / step) * step;
        if( ticy < mGraphs.at( 0)->series().minY())
            ticy += step;

        qreal   ticy_pixels = h * ( ticy - mGraphs.at( 0)->series().minY()) / ( mGraphs.at( 0)->series().maxY() - mGraphs.at( 0)->series().minY());

        while( ticy_pixels < h)
        {
            // tics
            QGraphicsLineItem   *litem = new QGraphicsLineItem( width, height - ticy_pixels - 5, width - PLOT_TIC_LENGTH, height - ticy_pixels - 5, outlineItem);
            litem->setPen( QPen( mGraphs.at( 0)->series().color()));

            // label
            QGraphicsTextItem     *titem = new QGraphicsTextItem( "", outlineItem);
            titem->setDefaultTextColor( mGraphs.at( 0)->series().color());
            if( mGraphs.at( 0)->series().unitY() == PLOT_UNIT_PACE)
                titem->setPlainText( cTime::t2str( ticy, false) + " " + mGraphs.at( 0)->series().unitStringY());
            else
                titem->setPlainText( QString::number( ticy) + " " + mGraphs.at( 0)->series().unitStringY());
            titem->setPos( width - titem->boundingRect().width() - 6, height - 5 - ticy_pixels - 0.5 * titem->boundingRect().height());

            ticy_pixels += step_pixels;
            ticy += step;
        }
    }

    return outlineItem;
}

QGraphicsRectItem* Plot::drawCenterRect( const qreal width, const qreal height)
{
    QGraphicsRectItem       *outlineItem = new QGraphicsRectItem();

    outlineItem->setRect( 0, 0, width, height);
    outlineItem->setPen( QPen( Qt::white));
    outlineItem->setBrush( QBrush( Qt::white));

    if( mGraphs.count() < 1)
        return outlineItem;

    // draw x and y lines

    new QGraphicsLineItem( 0, 0, 0, outlineItem->boundingRect().height(), outlineItem);
    new QGraphicsLineItem( 0, outlineItem->boundingRect().height(), outlineItem->boundingRect().width(), outlineItem->boundingRect().height(), outlineItem);

    // draw right y axis, if needed
    if( mGraphs.count() > 1)
        new QGraphicsLineItem( outlineItem->boundingRect().width(), 0, outlineItem->boundingRect().width(), outlineItem->boundingRect().height(), outlineItem);

    for( int plotIndex = 0; plotIndex < mGraphs.count(); plotIndex++)
    {
        PlotSeries      ps = mGraphs.at( plotIndex)->series();
        PlotGraph       *pg = mGraphs.at( plotIndex);

        // draw histogram bars

        if( pg->graphType() == PLOT_GRAPH_HISTOGRAM)
        {
            qreal           h = outlineItem->boundingRect().height();
            qreal           w = outlineItem->boundingRect().width() / ps.points().size();
            qreal           hwidth = w * 0.667;
            qreal           gap = ( w - hwidth) * 0.5;

            for( int j = 0; j < ps.points().size(); j++)
            {
                float           height = h * ps.points().at( j).y() / ps.maxY();

                QGraphicsRectItem   *item = new QGraphicsRectItem( gap + j * w, h - height, hwidth, height, outlineItem);
                QLinearGradient gradient( item->boundingRect().topLeft(), item->boundingRect().bottomLeft());
                gradient.setColorAt( 1, Qt::white);
                if( ps.points().at( j).flag())
                    gradient.setColorAt( 0, ps.color());
                else
                    gradient.setColorAt( 0, Qt::red);
                item->setBrush( QBrush( gradient));
                item->setToolTip( ps.points().at(j).xLabel() + "\n" + ps.points().at(j).yLabel());
            }
        }
        else if( pg->graphType() == PLOT_GRAPH_LINE)
        {
            qreal           h = outlineItem->boundingRect().height() - 10;
            qreal           w = outlineItem->boundingRect().width() - 20;

            for( int j = 0; j < ps.points().size(); j++)
            {
                qreal       x;

                if( ps.unitX() == PLOT_UNIT_DISTANCE)
                    x = w * ( ps.points().at( j).x() - ps.minX()) / ( ps.maxX() - ps.minX()) + 10;
                else                 // if not distance we assume it x axis is equidistant
                    x = w * j / ( ps.points().size() - 1) + 10;

                qreal       y = h - h * ( ps.points().at( j).y() - ps.minY()) / ( ps.maxY() - ps.minY()) + 5;

                if( j < ps.points().size() - 1)
                {
                    qreal       x2;

                    if( ps.unitX() == PLOT_UNIT_DISTANCE)
                        x2 = w * ( ps.points().at( j + 1).x() - ps.minX()) / ( ps.maxX() - ps.minX()) + 10;
                    else
                        x2 = w * ( j + 1) / ( ps.points().size() - 1) + 10;

                    qreal       y2 = h - h * ( ps.points().at( j + 1).y() - ps.minY()) / ( ps.maxY() - ps.minY()) + 5;

                    QGraphicsLineItem       *litem = new QGraphicsLineItem( x, y, x2, y2, outlineItem);
                    litem->setPen( QPen( QBrush( ps.color()), 2));
                }

                QGraphicsEllipseItem    *citem = new QGraphicsEllipseItem( x - 2, y - 2, 4, 4, outlineItem);
                citem->setPen( QPen( ps.color()));
                citem->setBrush( QBrush( ps.color()));
                citem->setToolTip( ps.points().at( j).xLabel() + "\n" + ps.points().at( j).yLabel());
            }
        }
    }

    return outlineItem;
}

QGraphicsRectItem* Plot::drawRightRect( const qreal width, const qreal height)
{
    QGraphicsRectItem       *outlineItem = new QGraphicsRectItem();

    outlineItem->setRect( 0, 0, width, height);
    outlineItem->setPen( QPen( Qt::white));
    outlineItem->setBrush( QBrush( Qt::white));

    if( mGraphs.count() < 2)
        return outlineItem;

    PlotGraph               *pg = mGraphs.at( 1);

    qreal   step = computeYStep( 1);

    if( pg->graphType() == PLOT_GRAPH_HISTOGRAM)
    {
        qreal   step_pixels = step * height / ( pg->series().maxY());

        qreal   ticy = cGeneral::rnd( pg->series().minY() / step) * step;
        if( ticy < pg->series().minY())
            ticy += step;

        qreal   ticy_pixels = height *  ticy / ( pg->series().maxY());

        while( ticy_pixels < height)
        {
            // tics
            QGraphicsLineItem   *litem = new QGraphicsLineItem( width, height - ticy_pixels, width - PLOT_TIC_LENGTH, height - ticy_pixels, outlineItem);
            litem->setPen( QPen( pg->series().color()));

            // label
            QGraphicsTextItem     *titem = new QGraphicsTextItem( "", outlineItem);
            titem->setDefaultTextColor( pg->series().color());
            if( pg->series().unitY() == PLOT_UNIT_PACE)
                titem->setPlainText( cTime::t2str( ticy, false));
            else
                titem->setPlainText( QString::number( ticy) + " " + pg->series().unitStringY());
            titem->setPos( width - titem->boundingRect().width() - 6, height - ticy_pixels - 0.5 * titem->boundingRect().height());

            ticy_pixels += step_pixels;
            ticy += step;
        }
    }
    else if( pg->graphType() == PLOT_GRAPH_LINE)
    {
        qreal   h = height - 10;

        qreal   step_pixels = step * h / ( pg->series().maxY() - pg->series().minY());

        qreal   ticy = cGeneral::rnd( pg->series().minY() / step) * step;
        if( ticy < pg->series().minY())
            ticy += step;

        qreal   ticy_pixels = h * ( ticy - pg->series().minY()) / ( pg->series().maxY() - pg->series().minY());

        while( ticy_pixels < h)
        {
            // tics
            QGraphicsLineItem   *litem = new QGraphicsLineItem( 0, height - ticy_pixels - 5, PLOT_TIC_LENGTH, height - ticy_pixels - 5, outlineItem);
            litem->setPen( QPen( pg->series().color()));

            // label
            QGraphicsTextItem     *titem = new QGraphicsTextItem( "", outlineItem);
            titem->setDefaultTextColor( pg->series().color());
            if( pg->series().unitY() == PLOT_UNIT_PACE)
                titem->setPlainText( cTime::t2str( ticy, false) + " " + pg->series().unitStringY());
            else
                titem->setPlainText( QString::number( ticy) + " " + pg->series().unitStringY());
            titem->setPos( PLOT_TIC_LENGTH + 2, height - 5 - ticy_pixels - 0.5 * titem->boundingRect().height());

            ticy_pixels += step_pixels;
            ticy += step;
        }
    }

    return outlineItem;
}

QGraphicsRectItem* Plot::drawBottomRect( const qreal width, const qreal height)
{
    QGraphicsRectItem       *outlineItem = new QGraphicsRectItem();

    outlineItem->setRect( 0, 0, width, height);
    outlineItem->setBrush( QBrush( Qt::white));
    outlineItem->setPen( QPen( Qt::white));

    if( mGraphs.count() < 1)
        return outlineItem;

    PlotSeries      ps = mGraphs.at( 0)->series();

    if( mGraphs.at( 0)->graphType() == PLOT_GRAPH_LINE)
    {
        qreal   step = computeXStep( 0);
        qreal   step_pixels = step * ( width - 20) / ( ps.maxX() - ps.minX());

        qreal   ticx = cGeneral::rnd( ps.minX() / step) * step;
        if( ticx < ps.minX())
            ticx += step;

        qreal   ticx_pixels = ( width - 20) * ( ticx - ps.minX()) / ( ps.maxX() - ps.minX()) + 10;

        while( ticx_pixels <= ( width - 10))
        {
            // tics
            QGraphicsLineItem   *litem = new QGraphicsLineItem( ticx_pixels, 0, ticx_pixels, PLOT_TIC_LENGTH, outlineItem);
            litem->setPen( QPen( Qt::black));

            // labels
            QGraphicsTextItem     *titem = new QGraphicsTextItem( "", outlineItem);
            titem->setPlainText( QString::number( ticx));
            titem->setPos( ticx_pixels - 0.5 * titem->boundingRect().width(), PLOT_TIC_LENGTH + 1);

            ticx_pixels += step_pixels;
            ticx += step;
        }
    }
    else if( mGraphs.at( 0)->graphType() == PLOT_GRAPH_HISTOGRAM)
    {
        float           w = outlineItem->boundingRect().width() / ps.points().size();
        float           hwidth = w * 0.667;
        float           gap = ( w - hwidth) * 0.5;

        for( int j = 0; j < ps.points().size(); j++)
        {
            QGraphicsSimpleTextItem     *titem = new QGraphicsSimpleTextItem( ps.points().at( j).xLabel(), outlineItem);
            titem->setPos( gap + j * w + 0.5 * hwidth, 1);
            titem->setRotation( mRotationAngleXAxis);        // = PI * 0.25
        }
    }

    return outlineItem;
}

qreal Plot::computeLeftWidth()
{
    qreal       width = 0;

    if( mGraphs.count() == 1 || mGraphs.count() == 2)
    {
        PlotGraph   *pg = mGraphs.at( 0);
        qreal       val = pg->series().maxY();

        QGraphicsTextItem     *titem = new QGraphicsTextItem( "");
        if( pg->series().unitY() == PLOT_UNIT_PACE)
            titem->setPlainText( cTime::t2str( val, false) + " " + pg->series().unitStringY());
        else
            titem->setPlainText( QString::number( cGeneral::rnd( val)) + " " + pg->series().unitStringY());
        width = titem->boundingRect().width() + PLOT_TIC_LENGTH + 2;
    }

    return width;
}

qreal Plot::computeRightWidth()
{
    qreal       width = 0;

    if( mGraphs.count() == 2)
    {
        PlotGraph   *pg = mGraphs.at( 1);
        qreal       val = pg->series().maxY();

        QGraphicsSimpleTextItem     *titem = new QGraphicsSimpleTextItem( QString::number( cGeneral::rnd( val)) + "  " + pg->series().unitStringY());
        width = titem->boundingRect().width() + PLOT_TIC_LENGTH + 2;
    }

    return width;
}

qreal Plot::computeBottomHeight()
{
    qreal   height = 0;

    if( mGraphs.count() > 0)
    {
        PlotSeries      ps = mGraphs.at( 0)->series();

        for( int j = 0; j < ps.points().size(); j++)
        {
            QGraphicsSimpleTextItem     *titem = new QGraphicsSimpleTextItem( ps.points().at( j).xLabel());
            qreal      real_height = titem->boundingRect().height() * cos( mRotationAngleXAxis * PI / 180.0) +
                                     titem->boundingRect().width() * sin( mRotationAngleXAxis * PI / 180.0);
            if( real_height > height)
                height = real_height;
        }
    }

    return height + PLOT_TIC_LENGTH + 2;
}

qreal Plot::computeXStep( const int index)
{
    PlotSeries      ps = mGraphs.at( index)->series();

    int     ndigits = cGeneral::numDigits( cGeneral::rnd( ps.maxX() - ps.minX()));
    qreal   dx = ( ps.maxX() - ps.minX()) / pow( 10.0, ndigits - 1);

    return computeStep( dx, pow( 10.0, ndigits - 2));
}

qreal Plot::computeYStep( const int index)
{
    PlotSeries      ps = mGraphs.at( index)->series();
    int             ndigits;
    qreal           dy;

    if( ps.zeroBased())
    {
        ndigits = cGeneral::numDigits( cGeneral::rnd( ps.maxY()));
        dy = ps.maxY() / pow( 10.0, ndigits - 1);
    }
    else
    {
        ndigits = cGeneral::numDigits( cGeneral::rnd( ps.maxY() - ps.minY()));
        dy = ( ps.maxY() - ps.minY()) / pow( 10.0, ndigits - 1);
    }

    return computeStep( dy, pow( 10.0, ndigits - 2));
}

qreal Plot::computeStep( const qreal delta, const qreal base)
{
    qreal       step;

    if( delta < 1.5)
        step = base;
    else if( delta < 3.5)
        step = 2.0 * base;
    else if( delta <= 7.5)
        step = 5.0 * base;
    else
        step = 10.0 * base;

    return step;
}
