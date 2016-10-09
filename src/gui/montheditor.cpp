// $Id: montheditor.cpp 294 2010-03-05 18:37:10Z  $
// (c) 2009, Parallel Pixels Ltd.

#include "montheditor.h"
#include "ui_montheditor.h"

#include <QCalendarWidget>

MonthEditor::MonthEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonthEditor)
{
    ui->setupUi(this);

    mCurDate = QDate::currentDate();

    ui->dateEdit->setDate( mCurDate);
    ui->dateEdit->calendarWidget()->setFirstDayOfWeek( Qt::Monday);
}

MonthEditor::~MonthEditor()
{
    delete ui;
}

void MonthEditor::changeEvent(QEvent *e)
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

void MonthEditor::on_dateEdit_dateChanged( QDate date)
{
    mCurDate = date;
    setFirstDayInMonth();
}

void MonthEditor::setFirstDayInMonth()
{
    ui->dateEdit->setDate( mCurDate);
    ui->mainView->setFirstDayOfMonth( mCurDate);

    emit dayChanged( mCurDate);
}

void MonthEditor::on_prevButton_clicked()
{
    mCurDate = mCurDate.addMonths( -1);
    setFirstDayInMonth();
}

void MonthEditor::on_nextButton_clicked()
{
    mCurDate = mCurDate.addMonths( 1);
    setFirstDayInMonth();
}

void MonthEditor::on_todayButton_clicked()
{
    QDate       d = QDate::currentDate();
    mCurDate = QDate( d.year(), d.month(), 1);
    setFirstDayInMonth();
}
