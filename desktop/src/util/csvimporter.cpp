// $Id: CsvImporter.cpp 370 2010-12-14 23:23:50Z boffyflow $
// (c) 2006, Parallel Pixels Ltd.

#include "src/util/CsvImporter.h"
#include "src/data/run.h"
#include "src/data/split.h"

#include <ostream>

#include <QFileDialog>
#include <QFileInfo>
#include <QSettings>
#include <QMessageBox>
#include <QDomDocument>
#include <QtDebug>

CsvImporter::CsvImporter()
{
}

void CsvImporter::run()
{
    QSettings       settings;

    QString         defaultPath = settings.value( "Options/tcx_defaultpath", QDir::homePath()).toString();

    QString         tcxFileName = QFileDialog::getOpenFileName( 0, tr( "Import Garmin TCX file"), defaultPath, tr( "TCX (*.tcx)"));
    if( tcxFileName.isNull())
        return;

    QFileInfo       tcxFile( tcxFileName);
    settings.setValue( "Options/tcx_defaultpath", tcxFile.absolutePath());

    QDir            dbDir;

    QFileInfo            dbFile = settings.value( "Options/dbfilename").toString();
    if( dbFile.exists())
    {
        dbDir = dbFile.absoluteDir();
        if( !dbDir.exists( "tcx"))
            dbDir.mkdir( "tcx");
        dbDir.cd( "tcx");
    }
    else
    {
        QMessageBox::critical( 0, tr( "No Data file found"), tr( "Could not find data file. Check permissions."));

        return;
    }

    QFileInfo       fi( dbDir.absolutePath() + "/" + tcxFile.fileName());
    if( !QFile::copy( tcxFile.absoluteFilePath(), fi.absoluteFilePath()))
    {
        QMessageBox::critical( 0, tr( "File copy failed"), tr( "Could not copy TCX file. Check permissions."));

        return;
    }

    Run         run;

    run.setDeviceFile( fi.dir().dirName() + "/" + fi.fileName());
    run.setComment( "imported from TCX file");

    loadDeviceData( &run, fi);

    run.save();
}

void CsvImporter::loadDeviceData( Run *run, QFileInfo& fi)
{
    QDomDocument    doc( "tcx");
    QFile           file( fi.absoluteFilePath());

    if( !file.open( QIODevice::ReadOnly))
    {
        QMessageBox::critical( 0, tr( "CSV open failed"), tr( "Could not open CSV file as read only."));

        return;
    }
    if( !doc.setContent( &file))
    {
        file.close();
        QMessageBox::critical( 0, tr( "CSV read failed"), tr( "Could not read or parse CSV file."));

        return;
    }
    file.close();

    QDomNodeList    lapList = doc.elementsByTagName( "Lap");

    for( int i = 0; i < lapList.count(); i++)
    {
        QDomElement     e = lapList.at( i).toElement();
        if( !e.isNull())
        {
            if( i == 0)
            {
                QDateTime       day = QDateTime::fromString( e.attribute( "StartTime"), Qt::ISODate);
                day = day.toLocalTime();
                run->setStartTime( day.time());
                run->setEndTime( day.time().addSecs( 3600));
                run->setJulianDay( day.date().toJulianDay());
            }

            QDomNodeList        lapNodes = e.childNodes();

            Split       *split = new Split();

            for( int j = 0; j < lapNodes.count(); j++)
            {
                QDomElement     lapNode = lapNodes.at( j).toElement();
                if( !lapNode.isNull())
                {
                    if( lapNode.tagName().compare( "TotalTimeSeconds") == 0)
                    {
                       split->setTime( lapNode.text().toFloat());
                    }
                    if( lapNode.tagName().compare( "DistanceMeters") == 0)
                    {
                        split->setDistance( lapNode.text().toFloat());
                    }
                    if( lapNode.tagName().compare( "AverageHeartRateBpm") == 0)
                    {
                        QDomElement     hrValueNode = lapNode.firstChildElement( "Value");
                        if( !hrValueNode.isNull())
                        {
                            split->setHeartRate( hrValueNode.text().toInt());
                        }
                    }
                }
            }

            if( i == lapList.count() - 1)
            {
                QDateTime       day = QDateTime::fromString( e.attribute( "StartTime"), Qt::ISODate);
                day = day.toLocalTime();
                run->setEndTime( day.time().addSecs( split->time()));
            }

            if( split->distance() > CSV_MIN_SPLIT_DISTANCE)     // only add splits that are longer than TCX_MIN_SPLIT_DISTANCE
                run->addSplit( split);
        }
    }
}
