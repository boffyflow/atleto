// (c) 2009 Parallel Pixels Ltd.
// $Id: gnuplotcommand.h 361 2010-05-27 00:05:54Z boffyflow $

#ifndef GNUPLOTCOMMAND_H
#define GNUPLOTCOMMAND_H

#include <QObject>

class GnuPlotCommand : public QObject
{
    Q_OBJECT

public:

    GnuPlotCommand( const QString &fileName);

    void        setFileName( const QString &fileName) { mFileName = fileName;};
    void        writeToDisk();

    void        addCommand( const QString &command) { mCommand += command;};
    void        setTitle( const QString &title) { mCommand += "set title \"" + title + "\"\n";};
    void        setPlotFile( const QString &plotFile) { mPlotFile = plotFile;};
    void        setSvgFile(  const QString &svgFile) { mSvgFile = svgFile;};

    QString     fileName() const { return mFileName;};

signals:

public slots:

private:

    QString         mCommand;
    QString         mPlotFile;
    QString         mSvgFile;
    QString         mFileName;
};

#endif // GNUPLOTCOMMAND_H
