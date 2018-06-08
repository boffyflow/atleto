// $Id: runviewer.cpp 371 2010-12-14 23:25:23Z boffyflow $
// (c) 2010 Parallel Pixels Ltd.

#include <QTableWidget>

#include "runviewer.h"
#include "ui_runviewer.h"
#include "src/gui/runeditor.h"
#include "src/util/rununits.h"
#include "src/util/ctime.h"
#include "src/util/cgeneral.h"
#include "src/plot/plotseries.h"
#include "src/plot/plotgraph.h"

RunViewer::RunViewer( const int run_id, QWidget *parent) :
    QDialog( parent),
    ui( new Ui::RunViewer)
{
    ui->setupUi(this);

    mRunId = run_id;

    mShowPace = true;
    mShowHeartrate = true;

    loadRun();
}

RunViewer::~RunViewer()
{
    delete ui;
}

void RunViewer::loadRun()
{
    mRun.removeAllSplits();
    mRun.restore( mRunId);

    setWindowTitle( QDate::fromJulianDay( mRun.julianDay()).toString( "dddd - MMM d, yyyy"));

    if( mRun.numberOfSplits() == 0)
    {
        reject();
        return;
    }

    if( mRun.aveHeartRate() == 0)
    {
        ui->hrCheckBox->setChecked( false);
        ui->hrCheckBox->setEnabled( false);
    }

    if( mRun.numberOfSplits() < 2)
    {
        ui->paceCheckBox->setChecked( false);
        ui->paceCheckBox->setEnabled( false);
        ui->hrCheckBox->setChecked( false);
        ui->hrCheckBox->setEnabled( false);
    }

    populateTable();
    updateLabels();

    updatePlot();
}

void
RunViewer::populateTable()
{
    ui->inputTable->clear();
    ui->inputTable->setRowCount( mRun.numberOfSplits());

    for( int row = 0; row < mRun.numberOfSplits(); row++)
    {
        Split       *s = mRun.split( row);

        RunDistanceString       rs;

        rs.setValue( s->distance());

        QTableWidgetItem    *distItem = new QTableWidgetItem( rs.text());
        ui->inputTable->setItem( row, 0, distItem);

        QTableWidgetItem    *timeItem = new QTableWidgetItem( cTime::t2str( s->time()));
        ui->inputTable->setItem( row, 1, timeItem);

        QTableWidgetItem    *paceItem = new QTableWidgetItem( rs.pace( s->time()));
        ui->inputTable->setItem( row, 2, paceItem);

        QTableWidgetItem    *hrItem = new QTableWidgetItem( QString::number( s->heartrate()));
        ui->inputTable->setItem( row, 3, hrItem);
    }

    ui->inputTable->resizeColumnsToContents();
    ui->inputTable->resizeRowsToContents();
}

void RunViewer::updateLabels()
{
    QList<QTableWidgetItem *>   selectedItems = ui->inputTable->selectedItems();

    if( selectedItems.count() == 0)
    {
        RunDistanceString       rs;

        rs.setValue( mRun.distance());

        ui->distanceLabel->setText( rs.text());
        ui->timeLabel->setText( cTime::t2str( mRun.total_time()));
        ui->paceLabel->setText( rs.pace( mRun.total_time()));
        ui->aveHrLabel->setText( QString::number( mRun.aveHeartRate()));
        ui->maxHrLabel->setText( QString::number( mRun.maxHeartRate()));
    }
    else
    {
        double      dist = 0;
        double      total_time = 0;
        double      hr = 0;
        int         maxhr = 0;

        for( int i = 0; i < selectedItems.count(); i++)
        {
            if( selectedItems.at( i)->column() == 0)
            {
                Split       *split = mRun.split( selectedItems.at( i)->row());
                dist += split->distance();
                total_time += split->time();
                hr += split->heartrate() * split->time();
                if( split->heartrate() > maxhr)
                    maxhr = split->heartrate();
            }
        }
        hr /= total_time;
        RunDistanceString       rs( dist);

        ui->distanceLabel->setText( rs.text());
        ui->timeLabel->setText( cTime::t2str( total_time));
        ui->paceLabel->setText( rs.pace( total_time));
        ui->aveHrLabel->setText( QString::number( cGeneral::rnd( hr)));
        ui->maxHrLabel->setText( QString::number( maxhr));
    }
}

void RunViewer::on_inputTable_itemSelectionChanged()
{
    updateLabels();
    updatePlot();
}

void RunViewer::updatePlot()
{
    QList<QTableWidgetItem *>   selectedItems = ui->inputTable->selectedItems();

    int     numSelected = selectedItems.count() / ui->inputTable->columnCount();

    if( numSelected == 1)
        return;

    ui->plot->clear();

    PlotSeries      paceData;
    PlotSeries      hrData;

    RunUnits        ru;

    paceData.setUnitStringY( "min/" + ru.current());
    hrData.setUnitStringY( "bpm");

    double          sdist = 0.0;

    if( numSelected == 0)
    {
        for( int i = 0; i < mRun.numberOfSplits(); i++)
        {
            Split                   *s = mRun.split( i);
            RunDistanceString       rs( s->distance());
            sdist += s->distance();
            RunDistanceString       rs2( sdist);

            paceData.addPoint( PlotPoint( rs2.curValue(), rs.paceValue( s->time()), rs2.text(), rs.pace( s->time())));
            hrData.addPoint( PlotPoint( rs2.curValue(), s->heartrate(), rs2.text(), QString::number( s->heartrate()) + " " + hrData.unitStringY()));
        }
    }
    else if( numSelected > 1)
    {
        for( int i = 0; i < selectedItems.count(); i++)
        {
            if( selectedItems.at( i)->column() == 0)
            {
                Split       *s = mRun.split( selectedItems.at( i)->row());

                RunDistanceString       rs( s->distance());
                sdist += s->distance();
                RunDistanceString       rs2( sdist);

                paceData.addPoint( PlotPoint( rs2.curValue(), rs.paceValue( s->time()), rs2.text(), rs.pace( s->time())));
                hrData.addPoint( PlotPoint( rs2.curValue(), s->heartrate(), rs2.text(), QString::number( s->heartrate()) + " " + hrData.unitStringY()));
            }
        }
    }

    if( ui->paceCheckBox->isChecked())
    {
        paceData.computeMinMax();
        paceData.setZeroBased( false);
        paceData.setUnits( PLOT_UNIT_DISTANCE, PLOT_UNIT_PACE);
        paceData.setColor( Qt::blue);
        PlotGraph       *paceGraph = new PlotGraph( paceData);
        paceGraph->setGraphType( PLOT_GRAPH_LINE);

        ui->plot->addGraph( paceGraph);
    }

    if( ui->hrCheckBox->isChecked())
    {
        hrData.computeMinMax();
        hrData.setZeroBased( false);
        hrData.setUnits( PLOT_UNIT_DISTANCE, PLOT_UNIT_BPM);
        hrData.setColor( Qt::red);
        PlotGraph       *hrGraph = new PlotGraph( hrData);
        hrGraph->setGraphType( PLOT_GRAPH_LINE);

        ui->plot->addGraph( hrGraph);
    }

//    if( ui->paceCheckBox->isChecked() || ui->hrCheckBox->isChecked())
    {
        ui->plot->setTitle( tr( "Pace and Heartrate"));
        ui->plot->draw();
    }
}

void RunViewer::on_editRunButton_clicked()
{
    RunEditor       re( QDate::currentDate(), mRun.id(), this);

    if( re.exec() == QDialog::Accepted)
        loadRun();
}

void RunViewer::on_paceCheckBox_clicked()
{
    updatePlot();
}

void RunViewer::on_hrCheckBox_clicked()
{
    updatePlot();
}
