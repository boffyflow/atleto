// $Id: physicaleditor.cpp 369 2010-09-25 00:02:33Z boffyflow $
// (c) 2009, Parallel Pixels Ltd.

#include <QStringList>

#include "src/gui/physicaleditor.h"
#include "ui_physicaleditor.h"

#include "src/util/cgeneral.h"
#include "src/data/athlete.h"


PhysicalEditor::PhysicalEditor( const QDate &day, const int id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PhysicalEditor)
{
    ui->setupUi(this);

    if( id > 0)
    {
        mPhysical.restore( id);
    }
    else
    {
        mPhysical.restoreByJulianDay( day.toJulianDay());
    }

    setWindowTitle( QDate::fromJulianDay( mPhysical.julianDay()).toString( "ddd - MMM d"));

    QStringList     ratingList;
    ratingList << "" << PHYSICAL_RATING_POOR << PHYSICAL_RATING_FAIR << PHYSICAL_RATING_GOOD << PHYSICAL_RATING_VERY_GOOD << PHYSICAL_RATING_EXCELLENT;

    ui->ratingCombo->addItems( ratingList);

    ui->bodyfatEdit->setValidator( new QDoubleValidator( 0.0, 100.0, 1, ui->bodyfatEdit));
    ui->hrEdit->setValidator( new QIntValidator( 0, 300, ui->hrEdit));

    if( mPhysical.id() > 0)
    {
        ui->weightEdit->setValue( mPhysical.weight());
        ui->weightEdit->displayValue();
        ui->hrEdit->setText( QString::number( mPhysical.restingHR()));
        ui->bodyfatEdit->setText( QString::number( mPhysical.bodyFat()));
        ui->ratingCombo->setCurrentIndex( mPhysical.rating());
        ui->deleteButton->setEnabled( true);
    }
    else
    {
        ui->deleteButton->setEnabled( false);
    }
    displayBMI();
}

PhysicalEditor::~PhysicalEditor()
{
    delete ui;
}

void PhysicalEditor::changeEvent(QEvent *e)
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

void PhysicalEditor::on_buttonBox_accepted()
{
    mPhysical.setWeight( ui->weightEdit->value());
    mPhysical.setRestingHR( ui->hrEdit->text().toInt());
    mPhysical.setBodyFat( ui->bodyfatEdit->text().toFloat());
    mPhysical.setRating( ui->ratingCombo->currentIndex());
    mPhysical.save();
}

void PhysicalEditor::on_deleteButton_clicked()
{
    if( mPhysical.id() > 0)
        mPhysical.remove();

    close();
}

void PhysicalEditor::on_weightEdit_editingFinished()
{
    displayBMI();
}

void PhysicalEditor::displayBMI()
{
    Athlete::setAthleteById( 1);
    Athlete             *athlete = Athlete::getInstance();
    double              height = athlete->getHeight();
    double              weight = ui->weightEdit->value();

    if( weight > 0.0)
    {
        double	bmi = cGeneral::bmi( weight, height);

        QString			ss;
        QString			tt;
        if( bmi < 18.5)		// underweight
        {
            ss = "QLabel{color:darkMagenta};";
            tt = "underweight";
        }
        else if( bmi < 25.0)	// normal weight
        {
            ss = "QLabel{color:green};";
            tt = "normal weight";
        }
        else if( bmi < 30.0)	// overweight
        {
            ss = "QLabel{color:darkMagenta};";
            tt = "overweight";
        }
        else					// obese
        {
            ss = "QLabel{color:red};";
            tt = "obese";
        }
        ui->bmiLabel->setText( "BMI: " + QString::number( cGeneral::rnd( bmi, 1)));
        ui->bmiLabel->setStyleSheet( ss);
        ui->bmiLabel->setToolTip( tt);
    }
    else
    {
        ui->bmiLabel->setText( "BMI: ");
        ui->bmiLabel->setStyleSheet( "QLabel{color:green};");
    }
}
