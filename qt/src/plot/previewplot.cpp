// (c) 2009 Parallel Pixels Ltd.
// $Id: previewplot.cpp 324 2010-03-16 22:33:59Z boffyflow $

#include "previewplot.h"
#include "ui_previewplot.h"

PreviewPlot::PreviewPlot( const QFile &svgFile, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreviewPlot)
{
    ui->setupUi(this);

    ui->plotView->setMinimumSize( 640, 480);
    ui->plotView->openFile( svgFile);
}

PreviewPlot::~PreviewPlot()
{
    delete ui;
}

void PreviewPlot::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
