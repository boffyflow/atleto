// (c) 2010 Parallel Pixels Ltd.
// $Id: querywidget.h 366 2010-06-04 21:16:57Z boffyflow $

#ifndef QUERYWIDGET_H
#define QUERYWIDGET_H

#include <QWidget>
#include <QMap>
#include "src/data/run.h"
#include "src/data/queryparameters.h"

class QDate;
class QHBoxLayout;
class QueryFilter;

namespace Ui
{
    class QueryWidget;
}

class QueryWidget : public QWidget
{
    Q_OBJECT
public:

    QueryWidget( QWidget *parent = 0);
    ~QueryWidget();

    QList<Run>      runList();

    void    addFilter( const int index, const QString& valueString);

    void                setQueryParameters( QueryParameters *query);
    QueryParameters     *queryParameters();

protected:

    void changeEvent(QEvent *e);

private:

    QDate                       rangeFrom() const;
    QDate                       rangeTo() const;

    QueryParameters             *mQueryParameters;
    QMap<int, QueryFilter *>    mFilters;
    QHBoxLayout                 *mLocationFilterLayout;
    Ui::QueryWidget             *ui;

private slots:

    void on_filterCombo_currentIndexChanged( int index);
    void on_periodCombo_currentIndexChanged( int index);
    void removeFilter( int filterType);
};

#endif // QUERYWIDGET_H
