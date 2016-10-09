// $Id: searchrunwidget.h 368 2010-06-12 22:08:44Z boffyflow $
// (c) 2010, Parallel Pixels Ltd.

#ifndef SEARCHRUNWIDGET_H
#define SEARCHRUNWIDGET_H

#include <QtWidgets/QWidget>
#include "src/data/queryparameters.h"

class QTreeWidgetItem;

namespace Ui
{
    class SearchRunWidget;
}

class SearchRunWidget : public QWidget
{
    Q_OBJECT
public:
    SearchRunWidget(QWidget *parent = 0);
    ~SearchRunWidget();

protected:
    void changeEvent(QEvent *e);

private:

    QueryParameters     *mQuery;
    Ui::SearchRunWidget *m_ui;

private slots:
    void on_resultsWidget_itemDoubleClicked( QTreeWidgetItem* item, int column);
    void on_searchButton_clicked();
};

#endif // SEARCHRUNWIDGET_H
