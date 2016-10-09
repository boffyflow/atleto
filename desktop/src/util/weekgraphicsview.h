// $Id: weekgraphicsview.h 294 2010-03-05 18:37:10Z  $
// (c) 2006, Parallel Pixels Ltd.

#ifndef WEEKGRAPHICSVIEW_H
#define WEEKGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QDate>

class WeekGraphicsView : public QGraphicsView
{
    Q_OBJECT
    Q_DISABLE_COPY(WeekGraphicsView)

public:

    WeekGraphicsView( QWidget * parent = 0);
    WeekGraphicsView( QGraphicsScene * scene, QWidget * parent = 0);

    void    setFirstDayOfWeek( const QDate &date);

    void loadDataIntoView();

protected:

    void resizeEvent ( QResizeEvent * event );

private:

    QGraphicsScene              *mScene;
    QDate                       mFirstDayOfWeek;
    QList<QGraphicsItem *>      mWeekGraphicItems;
    QList<QGraphicsItem *>      mDynamicItems;

signals:

    void    dataChanged( void);
};

#endif // WEEKGRAPHICSVIEW_H
