
// (c) 2010 Parallel Pixels Ltd.
// $Id: runtools.cpp 342 2010-03-25 09:13:13Z nebanch $

#include "runtools.h"
#include "ui_runtools.h"

#include <QStringList>
#include <QTableWidgetItem>
#include <math.h>

#include "src/data/pacezone.h"
#include "src/util/ctime.h"
#include "src/util/cgeneral.h"
#include "src/data/runrace.h"

RunTools::RunTools(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::RunTools)
{
    m_ui->setupUi(this);

    mUnits.setBase( "km");
    mUnits.setCurrent( "km");

    m_ui->inputDistanceLineEdit->setValue( 10000.0);
    m_ui->inputDistanceLineEdit->displayValue();

    for( int i = 0; i < RunRace_Open; i++)
    {
        m_ui->outputDistanceCombo->addItem( raceDistanceStrings[i], raceDistances[i]);
    }
    m_ui->outputDistanceCombo->setCurrentIndex( 9);

    updatePredictor();

    updatePziTable();
}

RunTools::~RunTools()
{
    delete m_ui;
}

void RunTools::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void RunTools::on_inputTimeEdit_dateTimeChanged( QDateTime inputTime)
{
    mInputTime = inputTime.time().hour() * 3600 + inputTime.time().minute() * 60 + inputTime.time().second();
}

void RunTools::on_unitsComboBox_currentIndexChanged( QString units)
{
    mUnits.setBase( units);
}

void RunTools::on_raceCombo_activated( int index)
{
    updatePziTable();
}

void RunTools::on_raceTime_editingFinished()
{
    updatePziTable();

}

void RunTools::updatePredictor()
{
    RunDistanceString   rs;
    rs.setValue( m_ui->inputDistanceLineEdit->value());

    float       secs = m_ui->inputTimeEdit->time().hour() * 3600.0 + m_ui->inputTimeEdit->time().minute() * 60.0 + m_ui->inputTimeEdit->time().second();

    m_ui->inputPaceLabel->setText( rs.pace( secs));
    m_ui->inputSpeedLabel->setText( rs.speed( secs));

    float       outputDist = m_ui->outputDistanceCombo->itemData( m_ui->outputDistanceCombo->currentIndex()).toDouble();
    float       outputTime = secs * pow( ( outputDist / rs.value()), 1.06);

    m_ui->outputTimeLabel->setText( cTime::t2str( outputTime));
    rs.setValue( outputDist);
    m_ui->outputPaceLabel->setText( rs.pace( outputTime));

/*
    QTime    time = teTime->time();
       double   d1 = _rununits.currentToBase( leDistance->text().toDouble());
       double   d2 = raceDistances[index];
       double   t1 = time.second() + time.minute() * 60 + time.hour() * 3600;

       int      t2 = cGeneral::rnd( t1 * pow( ( d2 / d1), 1.06));     // equation from Runner's World

       labelFinishTime->setText( cTime::t2str( t2));

       double    pd = _rununits.baseToCurrent( d2);

       labelPredictedPace->setText( cTime::t2str( cGeneral::rnd( (double ) t2 / pd), false) +
                                  " min/" + _rununits.current());
*/
}

void RunTools::updatePziTable()
{
    int     raceIndex = m_ui->raceCombo->currentIndex();
    float   distance = 0.0;

    if( raceIndex == 0)
        distance = 3000.0;
    else if( raceIndex == 1)
        distance = 5000.0;
    else if( raceIndex == 2)
        distance = 10000.0;

    float   secs =  m_ui->raceTime->time().hour() * 3600.0 +  m_ui->raceTime->time().minute() * 60.0 +  m_ui->raceTime->time().second();

    QStringList     pList = PaceZone::zones( raceIndex, secs);

    if( pList.count() != 0)
    {
        m_ui->paceZoneIndex->setText( pList.at( 0));
        m_ui->vdotLabel->setText( QString::number( cGeneral::rnd( cGeneral::vdot( distance, secs), 1)));

        for( int i = 1; i < pList.count(); i++)
        {
            QString         str = pList.at( i);
            QStringList     strings = str.split( ",");
            RunDistanceString       rs;
            rs.setValue( 1000.0);
            QString         paceRange;

            QTableWidgetItem  *nameItem = new QTableWidgetItem( strings.at( 0));
            m_ui->tableWidget->setItem( i - 1, 0, nameItem);

            secs = strings.at( 1).toFloat();
            paceRange.append( rs.pace( secs, false) + " - ");
            secs = strings.at( 2).toFloat();
            paceRange.append( rs.pace( secs));

            QTableWidgetItem  *paceItem = new QTableWidgetItem( paceRange);
            m_ui->tableWidget->setItem( i - 1, 1, paceItem);
        }

        m_ui->tableWidget->resizeColumnsToContents();
    }
}

void RunTools::on_raceTime_timeChanged(QTime date)
{
    updatePziTable();
}

void RunTools::on_inputDistanceLineEdit_editingFinished()
{
    updatePredictor();
}

void RunTools::on_inputTimeEdit_timeChanged( QTime date)
{
    updatePredictor();
}

void RunTools::on_outputDistanceCombo_activated(QString )
{
    updatePredictor();
}
