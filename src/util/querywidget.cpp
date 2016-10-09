// (c) 2010 Parallel Pixels Ltd.
// $Id: querywidget.cpp 372 2013-03-05 22:04:13Z boffyflow $

#include <QPushButton>
#include <QStandardItemModel>

#include "src/util/querywidget.h"
#include "ui_querywidget.h"

#include "src/util/queryfilter.h"

QueryWidget::QueryWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QueryWidget)
{
    ui->setupUi( this);

    ui->filterWidget->setLayout( new QVBoxLayout);
    ui->filterWidget->layout()->setContentsMargins( 3, 3, 3, 3);

    ui->fromDate->setDate( QDate::currentDate().addMonths( -1));
    ui->toDate->setDate( QDate::currentDate());

    ui->numUnitsEdit->setValidator( new QIntValidator( 1, 1000, ui->numUnitsEdit));

    ((QStandardItemModel *) ui->filterCombo->model())->item( 3)->setEnabled( false);        // disable time for now

    ui->periodCombo->setCurrentIndex( 0);

    ui->numUnitsEdit->hide();
    ui->unitsCombo->hide();
    ui->fromDate->hide();
    ui->fromLabel->hide();
    ui->toDate->hide();
    ui->toLabel->hide();
}

QueryWidget::~QueryWidget()
{
    delete ui;
}

void QueryWidget::changeEvent(QEvent *e)
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

void QueryWidget::addFilter( const int index, const QString& valueString)
{
    QueryFilter     *qf = new QueryFilter( index);
    mFilters[index] = qf;
    qf->setValueString( valueString);

    ((QVBoxLayout *) ui->filterWidget->layout())->addLayout( qf->layout());
    ((QStandardItemModel *) ui->filterCombo->model())->item( index)->setEnabled( false);

    connect( qf, SIGNAL( filterRemoved( int)), this, SLOT( removeFilter( int)));
}

void QueryWidget::on_periodCombo_currentIndexChanged( int index)
{
    if( index >= 0 && index <= 6)
    {
        ui->numUnitsEdit->hide();
        ui->unitsCombo->hide();
        ui->fromDate->hide();
        ui->fromLabel->hide();
        ui->toDate->hide();
        ui->toLabel->hide();
    }
    else if( index == 7)
    {
        ui->numUnitsEdit->show();
        ui->unitsCombo->show();
        ui->fromDate->hide();
        ui->fromLabel->hide();
        ui->toDate->hide();
        ui->toLabel->hide();
    }
    else if( index == 8)
    {
        ui->numUnitsEdit->hide();
        ui->unitsCombo->hide();
        ui->fromDate->show();
        ui->fromLabel->show();
        ui->toDate->show();
        ui->toLabel->show();
    }
    else if( index == 9)
    {
        ui->numUnitsEdit->hide();
        ui->unitsCombo->hide();
        ui->fromDate->show();
        ui->fromLabel->show();
        ui->toDate->hide();
        ui->toLabel->hide();
    }
}

void QueryWidget::on_filterCombo_currentIndexChanged( int index)
{
    if( index == FILTER_LOCATION)
        addFilter( index, "");

    if( index == FILTER_DISTANCE)
        addFilter( index, "0 100000");

    if( index == FILTER_RUNTYPE)
        addFilter( index, "base");

    ui->filterCombo->setCurrentIndex( 0);
}

void QueryWidget::removeFilter( int filterType)
{
    ui->filterWidget->layout()->removeItem( mFilters[filterType]->layout());
    mFilters.remove( filterType);

    ((QStandardItemModel *) ui->filterCombo->model())->item( filterType)->setEnabled( true);
}

QDate QueryWidget::rangeFrom() const
{
    QDate       startDate;
    QDate       todayDate = QDate::currentDate();
    int         selection = ui->periodCombo->currentIndex();

    if( selection == 0)       // all dates
    {
        startDate.setDate( 1900, 1, 1);
    }
    else if( selection == 1)        // this week
    {
        startDate = todayDate.addDays( 1 - todayDate.dayOfWeek());
    }
    else if( selection == 2)        // this month
    {
        startDate.setDate( todayDate.year(), todayDate.month(), 1);
    }
    else if( selection == 3)        // this year
    {
        startDate.setDate( todayDate.year(), 1, 1);
    }
    else if( selection == 4)        // last week
    {
        startDate = todayDate.addDays( 1 - todayDate.dayOfWeek() - 7);
    }
    else if( selection == 5)        // last month
    {
        startDate = QDate( todayDate.year(), todayDate.month(), 1).addMonths( -1);
    }
    else if( selection == 6)        // last year
    {
        startDate = QDate( todayDate.year(), 1, 1).addYears( -1);
    }
    else if( selection == 7)        // last XX
    {
        int     numLast = ui->numUnitsEdit->text().toInt();
        int     unitsLast = ui->unitsCombo->currentIndex();

        if( unitsLast == 0)
        {
            startDate = todayDate.addDays( - numLast);      // days
        }
        else if( unitsLast == 1)
        {
            startDate = todayDate.addDays( - numLast * 7);  // weeks
        }
        else if( unitsLast == 2)
        {
            startDate = todayDate.addMonths( - numLast);  // months
        }
        else if( unitsLast == 3)
        {
            startDate = todayDate.addYears( - numLast);  // years
        }
    }
    else if( selection == 8 || selection == 9)        // custom dates
    {
        startDate = ui->fromDate->date();
    }

    return startDate;
}

QDate QueryWidget::rangeTo() const
{
    QDate       endDate;
    QDate       todayDate = QDate::currentDate();
    int         selection = ui->periodCombo->currentIndex();

    if( selection == 0 || selection == 1 || selection == 2 || selection == 3 || selection == 7 || selection == 9)
    {
        endDate = todayDate;
    }
    else if( selection == 4)        // last week
    {
        endDate = todayDate.addDays( - todayDate.dayOfWeek());
    }
    else if( selection == 5)        // last month
    {
        QDate       d = QDate( todayDate.year(), todayDate.month(), 1).addMonths( -1);
        endDate.setDate( d.year(), d.month(), d.daysInMonth());
    }
    else if( selection == 6)        // last year
    {
        QDate       d = QDate( todayDate.year(), 1, 1).addYears( -1);
        endDate.setDate( d.year(), 12, 31);
    }
    else if( selection == 8)        // custom dates
    {
        endDate = ui->toDate->date();
    }

    return endDate;
}

QList<Run>  QueryWidget::runList()
{
    QList<int>      keys = mFilters.keys();
    QList<Run>      runs = Run::runList( rangeFrom(), rangeTo());

    for( int i = 0; i < keys.count(); i++)
    {
        QMutableListIterator<Run>   iter( runs);

        while( iter.hasNext())
        {
            QString     s = mFilters.value( keys.at( i))->result();
            Run         run = iter.next();

            if( keys.at( i) == FILTER_LOCATION)
            {
                if( !run.location().contains( s, Qt::CaseInsensitive))
                    iter.remove();
            }
            if( keys.at( i) == FILTER_DISTANCE)
            {
                double mindist = s.split( " ").at( 0).toDouble();
                double maxdist = s.split( " ").at( 1).toDouble();

                if( !( run.distance() >= mindist && run.distance() <= maxdist))
                    iter.remove();
            }
            if( keys.at( i) == FILTER_RUNTYPE)
            {
                if( run.kindofworkout() != s)
                    iter.remove();
            }
        }
    }

    return runs;
}

void QueryWidget::setQueryParameters( QueryParameters *query)
{
    mQueryParameters = query;

    ui->periodCombo->setCurrentIndex( mQueryParameters->range());
    ui->numUnitsEdit->setText( QString::number( mQueryParameters->lastN()));
    ui->unitsCombo->setCurrentIndex( mQueryParameters->lastUnits());
    ui->fromDate->setDate( mQueryParameters->customFrom());
    ui->toDate->setDate( mQueryParameters->customTo());

    QList<int>      fList =  mQueryParameters->filters()->keys();

    for( int i = 0; i < fList.count(); i++)
    {
        int     key = fList.at( i);
        addFilter( key, mQueryParameters->filters()->value( key));
    }
}

QueryParameters* QueryWidget::queryParameters()
{
    mQueryParameters->setRange( ui->periodCombo->currentIndex());
    mQueryParameters->setLastN( ui->numUnitsEdit->text().toInt());
    mQueryParameters->setLastUnits( ui->unitsCombo->currentIndex());
    mQueryParameters->setCustomFrom( ui->fromDate->date());
    mQueryParameters->setCustomTo( ui->toDate->date());

    mQueryParameters->removeAllFilters();

    QList<int>      filters = mFilters.keys();
    for( int i = 0; i < filters.count(); i++)
    {
        mQueryParameters->addFilter( filters.at( i), mFilters.value( filters.at( i))->result());
    }

    return mQueryParameters;
}



