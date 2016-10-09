// $Id: montheditor.h 294 2010-03-05 18:37:10Z  $
// (c) 2009, Parallel Pixels Ltd.

#ifndef MONTHEDITOR_H
#define MONTHEDITOR_H

#include <QWidget>
#include <QDate>

namespace Ui
{
    class MonthEditor;
}

class MonthEditor : public QWidget
{
    Q_OBJECT

public:

    MonthEditor(QWidget *parent = 0);
    ~MonthEditor();

    void    setFirstDayInMonth();
    QDate   currentDate() const { return mCurDate;};

protected:

    void changeEvent(QEvent *e);

private:

    QDate                   mCurDate;
    Ui::MonthEditor *ui;

private slots:

    void on_todayButton_clicked();
    void on_nextButton_clicked();
    void on_prevButton_clicked();
    void on_dateEdit_dateChanged(QDate date);

signals:

    void        dayChanged( const QDate &);
};

#endif // MONTHEDITOR_H
