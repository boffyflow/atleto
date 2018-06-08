// (c) 2009 Parallel Pixels Ltd.
// $Id: raceswidget.cpp 372 2013-03-05 22:04:13Z boffyflow $

#include "raceswidget.h"
#include "ui_raceswidget.h"

#include <QTableWidgetItem>
#include <QDebug>

#include "src/data/run.h"
#include "src/data/runrace.h"
#include "src/util/rununits.h"
#include "src/util/ctime.h"
#include "src/gui/runviewer.h"

RacesWidget::RacesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RacesWidget)
{
    ui->setupUi(this);
    ui->gunTimeCheckBox->hide();

    ui->distanceCombo->addItem( "All");
    for( int i = 0; i < RunRace_Open; i++)
    {
        ui->distanceCombo->addItem( raceDistanceStrings[i], raceDistances[i]);
    }

    updateYears();
}

RacesWidget::~RacesWidget()
{
    delete ui;
}

void RacesWidget::changeEvent(QEvent *e)
{
    QWidget::changeEvent( e);
    switch( e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void RacesWidget::updateYears()
{
    ui->yearCombo->clear();

    ui->yearCombo->addItem( "All");
    QList<int>      years = Run::years();

    for( int i = 0; i < years.count(); i++)
    {
        ui->yearCombo->insertItem( 1, QString::number( years.at( i)), years.at( i));
    }

    rebuildTable();
}

void RacesWidget::rebuildTable()
{
    ui->racesTable->clearContents();
    ui->racesTable->setRowCount( 0);

    QDate           firstDay = QDate( 1900, 1, 1);
    QDate           lastDay = QDate::currentDate();

    if( ui->yearCombo->currentIndex() > 0)
    {
        int         y = ui->yearCombo->itemData( ui->yearCombo->currentIndex()).toInt();
        firstDay.setDate( y, 1, 1);
        lastDay.setDate( y, 12, 31);
    }

    QTime   t;
    t.start();
    QList<RunRace>      raceList = RunRace::raceList( firstDay, lastDay);
    qDebug() << "time to load race list: " << t.restart() * 0.001;

    float       minRaceLength = 0.0;
    float       maxRacLength = 1000000.0;   // 1000 km
    if( ui->distanceCombo->currentIndex() > 0)
    {
        minRaceLength = raceDistances[ui->distanceCombo->currentIndex() - 1] - 100.0;
        maxRacLength = raceDistances[ui->distanceCombo->currentIndex() - 1] + 100.0;
    }

    int     row = 0;

    ui->racesTable->setSortingEnabled( false);
    for( int i = 0; i < raceList.count(); i++)
    {
        RunRace             race = raceList.at( i);
        Run                 run( race.run_id());
        RunDistanceString   rs;
        rs.setValue( run.distance());

        if( run.distance() > minRaceLength && run.distance() < maxRacLength)
        {
            ui->racesTable->insertRow( row);

            QTableWidgetItem *date_item = new QTableWidgetItem( QDate::fromJulianDay( run.julianDay()).toString( "yyyy-MM-dd"));
            date_item->setData( Qt::UserRole, run.id());
            ui->racesTable->setItem( row, 0, date_item);

            QTableWidgetItem *dist_item = new QTableWidgetItem( rs.text( 1));
            dist_item->setData( Qt::UserRole, run.id());
            ui->racesTable->setItem( row, 1, dist_item);

            QTableWidgetItem *loc_item = new QTableWidgetItem( race.raceName());
            loc_item->setData( Qt::UserRole, run.id());
            loc_item->setToolTip( run.location());
            ui->racesTable->setItem( row, 2, loc_item);

            QTableWidgetItem *time_item = new QTableWidgetItem( cTime::t2str( run.total_time()));
            time_item->setData( Qt::UserRole, run.id());
            ui->racesTable->setItem( row, 3, time_item);

            QTableWidgetItem *pace_item = new QTableWidgetItem( rs.pace( run.total_time()));
            pace_item->setData( Qt::UserRole, run.id());
            ui->racesTable->setItem( row, 4, pace_item);

            QTableWidgetItem *overall_item = new QTableWidgetItem( QString::number( race.place_overall()) + "/" + QString::number( race.num_overall()));
            overall_item->setData( Qt::UserRole, run.id());
            ui->racesTable->setItem( row, 5, overall_item);

            QTableWidgetItem *div_item = new QTableWidgetItem( QString::number( race.place_division()) + "/" + QString::number( race.num_division()));
            div_item->setData( Qt::UserRole, run.id());
            ui->racesTable->setItem( row, 6, div_item);

            QTableWidgetItem *bib_item = new QTableWidgetItem( race.bib());
            bib_item->setData( Qt::UserRole, run.id());
            ui->racesTable->setItem( row, 7, bib_item);

            QTableWidgetItem *comment_item = new QTableWidgetItem( run.comment());
            comment_item->setData( Qt::UserRole, run.id());
            ui->racesTable->setItem( row, 8, comment_item);

            row++;
        }        
    }
    qDebug() << "time to build table: " << t.elapsed() * 0.001;
    ui->racesTable->setSortingEnabled( true);

    ui->racesTable->sortItems( 0);
    ui->racesTable->resizeRowsToContents();
    ui->racesTable->resizeColumnsToContents();
}

void RacesWidget::on_distanceCombo_activated( QString )
{
    rebuildTable();
}

void RacesWidget::on_yearCombo_activated(QString )
{
    rebuildTable();
}

void RacesWidget::on_pbCheckBox_toggled( bool checked)
{
    rebuildTable();
}

void RacesWidget::on_gunTimeCheckBox_toggled( bool checked)
{
    rebuildTable();
}

void RacesWidget::on_racesTable_itemDoubleClicked( QTableWidgetItem* item)
{
    int     id = item->data( Qt::UserRole).toInt();

    RunViewer           *re = new RunViewer( id, this);

    re->show();
}
