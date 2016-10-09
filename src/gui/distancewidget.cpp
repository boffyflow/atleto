// $Id: distancewidget.cpp 221 2009-06-05 23:57:04Z robert $
// (c) 2009, Parallel Pixels Ltd.

#include <QLabel>
#include <QDomDocument>

#include "src/gui/distancewidget.h"
#include "ui_graphwidget.h"
#include "src/controller/distancecontroller.h"

DistanceWidget::DistanceWidget( QWidget *parent) : GraphWidget( parent)
{
    m_ui->mainBox->setTitle( "Distance Graph");

    QGridLayout     *grid = new QGridLayout( m_ui->contents);
    grid->addWidget( new QLabel( "No Settings"));
}

DistanceWidget::~DistanceWidget()
{
}

ReportController *DistanceWidget::controller()
{
    return new DistanceController();
}

void DistanceWidget::addElement( QDomDocument *doc)
{
    QDomElement     rootElem = doc->firstChildElement( "Report");
    QDomElement     elem = doc->createElement( "Distance");
    rootElem.appendChild( elem);
}
