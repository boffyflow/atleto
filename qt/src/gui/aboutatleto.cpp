// (c) 2009 Parallel Pixels Ltd.
// $Id: aboutatleto.cpp 324 2010-03-16 22:33:59Z boffyflow $

#include "aboutatleto.h"
#include "ui_aboutatleto.h"

#include "src/util/version.h"

AboutAtleto::AboutAtleto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutAtleto)
{
    ui->setupUi(this);

    QString     version = "Atleto v" + ATLETO_MAJ + "." + ATLETO_MIN + "." + ATLETO_MIN_REV + "." + BUILD;
    ui->aboutLabel->setText( version);
}

AboutAtleto::~AboutAtleto()
{
    delete ui;
}

void AboutAtleto::changeEvent(QEvent *e)
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
