// $Id: weathereditor.cpp 294 2010-03-05 18:37:10Z  $
// (c) 2009, Parallel Pixels Ltd.

#include "src/gui/weathereditor.h"
#include "ui_weathereditor.h"

WeatherEditor::WeatherEditor( const QDate &day, const int id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WeatherEditor)
{
    ui->setupUi(this);

    if( id > 0)
    {
        mWeather.restore( id);
    }
    else
    {
        mWeather.restoreByJulianDay( day.toJulianDay());
    }

    setWindowTitle( QDate::fromJulianDay( mWeather.julianDay()).toString( "ddd - MMM d"));

    if( mWeather.id() > 0)
    {
        ui->skyCombo->setCurrentIndex( mWeather.sky());
        ui->tempEdit->setValue( mWeather.temperature());
        ui->tempEdit->displayValue();
        ui->notesEdit->setText( mWeather.notes());
        ui->deleteButton->setEnabled( true);
    }
    else
    {
        ui->deleteButton->setEnabled( false);
    }
}

WeatherEditor::~WeatherEditor()
{
    delete ui;
}

void WeatherEditor::changeEvent(QEvent *e)
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

void WeatherEditor::on_buttonBox_accepted()
{
    mWeather.setSky( ui->skyCombo->currentIndex());
    mWeather.setTemperature( ui->tempEdit->value());
    mWeather.setNotes( ui->notesEdit->text());
    mWeather.save();
}

void WeatherEditor::on_deleteButton_clicked()
{
    if( mWeather.id() > 0)
        mWeather.remove();

    close();
}
