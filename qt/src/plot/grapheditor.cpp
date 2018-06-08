// (c) 2010 Parallel Pixels Ltd.
// $Id: grapheditor.cpp 372 2013-03-05 22:04:13Z boffyflow $

#include "src/plot/grapheditor.h"
#include "ui_grapheditor.h"
#include "src/data/graph.h"
#include "src/gui/mainwindow.h"

GraphEditor::GraphEditor( Graph *graph, QWidget *parent) :
    QDialog( parent),
    ui( new Ui::GraphEditor)
{
    mGraph = graph;
    ui->setupUi(this);

    // populate combo box
    ui->templateCombo->addItems( MainWindow::getInstance()->templateMap().keys());

    // load or default ui
    ui->nameLineEdit->setText( mGraph->name());
    if( mGraph->id() >= 0)
        ui->templateCombo->setCurrentIndex( ui->templateCombo->findText( mGraph->templateName()));
    ui->queryWidget->setQueryParameters( mGraph->queryParameters());

    setWindowTitle( mGraph->name());
}

GraphEditor::~GraphEditor()
{
    delete ui;
}

void GraphEditor::changeEvent( QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type())
    {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;
        default:
            break;
    }
}

void GraphEditor::accept()
{
    mGraph->setName( ui->nameLineEdit->text());
    mGraph->setTemplateName( ui->templateCombo->currentText());
    mGraph->setQueryParameters( ui->queryWidget->queryParameters());
    mGraph->save( mGraph->id());

    setWindowTitle( mGraph->name());

    QDialog::accept();
}



