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

    QString         defaultPath = settings.value( "Options/csv_defaultpath", QDir::homePath()).toString();

    QString         csvFileName = QFileDialog::getOpenFileName( 0, tr( "Import Garmin CSV file"), defaultPath, tr( "CVS (*.csv)"));
    if( csvFileName.isNull())
        return;

    QFileInfo       csvFile( csvFileName);
    settings.setValue( "Options/csv_defaultpath", csvFile.absolutePath());

    QDir            dbDir;

    QFileInfo            dbFile = settings.value( "Options/dbfilename").toString();
    if( dbFile.exists())
    {
        dbDir = dbFile.absoluteDir();
        if( !dbDir.exists( "csv"))
            dbDir.mkdir( "csv");
        dbDir.cd( "csv");
    }
    else
    {
        QMessageBox::critical( 0, tr( "No Data file found"), tr( "Could not find data file. Check permissions."));

        return;
    }

    QFileInfo       fi( dbDir.absolutePath() + "/" + csvFile.fileName());
    if( !QFile::copy( csvFile.absoluteFilePath(), fi.absoluteFilePath()))
    {
        QMessageBox::critical( 0, tr( "File copy failed"), tr( "Could not copy CSV file. Check permissions."));

        return;
    }

    Run         run;

    run.setDeviceFile( fi.dir().dirName() + "/" + fi.fileName());
    run.setComment( "imported from CSV file");

    loadDeviceData( &run, fi);

    run.save();
}

void CsvImporter::loadDeviceData( Run *run, QFileInfo& fi)
{
    QFile           file( fi.absoluteFilePath());

    if( !file.open( QIODevice::ReadOnly))
    {
        QMessageBox::critical( 0, tr( "CSV open failed"), tr( "Could not open CSV file as read only."));

        return;
    }
}
