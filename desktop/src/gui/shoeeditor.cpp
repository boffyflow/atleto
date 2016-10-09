// (c) 2009 Parallel Pixels Ltd.
// $Id: shoeeditor.cpp 369 2010-09-25 00:02:33Z boffyflow $

#include "shoeeditor.h"
#include "ui_shoeeditor.h"

#include <QList>

#include "src/data/shoe.h"
#include "src/util/rununits.h"

ShoeEditor::ShoeEditor( QWidget *parent, const int id) :
    QDialog(parent),
    ui(new Ui::ShoeEditor)
{
    ui->setupUi(this);
    mShoeId = id;
    loadShoe();
    ui->endUse->setEnabled( !ui->activeBox->isChecked());
}

ShoeEditor::~ShoeEditor()
{
    delete ui;
}

void ShoeEditor::loadShoe()
{
    if( mShoeId < 0)
    {
        ui->shoeName->setText( "New Shoe");
        ui->startUse->setDate( QDate::currentDate());
    }
    else
    {
        Shoe        s( mShoeId);

        QDate       d = s.useEnd();
        if( d.toJulianDay() == 0)
            d = QDate::currentDate();

        ui->shoeName->setText( s.name());
        ui->shoeBrand->setText( s.brand());
        ui->shoeModel->setText( s.model());
        ui->shoeSize->setText( s.size());
        ui->shoeNotes->setText( s.notes());
        ui->startUse->setDate( s.useStart());
        ui->endUse->setDate( d);
        ui->activeBox->setChecked( s.active());
        ui->startMileage->setValue( (double ) s.startMileage());
        ui->startMileage->displayValue( 0);
        ui->maxMileage->setValue( (double ) s.maxMileage());
        ui->maxMileage->displayValue( 0);
    }
}

void ShoeEditor::saveShoe()
{
    Shoe        s;

    s.setName( ui->shoeName->text());
    s.setBrand( ui->shoeBrand->text());
    s.setModel( ui->shoeModel->text());
    s.setSize( ui->shoeSize->text());
    s.setNotes( ui->shoeNotes->text());
    s.setUseStart( ui->startUse->date());
    s.setActive( ui->activeBox->isChecked());

    if( s.active())
        s.setUseEnd( QDate::fromJulianDay( 0));
    else
        s.setUseEnd( ui->endUse->date());

    s.setStartMileage( ui->startMileage->value());
    s.setMaxMileage( ui->maxMileage->value());

    mShoeId = s.save( mShoeId);
}

void ShoeEditor::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void ShoeEditor::on_buttonBox_accepted()
{
    saveShoe();
}

void ShoeEditor::on_activeBox_clicked(bool checked)
{
    ui->endUse->setEnabled( !checked);
}
