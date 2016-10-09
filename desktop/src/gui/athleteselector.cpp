// (c) 2009 Parallel Pixels Ltd.
// $Id: athleteselector.cpp 321 2010-03-16 01:09:07Z boffyflow $

#include "athleteselector.h"
#include "src/data/data.h"
#include "src/data/athlete.h"
#include "ui_athleteselector.h"

#include <QtDebug>

using namespace atleto;

AthleteSelector::AthleteSelector(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::AthleteSelector)
{
    m_ui->setupUi(this);

    Data        data;

    QStringList     athleteList, idList;

    data.athleteList( athleteList, idList);
    m_ui->athleteComboBox->addItems( athleteList);

    Athlete *athlete = Athlete::getInstance();
    int index = m_ui->athleteComboBox->findText(athlete->getName());
    m_ui->athleteComboBox->setCurrentIndex(index);

    isEdit = false;
    isNewAthlete = false;

    connect( m_ui->athleteComboBox, SIGNAL( currentIndexChanged(int)), this, SLOT( athleteChange()));
    connect( m_ui->newButton, SIGNAL( clicked()), this, SLOT( newAthlete()));
    connect( m_ui->buttonBox, SIGNAL( accepted()), this, SLOT( saveChangesAndQuit()));

    connect( m_ui->editName, SIGNAL ( textEdited(QString)), this, SLOT( athleteWasEdit()) );
    connect( m_ui->editDoB, SIGNAL ( dateChanged(QDate)), this, SLOT( athleteWasEdit()) );
    connect( m_ui->boxGender, SIGNAL ( currentIndexChanged(int)), this, SLOT( athleteWasEdit()) );
    connect( m_ui->boxHeight, SIGNAL ( valueChanged(double)), this, SLOT( athleteWasEdit()) );

    athleteChange();
}

AthleteSelector::~AthleteSelector()
{
    delete m_ui;
}

void AthleteSelector::athleteWasEdit()
{
    isEdit = true;
}

void AthleteSelector::saveChanges()
{
    // no changes
    if (isNewAthlete && !isEdit) return;

    Athlete *athlete = Athlete::getInstance();
    athlete->setName( m_ui->editName->text() );
    athlete->setHeight( m_ui->boxHeight->value() );
    athlete->setDoB( m_ui->editDoB->date() );
    athlete->setGender( m_ui->boxGender->currentText().operator ==("male") ? true : false );

    // new Athlete
    if(isNewAthlete) {
        Athlete::insertNewAthlete();
    }
    else {
        Athlete::saveAthlete();
    }
    isEdit = false;
    isNewAthlete = false;
}

void AthleteSelector::saveChangesAndQuit()
{
    // new Athlete was clicked, but changes were made
    if(isNewAthlete && !isEdit) Athlete::setAthleteById( lastKnownId );

    saveChanges();
    accept();
}

void AthleteSelector::newAthlete()
{
    lastKnownId = Athlete::getInstance()->getId();
    Athlete::newAthlete();
    int index = m_ui->athleteComboBox->count();
    m_ui->athleteComboBox->insertItem( index + 1, "new Athlete" );
    m_ui->athleteComboBox->setCurrentIndex( index );
    isNewAthlete = true;
    isEdit = false;
    // athleteChange()
    // will be called due to indexChange Signal
}

void AthleteSelector::athleteChange()
{
    if(isEdit) saveChanges();
    Athlete::setAthleteByName( m_ui->athleteComboBox->currentText() );
    Athlete *athlete = Athlete::getInstance();

    m_ui->editName->setText(athlete->getName());
    m_ui->boxHeight->setValue(athlete->getHeight());
    m_ui->boxHeight->displayValue( 2);
    m_ui->editDoB->setDate(athlete->getDoB());
    m_ui->boxGender->setCurrentIndex( athlete->isMale() ? 0 : 1 );

    isEdit = false;
}

void AthleteSelector::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
