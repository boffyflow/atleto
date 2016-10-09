// $Id: shoestatswidget.cpp 243 2009-09-18 23:55:23Z robert $
// (c) 2009, Parallel Pixels Ltd.

#include <QLabel>
#include <QDomDocument>

#include "src/gui/shoestatswidget.h"
#include "ui_graphwidget.h"
#include "src/controller/shoestatscontroller.h"

ShoeStatsWidget::ShoeStatsWidget( QWidget *parent) : GraphWidget( parent)
{
    m_ui->mainBox->setTitle( "Shoe Stats Graph");

    QGridLayout     *grid = new QGridLayout( m_ui->contents);
    grid->addWidget( new QLabel( "No Settings"));
}

ShoeStatsWidget::~ShoeStatsWidget()
{
}

ReportController *ShoeStatsWidget::controller()
{
    return new ShoeStatsController();
}

void ShoeStatsWidget::addElement( QDomDocument *doc)
{
    QDomElement     rootElem = doc->firstChildElement( "Report");
    QDomElement     elem = doc->createElement( "ShoeStats");
    rootElem.appendChild( elem);
}
