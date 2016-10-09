// $Id: calendarwidget.cpp 370 2010-12-14 23:23:50Z boffyflow $
// (c) 2009, Parallel Pixels Ltd.

#include "calendarwidget.h"
#include "ui_calendarwidget.h"

#include <QCalendarWidget>
#include <QTreeWidgetItem>
#include <QTreeWidget>
#include <QModelIndex>

#include "src/data/run.h"
#include "src/util/rununits.h"
#include "src/util/ctime.h"
#include "src/data/physical.h"
#include "src/util/weightunits.h"
#include "src/util/cgeneral.h"

CalendarWidget::CalendarWidget( QWidget *parent) :
    QWidget( parent),
    ui( new Ui::CalendarWidget)
{
    ui->setupUi( this);

    mCurDate = QDate::currentDate();

    buildTree();

    // ensure the day view is visible and the summary is not shown
    ui->tabWidget->setCurrentIndex( 0);
    ui->summaryGroup->hide();

    connect( ui->weekView, SIGNAL( dataChanged()), this, SLOT( updateSummary()));
    connect( ui->weekView, SIGNAL( dayChanged( const QDate &)), this, SLOT( updateDate( const QDate &)));

    connect( ui->monthView, SIGNAL( dayChanged( const QDate &)), this, SLOT( updateDate( const QDate &)));

    ui->diaryTree->setCurrentItem( ui->diaryTree->topLevelItem( 0));
}

CalendarWidget::~CalendarWidget()
{
    delete ui;
}

void CalendarWidget::changeEvent( QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void CalendarWidget::on_tabWidget_currentChanged( int index)
{
    if( ui->tabWidget->currentIndex() == 0)         // day
    {
        ui->dayView->dayChanged();
        ui->summaryGroup->hide();
    }
    else if( ui->tabWidget->currentIndex() == 1)    // week
    {
        mCurDate = ui->weekView->currentDate();
        ui->weekView->setDayInWeek();
        ui->summaryGroup->show();
        updateSummary();
    }
    else if( ui->tabWidget->currentIndex() == 2)    // month
    {
        mCurDate = ui->monthView->currentDate();
        ui->monthView->setFirstDayInMonth();
        ui->summaryGroup->show();
        updateSummary();
    }
    else if( ui->tabWidget->currentIndex() == 3)    // all
    {
        ui->summaryGroup->show();
        on_diaryTree_itemSelectionChanged();
    }
}

void CalendarWidget::updateSummary( const bool all)
{
    QDate       firstDay;
    QDate       lastDay;

    if( ui->tabWidget->currentIndex() == 1)     // week view
    {
        firstDay = mCurDate.addDays( 1 - mCurDate.dayOfWeek());
        lastDay = firstDay.addDays( 6);
    }
    else if( ui->tabWidget->currentIndex() == 2)    // month view
    {
        firstDay = QDate( mCurDate.year(), mCurDate.month(), 1);
        lastDay = QDate( mCurDate.year(), mCurDate.month(), mCurDate.daysInMonth());
    }
    else if( ui->tabWidget->currentIndex() == 3)    // year view
    {
        if( !all)
        {
            firstDay = QDate( mCurDate.year(), 1, 1);
            lastDay = QDate( mCurDate.year(), 12, 31);
        }
        else
        {
            firstDay = Run::firstDay();
            lastDay = Run::lastDay();
        }
    }

    float       distance = Run::total( firstDay, lastDay, "dist");
    float       total_time = Run::total( firstDay, lastDay, "t");

    RunDistanceString       rs;
    rs.setValue( distance);
    ui->distLabel->setText( rs.text());
    ui->timeLabel->setText( cTime::t2str( total_time));
    ui->paceLabel->setText( rs.pace( total_time));

    // Weight

    float       minW = Physical::min( firstDay, lastDay, "weight");
    float       aveW = Physical::average( firstDay, lastDay, "weight");
    float       maxW = Physical::max( firstDay, lastDay, "weight");

    WeightString       ws;
    if( minW > 0 && minW < 1000000 && aveW > 0 && aveW < 1000000 && maxW > 0 && maxW < 1000000)
    {
        ws.setValue( minW);
        ui->minWeightLabel->setText( ws.text());
        ws.setValue( aveW);
        ui->aveWeightLabel->setText( ws.text());
        ws.setValue( maxW);
        ui->maxWeightLabel->setText( ws.text());
        ui->groupBoxWeight->show();
    }
    else
    {
        ui->groupBoxWeight->hide();
    }

    // Body fat

    float       minBf = Physical::min( firstDay, lastDay, "bodyfat");
    float       aveBf = Physical::average( firstDay, lastDay, "bodyfat");
    float       maxBf = Physical::max( firstDay, lastDay, "bodyfat");

    if( minBf > 10 && minBf < 1000 && aveBf > 10 && aveBf < 1000 && maxBf > 10 && maxBf < 1000)
    {
        ui->bfMin->setText( QString::number( cGeneral::rnd( minBf * 0.1, 1), 'f', 1) + " %");
        ui->bfAverage->setText( QString::number( cGeneral::rnd( aveBf * 0.1, 1), 'f', 1) + " %");
        ui->bfMax->setText( QString::number( cGeneral::rnd( maxBf * 0.1, 1), 'f', 1) + " %");
        ui->groupBoxBodyfat->show();
    }
    else
    {
        ui->groupBoxBodyfat->hide();
    }

    // Heartrate

    int         maxHR = Split::maxHeartRate( firstDay, lastDay);
    int         aveHR = Split::aveHeartRate( firstDay, lastDay);

    if( maxHR > 0 && aveHR > 0)
    {
        ui->maxHRLabel->setText( QString::number( maxHR));
        ui->aveHRLabel->setText( QString::number( aveHR));
        ui->groupBoxHeartrate->show();
    }
    else
    {
        ui->groupBoxHeartrate->hide();
    }
}

void CalendarWidget::updateContent()
{
    if( ui->tabWidget->currentIndex() == 0)     // day view
    {
        ui->dayView->dayChanged();
    }
    else if( ui->tabWidget->currentIndex() == 1)     // week view
    {
        ui->weekView->setDayInWeek();
    }
    else if( ui->tabWidget->currentIndex() == 2)    // month view
    {
        ui->monthView->setFirstDayInMonth();
    }
    else if( ui->tabWidget->currentIndex() == 3)    // all
    {
        mSelectedCalItem->setSelected( true);
        if( mSelectedCalItem->childCount() > 0)
            updateSummary( true);
        else
            updateSummary( false);
    }
}

void CalendarWidget::updateDate( const QDate &day)
{
    mCurDate = day;
    updateSummary();
}

void CalendarWidget::buildTree()
{
    QList<int>                  years = Run::years();

    for( int i = 0; i < years.count(); i++)
    {
        QTreeWidgetItem     *item = new QTreeWidgetItem( ui->diaryTree->topLevelItem( 0));
        item->setText( 0, QString::number( years.at( i)));
    }

    ui->diaryTree->expandAll();
}

void CalendarWidget::on_diaryTree_itemSelectionChanged()
{
    mSelectedCalItem = ui->diaryTree->selectedItems().at( 0);

    bool    all = false;
    int     year = mSelectedCalItem->text( 0).toInt();

    if( mSelectedCalItem->text( 0).length() > 4)
        all = true;
    else
        mCurDate = QDate( year, 1, 1);

    updateSummary( all);
}
