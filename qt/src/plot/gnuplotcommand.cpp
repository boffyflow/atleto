// (c) 2009 Parallel Pixels Ltd.
// $Id: gnuplotcommand.cpp 361 2010-05-27 00:05:54Z boffyflow $

#include "src/plot/gnuplotcommand.h"

#include <QFile>
#include <QTextStream>
#include <QDate>

GnuPlotCommand::GnuPlotCommand( const QString &fileName) :
    mFileName( fileName)
{
    mCommand += "# gnuplot settings file created by Atleto\n";
    mCommand += "# on " + QDate::currentDate().toString( Qt::ISODate) + "\n#\n";
    mCommand += "set terminal svg\n";
    mCommand += "set border 3\n";
    mCommand += "set boxwidth 2 absolute\n";
    mCommand += "set style fill solid 0.5 border\n";
    mCommand += "set style histogram clustered gap 2.75 title offset character 0, 0, 0\n";
    mCommand += "set style data histograms\n";
    mCommand += "set ticslevel 0.5\n";
    mCommand += "set xtics border out scale 0.0,0.0 nomirror rotate by -45 offset character 0, 0, 0\n";
    mCommand += "set ytics border in scale 0.0,0.5 nomirror norotate  offset character 0, 0, 0\n";
    mCommand += "set key off\n";
    mCommand += "set grid ytics\n";
    mCommand += "set yrange [0:*]\n";
}

void GnuPlotCommand::writeToDisk()
{
    mCommand += "set output '" + mSvgFile + "'\n";
    mCommand += "plot '" + mPlotFile + "' u 2:xticlabel(1), '' u 0:2:3 with labels center offset 1.5,0.5\n";

    QFile       f( mFileName);

    if( !f.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream     dataOut( &f);

    dataOut << mCommand;

    dataOut.flush();

    f.close();
}
