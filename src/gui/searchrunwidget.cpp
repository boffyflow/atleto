// $Id: searchrunwidget.cpp 370 2010-12-14 23:23:50Z boffyflow $
// (c) 2010, Parallel Pixels Ltd.

#include <QtSql>

#include "searchrunwidget.h"
#include "ui_searchrunwidget.h"

#include "runlineedit.h"
#include "src/data/run.h"
#include "src/util/ctime.h"
#include "src/gui/runviewer.h"

SearchRunWidget::SearchRunWidget(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::SearchRunWidget)
{
    m_ui->setupUi(this);
    mQuery = new QueryParameters;

    QSettings   settings;

    settings.beginGroup( "Search");
    mQuery->restoreFromXML( settings.value( "query").toString());
    settings.endGroup();

    m_ui->queryWidget->setQueryParameters( mQuery);
}

SearchRunWidget::~SearchRunWidget()
{
    mQuery = m_ui->queryWidget->queryParameters();

    QSettings       settings;

    settings.beginGroup( "Search");
    settings.setValue( "query", mQuery->toXML());
    settings.endGroup();

    delete mQuery;
    delete m_ui;
}

void SearchRunWidget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void SearchRunWidget::on_searchButton_clicked()
{
    QList<Run>      rList = m_ui->queryWidget->runList();

    m_ui->resultsWidget->clear();

    for( int i = 0; i < rList.count(); i++)
    {
        Run         run = rList.at( i);
        int         jd = run.julianDay();

        QTreeWidgetItem     *item = new QTreeWidgetItem();

        for( int i = 0; i < run.numberOfSplits(); i++)
        {
            QTreeWidgetItem     *split_item = new QTreeWidgetItem();
            RunDistanceString   split_rs;
            split_rs.setValue( run.split( i)->distance());

            split_item->setText( 0, split_rs.text( 2) + " in " + cTime::t2str( run.split( i)->time()) + " (" +
                        split_rs.pace( run.split( i)->time()) + ")   " + run.split( i)->comment());
            item->addChild( split_item);
        }

        RunDistanceString	rs;
        rs.setValue( run.distance());

        item->setText( 0, QDate::fromJulianDay( jd).toString( "dd-MM-yyyy") + " - " + rs.text( 1) + " in " +
                       cTime::t2str( run.total_time()) + " (" + rs.pace( run.total_time()) + ") - " + run.location());
        item->setData( 0, Qt::UserRole, run.id());

        m_ui->resultsWidget->insertTopLevelItem( 0, item);
    }
}

void SearchRunWidget::on_resultsWidget_itemDoubleClicked(QTreeWidgetItem* item, int column)
{
    int     id = item->data( 0, Qt::UserRole).toInt();

    RunViewer           *re = new RunViewer( id, this);

    re->show();
}
