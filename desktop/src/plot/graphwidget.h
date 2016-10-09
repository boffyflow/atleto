// $Id: graphwidget.h 372 2013-03-05 22:04:13Z boffyflow $
// (c) 2010, Parallel Pixels Ltd.

#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QWidget>

class Graph;

namespace Ui {
    class GraphWidget;
}

class GraphWidget : public QWidget
{
    Q_OBJECT
public:
    GraphWidget( Graph *props, QWidget *parent = 0);
    ~GraphWidget();

    Graph*    properties() { return mProps;};

protected:

    void changeEvent(QEvent *e);
    void closeEvent( QCloseEvent *event);

private:

    Graph               *mProps;            // GraphWidget is owner of Graph
    Ui::GraphWidget     *ui;

private slots:
    void on_propsButton_clicked();

    void on_csvButton_clicked();

signals:

    void    titleChanged();
};

#endif // GRAPHWIDGET_H
