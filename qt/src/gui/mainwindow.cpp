// (c) 2009 Parallel Pixels Ltd.
// $Id: mainwindow.cpp 372 2013-03-05 22:04:13Z boffyflow $

#include <QSettings>
#include <QSqlDatabase>
#include <QLabel>
#include <QDir>
#include <QDebug>
#include <QFileInfoList>

#include "src/data/data.h"
#include "src/gui/runtools.h"
#include "src/gui/shoelist.h"
#include "mainwindow.h"
#include "athleteselector.h"
#include "ui_mainwindow.h"
#include "src/gui/aboutatleto.h"
#include "src/data/athlete.h"
#include "src/gui/atletooptions.h"
#include "src/util/tcximporter.h"
#include "src/util/csvimporter.h"

//testing
#include "src/plot/ploteditor.h"

using namespace atleto;

MainWindow *MainWindow::mInstance = NULL;

MainWindow::MainWindow( QWidget *parent)
    : QMainWindow(parent), ui( new Ui::MainWindowClass)
{
    MainWindow::mInstance = this;

    // open database connection
    openConnection();

    ui->setupUi(this);
    statusBar()->addWidget( new QLabel( ""));

    Data        data;

    Athlete::setAthleteById( data.activeAthlete());

    updateStatus();

    // read ui settings
    readSettings();

    // read in graph templates
    readGraphTemplates();
}

MainWindow::~MainWindow()
{
    closeConnection();

    writeSettings();
    delete ui;
}

void MainWindow::writeSettings()
{
    Data      data;
    QSettings settings;

    settings.beginGroup( "MainWindow");
    settings.setValue( "geometry", saveGeometry());
    settings.setValue( "state", saveState());
//    settings.setValue( "currentTab", ui->mainContent->currentIndex());
    settings.endGroup();

    settings.beginGroup( "Data");
    settings.setValue( "active_athlete", data.activeAthlete());
    settings.endGroup();
}

void MainWindow::readSettings()
{
    QSettings   settings;

    settings.beginGroup( "MainWindow");
    restoreState( settings.value( "state").toByteArray());
    restoreGeometry( settings.value( "geometry").toByteArray());

    ui->actionCalendar->trigger();

    settings.endGroup();
}

void MainWindow::readGraphTemplates()
{
    QStringList apt_filter;
    apt_filter << "*.atp";

    // TODO
    //    QStringList     apt_files = QDir( QCoreApplication::applicationDirPath() + "/apt").entryList( apt_filter);
    QFileInfoList     apt_files = QDir( "C:/Users/robert.uebbing/Desktop/scratch/plot").entryInfoList( apt_filter);

    for( int i = 0; i < apt_files.size(); i++)
    {
        QFile       f( apt_files.at( i).absoluteFilePath());
        if( f.open( QIODevice::ReadOnly | QIODevice::Text))
        {
            QString     name = f.readLine().trimmed();
            mGraphTemplates.insert(name, apt_files.at( i).absoluteFilePath());
        }
    }

    qDebug() << mGraphTemplates.keys();
    qDebug() << mGraphTemplates.values();
}

void MainWindow::openConnection()
{
    QSettings   settings;
    Data        data;

    settings.beginGroup( "Options");
    mDBName = settings.value( "dbfilename").toString();
    settings.endGroup();

    settings.beginGroup( "Data");
    data.setActiveAthlete( settings.value( "active_athlete").toInt());
    settings.endGroup();

    QSqlDatabase		db = QSqlDatabase::addDatabase( "QSQLITE");
    db.setDatabaseName( mDBName);
    db.open();
}

void MainWindow::closeConnection()
{
    QSqlDatabase::database().close();
    QSqlDatabase::removeDatabase( mDBName);
}

//++++++++++++++ SLOTS ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void MainWindow::on_actionAbout_Qt_triggered()
{
    qApp->aboutQt();
}

void MainWindow::on_actionQuit_triggered()
{
    qApp->exit( 0);
}

void MainWindow::on_actionCalendar_triggered( bool state)
{
    if( state)
    {
        ui->actionReport_Generator->setChecked( !state);
        ui->actionSearch_Run->setChecked( !state);
        ui->actionRaces->setChecked( !state);
        ui->mainContent->setCurrentIndex( 0);
    }
    else
    {
        ui->actionCalendar->setChecked( !state);
    }
}

void MainWindow::on_actionReport_Generator_triggered( bool state)
{
    if( state)
    {
        ui->actionCalendar->setChecked( !state);
        ui->actionSearch_Run->setChecked( !state);
        ui->actionRaces->setChecked( !state);
        ui->mainContent->setCurrentIndex( 1);
    }
    else
    {
        ui->actionReport_Generator->setChecked( !state);
    }
}

void MainWindow::on_actionSearch_Run_triggered( bool state)
{
    if( state)
    {
        ui->actionCalendar->setChecked( !state);
        ui->actionReport_Generator->setChecked( !state);
        ui->actionRaces->setChecked( !state);
        ui->mainContent->setCurrentIndex( 2);
    }
    else
    {
        ui->actionSearch_Run->setChecked( !state);
    }
}

void MainWindow::on_actionRaces_triggered( bool state)
{
    if( state)
    {
        ui->actionCalendar->setChecked( !state);
        ui->actionReport_Generator->setChecked( !state);
        ui->actionSearch_Run->setChecked( !state);
        ui->mainContent->setCurrentIndex( 3);
    }
    else
    {
        ui->actionRaces->setChecked( !state);
    }
}

void MainWindow::on_actionAthlete_triggered()
{
    AthleteSelector     as( this);
    as.exec();
}

void MainWindow::on_actionRun_Calculator_triggered()
{
    RunTools        *toolsDialog = new RunTools( this);

    toolsDialog->show();
}

void MainWindow::on_actionShoes_triggered()
{
    ShoeList      *shoeList = new ShoeList( this);

    shoeList->show();
}

void MainWindow::on_actionAbout_Atleto_triggered()
{
    AboutAtleto         about;

    about.exec();
}



void MainWindow::on_actionOptions_triggered()
{
    AtletoOptions       ao( this);

    if( ao.exec() == QDialog::Accepted)
    {
        if( ui->mainContent->currentIndex() == 0)
        {
            ((CalendarWidget *) ui->mainContent->currentWidget())->updateContent();
        }
    }
}

void MainWindow::updateStatus()
{
    Data        data;

    QString     message =  QString( "%1 runs stored in database. ").arg( QString::number( data.num( "runs")));

    statusBar()->showMessage( message);
}

void MainWindow::on_actionImport_TCX_triggered()
{
    TcxImporter         tcx;

    tcx.run();

    if( ui->mainContent->currentIndex() == 0)
    {
        ((CalendarWidget *) ui->mainContent->currentWidget())->updateContent();
    }

    updateStatus();
}

void MainWindow::on_actionImport_CSV_triggered()
{
    CsvImporter         csv;

    csv.run();

    if( ui->mainContent->currentIndex() == 0)
    {
        ((CalendarWidget *) ui->mainContent->currentWidget())->updateContent();
    }

    updateStatus();
}

void MainWindow::on_actionPlotTest_triggered()
{
    PlotEditor      pe;

    pe.exec();
}

void MainWindow::on_actionPublish_triggered()
{
    qDebug() << mDBName;
}

