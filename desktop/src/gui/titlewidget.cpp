// $Id: titlewidget.cpp 221 2009-06-05 23:57:04Z robert $
// (c) 2009, Parallel Pixels Ltd.

#include <QCheckBox>

#include "src/gui/titlewidget.h"
#include "ui_graphwidget.h"
#include "src/controller/titlecontroller.h"

TitleWidget::TitleWidget( QWidget *parent) : GraphWidget( parent)
{
    m_ui->mainBox->setTitle( "Title");

    QGridLayout     *grid = new QGridLayout( m_ui->contents);
    grid->addWidget( new QCheckBox( "version"));
    grid->addWidget( new QCheckBox( "date"));
}

TitleWidget::~TitleWidget()
{
}

ReportController *TitleWidget::controller()
{
    return new TitleController();
}

void TitleWidget::addElement( QDomDocument *doc)
{
    QDomElement     rootElem = doc->firstChildElement( "Report");
    QDomElement     elem = doc->createElement( "Title");
    rootElem.appendChild( elem);
}
