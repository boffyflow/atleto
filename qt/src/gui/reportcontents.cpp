// $Id: reportcontents.cpp 214 2009-05-28 17:44:45Z robert $
// (c) 2009, Parallel Pixels Ltd.

#include <QDate>

#include "reportcontents.h"
#include "ui_reportcontents.h"

#include "src/gui/barchart.h"

ReportContents::ReportContents(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::ReportContents)
{
    m_ui->setupUi(this);
    mScene.setSceneRect( 0.0, 0.0, 0.0, 0.0);

    m_ui->graphicsView->setScene( &mScene);
}

ReportContents::~ReportContents()
{
    for( int i = 0; i < mControllers.count(); i++)
        delete mControllers[i];

    delete m_ui;
}

void ReportContents::addController( ReportController *controller)
{
    mControllers.append( controller);
    addChart( controller->graph());
}

void ReportContents::addChart( BaseChart *chart)
{
    QRectF      r = mScene.sceneRect();

    mScene.addItem( chart->graphicsItem());
    chart->graphicsItem()->setPos( r.bottomLeft());
}

void ReportContents::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
