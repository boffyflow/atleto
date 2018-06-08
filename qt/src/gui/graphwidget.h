// $Id: graphwidget.h 221 2009-06-05 23:57:04Z robert $
// (c) 2009, Parallel Pixels Ltd.

#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QtGui/QWidget>
#include <QDomElement>
#include "src/controller/reportcontroller.h"

namespace Ui
{
    class GraphWidget;
}

const int   GRAPHWIDGET_UP = 0;
const int   GRAPHWIDGET_DOWN = 1;

class GraphWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(GraphWidget)

public:

    explicit GraphWidget( QWidget *parent = 0);
    virtual ~GraphWidget();

    void    disable( const int direction);
    void    enable( const int direction);

    virtual ReportController    *controller() = 0;
    virtual void                addElement( QDomDocument *doc) = 0;

protected:

    virtual void changeEvent(QEvent *e);

    Ui::GraphWidget     *m_ui;

private slots:

    void on_closeButton_clicked();
    void on_downButton_clicked();
    void on_upButton_clicked();

signals:

    void    up( GraphWidget *);
    void    down( GraphWidget *);
    void    close( GraphWidget *);
};

#endif // GRAPHWIDGET_H
