// $Id: raceinfodialog.cpp 214 2009-05-28 17:44:45Z robert $
// (c) 2009, Parallel Pixels Ltd.

#include "raceinfodialog.h"
#include "ui_raceinfodialog.h"

#include "src/util/cgeneral.h"
#include "src/data/data.h"

using namespace atleto;

RaceInfoDialog::RaceInfoDialog( QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::RaceInfoDialog)
{
    m_ui->setupUi(this);

    m_ui->divNumLineEdit->setValidator( new QIntValidator( 1, 1000000, m_ui->divNumLineEdit));
    m_ui->divPlaceLineEdit->setValidator( new QIntValidator( 1, 1000000, m_ui->divPlaceLineEdit));
    m_ui->overallNumLineEdit->setValidator( new QIntValidator( 1, 1000000, m_ui->overallNumLineEdit));
    m_ui->overallPlaceLineEdit->setValidator( new QIntValidator( 1, 1000000, m_ui->overallPlaceLineEdit));

    Data		data;

    // division names
    QStringList		strings;
    QList<int>      ids;

    data.list( "run_divisions", strings, ids);
    for( int i = 0; i < strings.size(); i++)
        m_ui->divComboBox->addItem( strings[i], ids[i]);

    connect( m_ui->buttonBox, SIGNAL( accepted()), this, SLOT( storeRace()));
    connect( m_ui->overallNumLineEdit, SIGNAL( textChanged( const QString &)), this, SLOT( updatePercentages()));
    connect( m_ui->divNumLineEdit, SIGNAL( textChanged( const QString &)), this, SLOT( updatePercentages()));
    connect( m_ui->overallPlaceLineEdit, SIGNAL( textChanged( const QString &)), this, SLOT( updatePercentages()));
    connect( m_ui->divPlaceLineEdit, SIGNAL( textChanged( const QString &)), this, SLOT( updatePercentages()));
}

RaceInfoDialog::~RaceInfoDialog()
{
    delete m_ui;
}

void RaceInfoDialog::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void RaceInfoDialog::storeRace()
{
    mRunRace.setBib( m_ui->bibLineEdit->text());
    mRunRace.setRaceName( m_ui->raceNameLineEdit->text());
    mRunRace.setDivisionName( m_ui->divComboBox->currentText());
    mRunRace.setPlaceOverall( m_ui->overallPlaceLineEdit->text().toInt());
    mRunRace.setNumOverall( m_ui->overallNumLineEdit->text().toInt());
    mRunRace.setPlaceDivision( m_ui->divPlaceLineEdit->text().toInt());
    mRunRace.setNumDivision( m_ui->divNumLineEdit->text().toInt());

    QTime		gt = m_ui->gunTimeEdit->time();
    QTime		ct = m_ui->chipTimeEdit->time();
    mRunRace.setGuntime( gt.second() + gt.minute() * 60 + gt.hour() * 3600);
    mRunRace.setChiptime( ct.second() + ct.minute() * 60 + ct.hour() * 3600);
}

void RaceInfoDialog::setRunRace( const RunRace &runRace)
{
    mRunRace = runRace;

    m_ui->bibLineEdit->setText( mRunRace.bib());
    m_ui->raceNameLineEdit->setText( mRunRace.raceName());
    m_ui->divComboBox->setCurrentIndex( m_ui->divComboBox->findText( mRunRace.divisionName()));
    m_ui->overallPlaceLineEdit->setText( QString::number( mRunRace.place_overall()));
    m_ui->overallNumLineEdit->setText( QString::number( mRunRace.num_overall()));
    m_ui->divPlaceLineEdit->setText( QString::number( mRunRace.place_division()));
    m_ui->divNumLineEdit->setText( QString::number( mRunRace.num_division()));
    m_ui->gunTimeEdit->setTime( QTime( 0, 0, 0).addSecs( mRunRace.guntime()));
    m_ui->chipTimeEdit->setTime( QTime( 0, 0, 0).addSecs( mRunRace.chiptime()));
}

void RaceInfoDialog::updatePercentages()
{
    double   divPer = m_ui->divPlaceLineEdit->text().toDouble() * 100.0 / m_ui->divNumLineEdit->text().toDouble();
    double   overallPer = m_ui->overallPlaceLineEdit->text().toDouble() * 100.0 / m_ui->overallNumLineEdit->text().toDouble();

    m_ui->divisionPercentLabel->setText( "top " + QString::number( cGeneral::rnd( divPer, 1)) + "%");
    m_ui->overallPercentLabel->setText( "top " + QString::number( cGeneral::rnd( overallPer, 1)) + "%");
}

