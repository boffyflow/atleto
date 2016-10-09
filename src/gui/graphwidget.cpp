// $Id: graphwidget.cpp 214 2009-05-28 17:44:45Z robert $
// (c) 2009, Parallel Pixels Ltd.

#include "src/gui/graphwidget.h"
#include "ui_graphwidget.h"

GraphWidget::GraphWidget( QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::GraphWidget)
{
    m_ui->setupUi(this);
}

GraphWidget::~GraphWidget()
{
    delete m_ui;
}

void GraphWidget::disable( const int direction)
{
    if( direction == GRAPHWIDGET_UP)
        m_ui->upButton->setEnabled( false);
    else if( direction == GRAPHWIDGET_DOWN)
        m_ui->downButton->setEnabled( false);
}

void GraphWidget::enable( const int direction)
{
    if( direction == GRAPHWIDGET_UP)
        m_ui->upButton->setEnabled( true);
    else if( direction == GRAPHWIDGET_DOWN)
        m_ui->downButton->setEnabled( true);
}


void GraphWidget::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void GraphWidget::on_upButton_clicked()
{
    emit up( this);
}

void GraphWidget::on_downButton_clicked()
{
    emit down( this);
}

void GraphWidget::on_closeButton_clicked()
{
    emit close( this);
}
