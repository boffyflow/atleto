// $Id: journaleditor.cpp 294 2010-03-05 18:37:10Z  $
// (c) 2009, Parallel Pixels Ltd.

#include "journaleditor.h"
#include "ui_journaleditor.h"

#include "src/data/run.h"
#include "src/util/rununits.h"
#include "src/data/physical.h"
#include "src/util/weightunits.h"
#include "src/util/ctime.h"

JournalEditor::JournalEditor( const QDate &day, const int id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JournalEditor)
{
    ui->setupUi(this);

    if( id > 0)
    {
        mEntry.restore( id);
    }
    else
    {
        mEntry.restoreByJulianDay( day.toJulianDay());
    }

    QDate       day2 = QDate::fromJulianDay( mEntry.julianDay());

    setWindowTitle( "Journal entry for " + day2.toString( "ddd - MMM d"));


    QList<Run>      runList = Run::runList( day2, day2);
    float       dist = 0.0;
    float       t = 0.0;
    QString     location;
    for( int i = 0; i < runList.count(); i++)
    {
        dist += runList.at( i).distance();
        t += runList.at( i).total_time();
        location.append( runList.at( i).location() + ", ");
    }
    if( !location.isEmpty())
        location.chop( 2);

    RunDistanceString       rs;
    rs.setValue( dist);
    ui->distLabel->setText( rs.text() + " in " + cTime::t2str( t) + " at " + rs.pace( t));
    ui->locationLabel->setText( location);

    Physical        p;
    p.restoreByJulianDay( day2.toJulianDay());
    WeightString        ws;
    if( p.id() > 0)
    {
        ws.setValue( p.weight());
    }
    else
    {
        ws.setValue( 0.0);
    }
    ui->weightLabel->setText( ws.text());

    if( mEntry.id() > 0)
    {
        ui->entryEdit->setHtml( mEntry.entry());
    }
}

JournalEditor::~JournalEditor()
{
    delete ui;
}

void JournalEditor::changeEvent(QEvent *e)
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

void JournalEditor::on_buttonBox_accepted()
{
    mEntry.setEntry( ui->entryEdit->toHtml());
    mEntry.save();
}

void JournalEditor::on_deleteButton_clicked()
{
    if( mEntry.id() > 0)
        mEntry.remove();

    close();
}
