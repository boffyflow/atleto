// $Id: reportwidget.cpp 366 2010-06-04 21:16:57Z boffyflow $
// (c) 2009, Parallel Pixels Ltd.

#include <QMenu>
#include <QAction>
#include <QCalendarWidget>
#include <QtSql>
#include <QHash>
#include <QTextEdit>
#include <QMdiSubWindow>

#include "reportwidget.h"
#include "ui_reportwidget.h"

#include "src/plot/grapheditor.h"
#include "src/plot/graphwidget.h"
#include "src/data/graph.h"

ReportWidget::ReportWidget(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::ReportWidget)
{
    m_ui->setupUi( this);

    restoreGraphs();
}

ReportWidget::~ReportWidget()
{
    delete m_ui;
}

void ReportWidget::changeEvent(QEvent *e)
{
    switch (e->type())
    {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void ReportWidget::on_addGraphButton_clicked()
{
    Graph           *props = new Graph();
    GraphEditor     ge( props, this);

    if( ge.exec() == QDialog::Accepted)
    {
        GraphWidget     *gw = new GraphWidget( props, this);

        connect( gw, SIGNAL( titleChanged()), this, SLOT( updateTitles()));

        QMdiSubWindow      *w = m_ui->mdiArea->addSubWindow( gw);
        w->setWindowTitle( props->name());
        w->show();
    }
    else
    {
        delete props;
    }
}

void ReportWidget::on_cascadeButton_clicked()
{
    m_ui->mdiArea->cascadeSubWindows();
}

void ReportWidget::on_tileButton_clicked()
{
    m_ui->mdiArea->tileSubWindows();
}

void ReportWidget::updateTitles()
{
    for( int i = 0; i < m_ui->mdiArea->subWindowList().count(); i++)
    {
        m_ui->mdiArea->subWindowList().at( i)->setWindowTitle( ( (GraphWidget *) m_ui->mdiArea->subWindowList().at( i)->widget())->properties()->name());
    }
}

void ReportWidget::restoreGraphs()
{
    QList<Graph *>        graphList = Graph::graphList();

    for( int i = 0; i < graphList.count(); i++)
    {
        Graph       *g = graphList.at( i);

        GraphWidget     *gw = new GraphWidget( g, this);

        connect( gw, SIGNAL( titleChanged()), this, SLOT( updateTitles()));

        QMdiSubWindow      *w = m_ui->mdiArea->addSubWindow( gw);
        w->setWindowTitle( g->name());
        w->show();
    }

    m_ui->mdiArea->tileSubWindows();
}
