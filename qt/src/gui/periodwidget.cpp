// $Id: periodwidget.cpp 220 2009-06-04 23:42:36Z robert $
// (c) 2009, Parallel Pixels Ltd.

#include <QCalendarWidget>

#include "periodwidget.h"
#include "ui_periodwidget.h"

PeriodWidget::PeriodWidget(QWidget *parent) :
    QGroupBox(parent),
    m_ui(new Ui::PeriodWidget)
{
    m_ui->setupUi(this);

    QValidator      *validator = new QIntValidator( 1, 999, this);
    m_ui->numUnitsEdit->setValidator( validator);

    m_ui->numUnitsEdit->hide();
    m_ui->unitsCombo->hide();

    m_ui->fromDate->calendarWidget()->setFirstDayOfWeek( Qt::Monday);
    m_ui->toDate->calendarWidget()->setFirstDayOfWeek( Qt::Monday);
}

PeriodWidget::~PeriodWidget()
{
    delete m_ui;
}

void PeriodWidget::changeEvent(QEvent *e)
{
    QGroupBox::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

int PeriodWidget::periodType() const
{
    return m_ui->reportTypeCombo->currentIndex();
}

QDate PeriodWidget::startDate() const
{
    return m_ui->fromDate->date();
}

QDate PeriodWidget::endDate() const
{
    return m_ui->toDate->date();
}

int PeriodWidget::period() const
{
    return m_ui->periodCombo->currentIndex();
}

int PeriodWidget::numUnits() const
{
    return m_ui->numUnitsEdit->text().toInt();
}

int PeriodWidget::unitsPeriod() const
{
    return m_ui->unitsCombo->currentIndex();
}

void PeriodWidget::setPeriod( const int periodType, const QDate &startDate, const QDate &endDate, const int period, const int numUnits, const int unitsPeriod)
{
    m_ui->reportTypeCombo->setCurrentIndex( periodType);
    m_ui->periodCombo->setCurrentIndex( period);
    if( period == REPORT_LAST_FLEX)
    {
        m_ui->numUnitsEdit->setText( QString::number( numUnits));
        m_ui->unitsCombo->setCurrentIndex( unitsPeriod);
    }
    else if( period == REPORT_CUSTOM_DATES)
    {
        m_ui->fromDate->setDate( startDate);
        m_ui->toDate->setDate( endDate);
    }
}

void PeriodWidget::on_periodCombo_currentIndexChanged( int index)
{
    if( index == REPORT_LAST_FLEX)
    {
        m_ui->numUnitsEdit->show();
        m_ui->unitsCombo->show();
    }
    else
    {
        m_ui->numUnitsEdit->hide();
        m_ui->unitsCombo->hide();
    }

    bool    datesEnabled = false;
    if( index == REPORT_CUSTOM_DATES)
    {
        datesEnabled = true;
    }
    else
    {
        setDates();
    }

    m_ui->fromDate->setEnabled( datesEnabled);
    m_ui->toDate->setEnabled( datesEnabled);

    emit periodChanged();
}

void PeriodWidget::setDates()
{
    int     index = m_ui->periodCombo->currentIndex();
    QDate   to_day = QDate::currentDate();
    QDate   from_day = to_day.addDays( -10);
    int     month = to_day.month();
    int     year = to_day.year();

    if( index == REPORT_THIS_WEEK)
    {
        from_day = to_day.addDays( 1 - to_day.dayOfWeek());
        to_day = QDate::currentDate();
    }
    else if( index == REPORT_THIS_MONTH)
    {
        from_day.setDate( to_day.year(), to_day.month(), 1);
        to_day = QDate::currentDate();
    }
    else if( index == REPORT_THIS_YEAR)
    {
        from_day.setDate( to_day.year(), 1, 1);
        to_day = QDate::currentDate();
    }
    else if( index == REPORT_LAST_WEEK)
    {
        from_day = to_day.addDays( 1 - 7 - to_day.dayOfWeek());
        to_day = from_day.addDays( 6);
    }
    else if( index == REPORT_LAST_MONTH)
    {
        if( month == 1)
        {
            month = 12;
            year--;
        }
        from_day.setDate( year, month - 1, 1);
        to_day.setDate( year, month - 1, from_day.daysInMonth());
    }
    else if( index == REPORT_LAST_YEAR)
    {
        from_day.setDate( year - 1, 1, 1);
        to_day.setDate( year - 1, 12, 31);
    }
    else if( index == REPORT_LAST_FLEX)
    {
        int     number = m_ui->numUnitsEdit->text().toInt();
        int     pindex = m_ui->unitsCombo->currentIndex();

        if( pindex == REPORT_PERIOD_DAYS)
        {
            from_day = to_day.addDays( -number);
        }
        else if( pindex == REPORT_PERIOD_WEEKS)
        {
            from_day = to_day.addDays( 1 - to_day.dayOfWeek() - number * 7);
        }
        else if( pindex == REPORT_PERIOD_MONTHS)
        {
            from_day = to_day.addMonths( -number);
        }
        else if( pindex == REPORT_PERIOD_YEARS)
        {
            from_day = to_day.addYears( -number);
        }
    }

    m_ui->fromDate->setDate( from_day);
    m_ui->toDate->setDate( to_day);
}


void PeriodWidget::on_numUnitsEdit_editingFinished()
{
    setDates();

    emit periodChanged();
}

void PeriodWidget::on_unitsCombo_currentIndexChanged(int index)
{
    setDates();

    emit periodChanged();
}


void PeriodWidget::on_reportTypeCombo_currentIndexChanged(int index)
{
    emit periodChanged();
}

void PeriodWidget::on_fromDate_dateChanged(QDate date)
{
    emit periodChanged();
}

void PeriodWidget::on_toDate_dateChanged(QDate date)
{
    emit periodChanged();
}
