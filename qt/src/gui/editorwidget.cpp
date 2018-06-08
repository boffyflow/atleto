// $Id: editorwidget.cpp 357 2010-04-07 17:42:35Z boffyflow $
// (c) 2009, Parallel Pixels Ltd.

#include <QCalendarWidget>

#include "editorwidget.h"
#include "ui_editorwidget.h"

#include "src/gui/runeditor.h"
#include "src/gui/weathereditor.h"
#include "src/gui/physicaleditor.h"
#include "src/gui/journaleditor.h"
#include "src/data/athlete.h"
#include "src/data/run.h"
#include "src/data/weather.h"
#include "src/data/physical.h"
#include "src/util/cgeneral.h"
#include "src/util/ctime.h"
#include "src/util/rununits.h"
#include "src/util/weightunits.h"
#include "src/util/temperatureunits.h"

EditorWidget::EditorWidget( QWidget *parent) :
    QWidget( parent),
    m_ui( new Ui::EditorWidget)
{
    m_ui->setupUi( this);

    mCurDate = QDate::currentDate();
    m_ui->dateEdit->calendarWidget()->setFirstDayOfWeek( Qt::Monday);
    m_ui->dateEdit->setDate( mCurDate);

    // Workout table
    connect( m_ui->editButton, SIGNAL( clicked()), this, SLOT( editRun()));
    connect( m_ui->woTable, SIGNAL( cellDoubleClicked( int, int)), this, SLOT( editRun( int, int)));
    connect( m_ui->deleteButton, SIGNAL( clicked()), this, SLOT( deleteRun()));
    connect( m_ui->woTable, SIGNAL( itemSelectionChanged()), this, SLOT( setButtons()));
}

EditorWidget::~EditorWidget()
{
    delete m_ui;
}

void EditorWidget::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void EditorWidget::dayChanged()
{
    m_ui->dateEdit->setDate( mCurDate);
    m_ui->weekdayLabel->setText( mCurDate.toString( "dddd"));

    populateData();
}

void EditorWidget::populateData()
{
    // Weather

    Weather         w;
    w.restoreByJulianDay( mCurDate.toJulianDay());

    TemperatureString       ts;
    ts.setValue( w.temperature());
    QString         wstring = ":/main/icons/weather" + QString::number( w.sky());
    m_ui->skyLabel->setPixmap( QPixmap( wstring));
    m_ui->tempLabel->setText( ts.text());
    m_ui->weatherNotesLabel->setText( w.notes());

    // Physical

    Physical         p;
    p.restoreByJulianDay( mCurDate.toJulianDay());
    QStringList     ratingList;
    ratingList << "" << "Poor" << "Fair" << "Good" << "Very Good" << "Execellent";

    WeightString            ws;
    ws.setValue( p.weight());
    if( p.weight() <= 0.0)
        m_ui->weightLabel->setText( "");
    else
        m_ui->weightLabel->setText( ws.text());

    if( p.bodyFat() < 0)
        m_ui->bodyfatLabel->setText( "");
    else
        m_ui->bodyfatLabel->setText( "Bodyfat [%]: " + QString::number( p.bodyFat()));
    if( p.restingHR() < 0)
        m_ui->hrLabel->setText( "");
    else
        m_ui->hrLabel->setText( "Resting HR: " + QString::number( p.restingHR()));
    if( p.rating() == 0)
        m_ui->ratingLabel->setText( "");
    else
        m_ui->ratingLabel->setText( "Rating: " + ratingList[ p.rating()]);
    displayBMI( p.weight());

    // Workouts

    QList<QStringList>		contents;
    QList<Run>                  runList = Run::runList( mCurDate);

    for( int i = 0; i < runList.count(); i++)
    {
        Run                     run = runList.at( i);
        RunDistanceString       rs;
        rs.setValue( run.distance());
        QString         iconName = ":/main/icons/runner.xpm";

        QStringList     rowData = ( QStringList() << QString::number( run.id()) <<             // 0
                                                    run.starttime().toString( "hhmm" + QString::number( i)) <<        // 1
                                                    iconName <<                                 // 2
                                                    run.location() <<                           // 3
                                                    "   " + rs.text() <<                        // 4
                                                    "   " + cTime::t2str( run.total_time()) <<  // 5
                                                    "   " + rs.pace( run.total_time()));        // 6
        contents.append( rowData);
    }

    m_ui->woTable->clear();
    m_ui->editButton->setEnabled( false);
    m_ui->deleteButton->setEnabled( false);
    m_ui->woTable->setRowCount( contents.size());
    m_ui->woTable->setColumnHidden( 0, true);		// hide the id column
    m_ui->woTable->setColumnHidden( 1, true);		// hide the start time column

    for( int i = 0; i < contents.size(); i++)
    {
        QStringList		entry = contents[i];

        m_ui->woTable->setItem( i, 0, new QTableWidgetItem( entry[0])); // run id (hidden)
        m_ui->woTable->setItem( i, 1, new QTableWidgetItem( entry[1]));	// start time (hidden)
        m_ui->woTable->setItem( i, 2, new QTableWidgetItem( QIcon( entry[2]), entry[3]));	// type icon + location
        m_ui->woTable->setItem( i, 3, new QTableWidgetItem( entry[4])); // distance
        m_ui->woTable->setItem( i, 4, new QTableWidgetItem( entry[5])); // time
        m_ui->woTable->setItem( i, 5, new QTableWidgetItem( entry[6])); // pace or speed
    }

    m_ui->woTable->sortItems( 1);       // sort based on start time
    m_ui->woTable->resizeColumnsToContents();

    if( runList.count() == 0)
    {
        m_ui->woTable->clear();
        m_ui->editButton->setEnabled( false);
        m_ui->deleteButton->setEnabled( false);
    }
}

void EditorWidget::displayBMI( const double weight)
{
    Athlete::setAthleteById( 1);
    Athlete             *athlete = Athlete::getInstance();
    double              height = athlete->getHeight();

    if( weight > 0)
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
        m_ui->bmiLabel->setText( "BMI: " + QString::number( cGeneral::rnd( bmi, 1)));
        m_ui->bmiLabel->setStyleSheet( ss);
        m_ui->bmiLabel->setToolTip( tt);
    }
    else
    {
        m_ui->bmiLabel->setText( "BMI: ");
        m_ui->bmiLabel->setStyleSheet( "QLabel{color:green};");
    }
}

void EditorWidget::on_addButton_clicked()
{
    RunEditor       re( mCurDate, -1, this);
    re.exec();
    dayChanged();
}

void EditorWidget::setButtons()
{
    QList<QTableWidgetItem *>	selItems = m_ui->woTable->selectedItems();

    bool		en = true;
    if( selItems.size() == 0)
        en = false;

    m_ui->editButton->setEnabled( en);
    m_ui->deleteButton->setEnabled( en);
}

void EditorWidget::editRun( int row, int column)
{
    if( row < 0)
        row = m_ui->woTable->selectedItems()[0]->row();

    int			runId = m_ui->woTable->item( row, 0)->text().toInt();

    RunEditor       runeditor( mCurDate, runId, this);

    runeditor.exec();

    dayChanged();
}

void EditorWidget::deleteRun()
{
    int     row = m_ui->woTable->selectedItems()[0]->row();
    int     runId = m_ui->woTable->item( row, 0)->text().toInt();

    Run     run( runId);
    run.remove();
    dayChanged();
}

void EditorWidget::on_editWeather_clicked()
{
    WeatherEditor       we( mCurDate, -1, this);

    we.exec();

    Weather         w;
    w.restoreByJulianDay( mCurDate.toJulianDay());
    TemperatureString       ts;
    ts.setValue( w.temperature());
    QString         wstring = ":/main/icons/weather" + QString::number( w.sky());
    m_ui->skyLabel->setPixmap( QPixmap( wstring));
    m_ui->tempLabel->setText( ts.text());
    m_ui->weatherNotesLabel->setText( w.notes());
}

void EditorWidget::on_editPhysical_clicked()
{
    PhysicalEditor       pe( mCurDate, -1, this);
    QStringList     ratingList;
    ratingList << "" << "Poor" << "Fair" << "Good" << "Very Good" << "Execellent";

    pe.exec();

    Physical         p;
    p.restoreByJulianDay( mCurDate.toJulianDay());
    WeightString            ws;
    ws.setValue( p.weight());
    m_ui->weightLabel->setText( ws.text());
    m_ui->bodyfatLabel->setText( "Bodyfat [%]: " + QString::number( p.bodyFat()));
    m_ui->hrLabel->setText( "Resting HR: " + QString::number( p.restingHR()));
    m_ui->ratingLabel->setText( "Rating: " + ratingList[ p.rating()]);
    displayBMI( p.weight());
}

void EditorWidget::on_pushButton_clicked()
{
    JournalEditor       je( mCurDate, -1, this);

    je.exec();
}

void EditorWidget::on_dateEdit_dateChanged( QDate date)
{
    mCurDate = date;
    dayChanged();
}

void EditorWidget::on_prevButton_clicked()
{
    mCurDate = mCurDate.addDays( -1);
    dayChanged();
}

void EditorWidget::on_nextButton_clicked()
{
    mCurDate = mCurDate.addDays( 1);
    dayChanged();
}

void EditorWidget::on_todayButton_clicked()
{
    mCurDate = QDate::currentDate();
    dayChanged();
}
