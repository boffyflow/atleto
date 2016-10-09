// $Id: weightwidget.cpp 223 2009-06-12 00:16:18Z robert $
// (c) 2009, Parallel Pixels Ltd.

#include <QLabel>
#include <QDomDocument>

#include "src/gui/weightwidget.h"
#include "ui_graphwidget.h"
#include "src/controller/weightcontroller.h"

WeightWidget::WeightWidget( QWidget *parent) : GraphWidget( parent)
{
    m_ui->mainBox->setTitle( "Weight Graph");

    QGridLayout     *grid = new QGridLayout( m_ui->contents);
    grid->addWidget( new QLabel( "No Settings"));
}

WeightWidget::~WeightWidget()
{
}

ReportController *WeightWidget::controller()
{
    return new WeightController();
}

void WeightWidget::addElement( QDomDocument *doc)
{
    QDomElement     rootElem = doc->firstChildElement( "Report");
    QDomElement     elem = doc->createElement( "Weight");
    rootElem.appendChild( elem);
}
