// $Id: calendarwidget.h 370 2010-12-14 23:23:50Z boffyflow $
// (c) 2009, Parallel Pixels Ltd.

#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QWidget>
#include <QDate>

namespace Ui {
    class CalendarWidget;
}

class QTreeWidgetItem;

class CalendarWidget : public QWidget
{
    Q_OBJECT

public:

    CalendarWidget( QWidget *parent = 0);
    ~CalendarWidget();

public slots:

    void        updateSummary( const bool all = false);
    void        updateDate( const QDate &day);
    void        updateContent();

protected:

    void changeEvent( QEvent *e);

private:

    void                buildTree();

    QDate               mCurDate;
    Ui::CalendarWidget  *ui;
    QTreeWidgetItem     *mSelectedCalItem;

private slots:

    void on_diaryTree_itemSelectionChanged();
    void on_tabWidget_currentChanged(int index);
};

#endif // CALENDARWIDGET_H
