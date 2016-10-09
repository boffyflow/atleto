// $Id: ploteditor.cpp 369 2010-09-25 00:02:33Z boffyflow $
// (c) 2010, Parallel Pixels Ltd.

#include "ploteditor.h"
#include "ui_ploteditor.h"


PlotEditor::PlotEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlotEditor)
{
    ui->setupUi(this);
}

PlotEditor::~PlotEditor()
{
    delete ui;
}

void PlotEditor::changeEvent(QEvent *e)
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

void PlotEditor::resizeEvent( QResizeEvent *e)
{
    QDialog::resizeEvent(e);

//    mPlot->resize( ui->contentFrame->size());
}


void PlotEditor::on_pushButton_clicked()
{
    QDialog::accept();
}
