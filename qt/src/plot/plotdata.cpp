// $Id: plotdata.cpp 369 2010-09-25 00:02:33Z boffyflow $
// (c) 2010, Parallel Pixels Ltd.

#include <QDir>
#include <QTextStream>
#include <QProcess>

#include "src/data/athlete.h"
#include "src/data/run.h"
#include "src/data/physical.h"
#include "src/util/rununits.h"
#include "src/util/weightunits.h"
#include "src/util/cgeneral.h"
#include "src/util/ctime.h"
#include "src/plot/plotdata.h"
#include "src/plot/gnuplotcommand.h"

PlotData::PlotData()
{
}

/*
PlotData::PlotData( const Plot &plot):
    mPlot( plot)
{
}
*/

PlotData::~PlotData()
{
}

void PlotData::setTimeSpan( const QDate &firstDay, const QDate &lastDay)
{
    mFirstDay = firstDay;
    mLastDay = lastDay;
}

QString PlotData::svgFile() const
{
    QFile       dataFile( QDir::tempPath() + "/atleto_plot.dat");
   if( !dataFile.open(QIODevice::WriteOnly | QIODevice::Text))
        return "";

    QTextStream     dataOut( &dataFile);

    QDate       d1 = mFirstDay;
    QDate       d2;

    if( mPlot.aggregation() == PLOT_AG_DAILY)
        d2 = d1;
    else if( mPlot.aggregation() == PLOT_AG_WEEKLY)
        d2 = d1.addDays( 7 - mFirstDay.dayOfWeek());
    else if( mPlot.aggregation() == PLOT_AG_MONTHLY)
        d2 = QDate( d1.year(), d1.month(), d1.daysInMonth());
    else if( mPlot.aggregation() == PLOT_AG_YEARLY)
        d2 = QDate( d1.year(), 12, 31);

    while( d1 <= mLastDay)
    {
        if( d2 > mLastDay)
            d2 = mLastDay;

        QString     xLabel;
        QString     y1data;
        QString     y2data;

        y1data = yValue( d1, d2, mPlot.y1Data());
        y2data = yValue( d1, d2, mPlot.y2Data());

        QDate       prevDate = d1;
        d1 = d2.addDays( 1);
        if( mPlot.aggregation() == PLOT_AG_DAILY)
        {
            xLabel = prevDate.toString( "MMM dd");
            d2 = d1;
        }
        else if( mPlot.aggregation() == PLOT_AG_WEEKLY)
        {
            xLabel = prevDate.toString( "MMM dd-") + d2.toString( "MMM dd");
            d2 = d1.addDays( 6);
        }
        else if( mPlot.aggregation() == PLOT_AG_MONTHLY)
        {
            xLabel = prevDate.toString( "MMM yyyy");
            d2 = QDate( d1.year(), d1.month(), d1.daysInMonth());
        }
        else if( mPlot.aggregation() == PLOT_AG_YEARLY)
        {
            xLabel = prevDate.toString( "yyyy");
            d2 = QDate( d1.year(), 12, 31);
        }

        dataOut << "\"" << xLabel << "\"   " << y1data << "  " << y2data << "\n";
    }

    dataFile.close();

    QProcess        process;
    QSettings       settings;
    QString         app = settings.value( "Options/gnuplotexecutable").toString();
    QFile           svgFile( QDir::tempPath() + "/atleto_svg.svg");
    QStringList     args;
    GnuPlotCommand  gpc( QDir::tempPath() + "/atleto.gp");

    if( mPlot.y1Data() == PLOT_TYPE_DISTANCE)
    {
        gpc.setTitle( "Run distance [km]");
    }
    else if( mPlot.y1Data() == PLOT_TYPE_WEIGHT)
    {
        gpc.addCommand( "set autoscale\n");
        gpc.setTitle( "Weight [kg]");
    }
    else if( mPlot.y1Data() == PLOT_TYPE_BMI)
    {
        gpc.addCommand( "set autoscale\n");
        gpc.setTitle( "Body Mass Index (BMI)");
    }

    gpc.setSvgFile( svgFile.fileName());
    gpc.setPlotFile( dataFile.fileName());
    gpc.writeToDisk();

    args << gpc.fileName();

    process.start( app, args);
    process.waitForFinished();

    return svgFile.fileName();
}

QString PlotData::yValue( const QDate &day1, const QDate &day2, const int valueType) const
{
    QString     value;

    if( valueType == PLOT_TYPE_NONE)
        value = "";
    else if( valueType == PLOT_TYPE_DISTANCE)
    {
        double      dist = Run::total( day1, day2, "dist");

        RunDistanceString       rs;
        rs.setValue( dist);
        value = rs.text( 0, false);
    }
    else if( valueType == PLOT_TYPE_TIME)
    {
        double      t = Run::total( day1, day2, "t");

        value = QString::number( cGeneral::rnd( t, 0)) + "  " + cTime::t2str( t, false);
    }
    else if( valueType == PLOT_TYPE_PACE)
    {
        double      dist = Run::total( day1, day2, "dist");
        double      t = Run::total( day1, day2, "t");

        RunDistanceString       rs;
        rs.setValue( dist);
        value = rs.pace( t, false);
    }
    else if( valueType == PLOT_TYPE_WEIGHT)
    {
        double      weight = Physical::average( day1, day2, "weight");

        WeightString        ws;
        ws.setValue( weight);
        value = ws.text( 1, false);
    }
    else if( valueType == PLOT_TYPE_BMI)
    {
        Athlete::setAthleteById( 1);
        Athlete     *athlete = Athlete::getInstance();
        double      weight = Physical::average( day1, day2, "weight");
        double      height = athlete->getHeight();

        value = QString::number( cGeneral::bmi( weight, height), 'f', 1);
    }
    else if( valueType == PLOT_TYPE_SHOES)
    {
        value = "";     // TODO
    }

    return value;
}
