// $Id: weekeditor.cpp 294 2010-03-05 18:37:10Z  $
// (c) 2009, Parallel Pixels Ltd.

#include "weekeditor.h"
#include "ui_weekeditor.h"

#include <QGraphicsRectItem>
#include <QDate>
#include <QScrollBar>
#include <QCalendarWidget>

#include "src/util/graphicscalentryitem.h"
#include "src/data/run.h"

const qreal ENTRY_HEIGHT = 16.0;
const qreal ENTRY_WIDTH = 70.0;
const qreal TIME_WIDTH = 35.0;

WeekEditor::WeekEditor( QWidget *parent, const QDate &day) :
    QWidget( parent),
    ui( new Ui::WeekEditor)
{
    ui->setupUi(this);

    mCurDate = QDate::currentDate();
    ui->dateEdit->calendarWidget()->setFirstDayOfWeek( Qt::Monday);
    ui->dateEdit->setDate( mCurDate);

    connect( ui->mainView, SIGNAL( dataChanged()), this, SLOT( weekViewChanged()));
}

WeekEditor::~WeekEditor()
{
    delete ui;
}

void WeekEditor::setDayInWeek()
{
    ui->dateEdit->setDate( mCurDate);
    ui->mainView->setFirstDayOfWeek( mCurDate);

    emit dayChanged( mCurDate);
}

void WeekEditor::changeEvent(QEvent *e)
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

void WeekEditor::weekViewChanged()
{
    emit dataChanged();
}

void WeekEditor::on_dateEdit_dateChanged( QDate date)
{
    mCurDate = date;
    setDayInWeek();
}

void WeekEditor::on_prevButton_clicked()
{
    mCurDate = mCurDate.addDays( -7);
    setDayInWeek();
}

void WeekEditor::on_nextButton_clicked()
{
    mCurDate = mCurDate.addDays( 7);
    setDayInWeek();
}

void WeekEditor::on_todayButton_clicked()
{
    mCurDate = QDate::currentDate();
    setDayInWeek();
}
