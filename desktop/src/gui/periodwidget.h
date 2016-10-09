// $Id: periodwidget.h 220 2009-06-04 23:42:36Z robert $
// (c) 2009, Parallel Pixels Ltd.

#ifndef PERIODWIDGET_H
#define PERIODWIDGET_H

#include <QtGui/QGroupBox>
#include <QDate>

const int REPORT_TYPE_DAILY = 0;
const int REPORT_TYPE_WEEKLY = 1;
const int REPORT_TYPE_MONTHLY = 2;
const int REPORT_TYPE_YEARLY = 3;

const int REPORT_THIS_WEEK = 0;
const int REPORT_THIS_MONTH = 1;
const int REPORT_THIS_YEAR = 2;
const int REPORT_LAST_WEEK = 3;
const int REPORT_LAST_MONTH = 4;
const int REPORT_LAST_YEAR = 5;
const int REPORT_LAST_FLEX = 6;
const int REPORT_CUSTOM_DATES = 7;

const int REPORT_PERIOD_DAYS = 0;
const int REPORT_PERIOD_WEEKS = 1;
const int REPORT_PERIOD_MONTHS = 2;
const int REPORT_PERIOD_YEARS = 3;

namespace Ui
{
    class PeriodWidget;
}

class PeriodWidget : public QGroupBox
{
    Q_OBJECT
    Q_DISABLE_COPY(PeriodWidget)

public:

    explicit PeriodWidget(QWidget *parent = 0);
    virtual ~PeriodWidget();

    int     periodType() const;
    QDate   startDate() const;
    QDate   endDate() const;
    int     period() const;
    int     numUnits() const;
    int     unitsPeriod() const;

    void    setDates();

    void    setPeriod( const int periodType, const QDate &startDate, const QDate &endDate, const int period, const int numUnits = 1, const int unitsPeriod = 0);

protected:

    virtual void changeEvent(QEvent *e);

private:

    Ui::PeriodWidget    *m_ui;

private slots:

    void on_toDate_dateChanged(QDate date);
    void on_fromDate_dateChanged(QDate date);
    void on_reportTypeCombo_currentIndexChanged(int index);
    void on_unitsCombo_currentIndexChanged( int index);
    void on_numUnitsEdit_editingFinished();
    void on_periodCombo_currentIndexChanged( int index);

signals:

    void    periodChanged();
};

#endif // PERIODWIDGET_H
