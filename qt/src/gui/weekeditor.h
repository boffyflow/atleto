// $Id: weekeditor.h 294 2010-03-05 18:37:10Z  $
// (c) 2009, Parallel Pixels Ltd.

#ifndef WEEKEDITOR_H
#define WEEKEDITOR_H

#include <QWidget>
#include <QDate>

#include "src/util/graphicsrunitem.h"

namespace Ui
{
    class WeekEditor;
}

class WeekEditor : public QWidget
{
    Q_OBJECT

public:

    WeekEditor( QWidget *parent = 0, const QDate &day = QDate::currentDate());
    ~WeekEditor();

    void    setDayInWeek();
    QDate   currentDate() const { return mCurDate;};

protected:

    void changeEvent( QEvent *e);

private:

    QDate                   mCurDate;
    Ui::WeekEditor          *ui;

private slots:

    void on_todayButton_clicked();
    void on_nextButton_clicked();
    void on_prevButton_clicked();
    void on_dateEdit_dateChanged( QDate date);
    void weekViewChanged();

signals:

    void        dataChanged();
    void        dayChanged( const QDate &);
};

#endif // WEEKEDITOR_H
