// $Id: monthgraphicsview.h 294 2010-03-05 18:37:10Z  $
// (c) 2006, Parallel Pixels Ltd.

#ifndef MONTHGRAPHICSVIEW_H
#define MONTHGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QDate>

class MonthGraphicsView : public QGraphicsView
{
    Q_OBJECT
    Q_DISABLE_COPY(MonthGraphicsView)

public:

    MonthGraphicsView( QWidget * parent = 0);
    MonthGraphicsView( QGraphicsScene * scene, QWidget * parent = 0);

    void    setFirstDayOfMonth( const QDate &date);

protected:

    void resizeEvent ( QResizeEvent * event );

private:

    QGraphicsScene              *mScene;
    QDate                       mFirstDayOfMonth;
    QList<QGraphicsItem *>      mMonthGraphicItems;

signals:

    void    dataChanged( void);
};

#endif // MONTHGRAPHICSVIEW_H
