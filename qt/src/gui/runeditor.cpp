// (c) 2009 Parallel Pixels Ltd.
// $Id: runeditor.cpp 370 2010-12-14 23:23:50Z boffyflow $

#include <QCompleter>
#include <QFileDialog>
#include <QMessageBox>

#include "runeditor.h"
#include "ui_runeditor.h"

#include "src/data/data.h"
#include "runlineedit.h"
#include "src/util/runtabledelegate.h"
#include "src/util/ctime.h"
#include "src/util/cgeneral.h"
#include "src/util/tcximporter.h"
#include "src/gui/raceinfodialog.h"
#include "src/gui/mainwindow.h"
#include "src/data/run.h"
#include "src/data/split.h"
#include "src/data/shoe.h"

using namespace atleto;

RunEditor::RunEditor(  const QDate& day, const int run_id, QWidget *parent) :
    QDialog( parent),
    m_ui( new Ui::RunEditor),
    mRunId( run_id)
{
    m_ui->setupUi(this);

    setDefaultValues();

    if( mRunId > 0)
    {
        mRun.restore( mRunId);
        mDate = QDate::fromJulianDay( mRun.julianDay());
        mRace.restoreByRunId( mRunId);
        restoreValues();
    }
    else
    {
        if( day.isValid())
            mDate = day;
        else
            mDate = QDate::currentDate();
    }

    setWindowTitle( "Edit run for " + mDate.toString( "ddd, MMM d"));

    buildTableModel();
    updateLabels();

    QCompleter      *c1 = new QCompleter( m_ui->locationComboBox->model(), this);
    m_ui->locationComboBox->setCompleter( c1);

    QCompleter      *c2 = new QCompleter( m_ui->surfaceComboBox->model(), this);
    m_ui->surfaceComboBox->setCompleter( c2);

    QCompleter      *c3 = new QCompleter( m_ui->runTypesComboBox->model(), this);
    m_ui->runTypesComboBox->setCompleter( c3);

    connect( mModel, SIGNAL( itemChanged( QStandardItem *)), this, SLOT( updateTable( QStandardItem *)));
    connect( m_ui->buttonBox, SIGNAL( accepted()), this, SLOT( storeRun()));
    connect( m_ui->raceInfoButton, SIGNAL( clicked()), this, SLOT( setRaceInfo()));
}

RunEditor::~RunEditor()
{
    delete m_ui;
}

void RunEditor::changeEvent(QEvent *e)
{
    switch( e->type())
    {
        case QEvent::LanguageChange:
            m_ui->retranslateUi(this);
            break;
        default:
            break;
    }
}

void RunEditor::setDefaultValues()
{
    QTime       end_time( QTime::currentTime().hour(), 0, 0);

    m_ui->startTimeEdit->setTime( end_time.addSecs( -3600));
    m_ui->endTimeEdit->setTime( end_time);

    Data            data;
    QStringList     strings;
    QList<int>      ids;

    data.list( "locations", strings, ids);
    for( int i = 0; i < strings.size(); i++)
        m_ui->locationComboBox->addItem( strings[i], ids[i]);
    m_ui->locationComboBox->setCurrentIndex( m_ui->locationComboBox->findText( "unknown"));

    strings.clear();
    ids.clear();
    data.list( "run_types", strings, ids);
    for( int i = 0; i < strings.size(); i++)
        m_ui->runTypesComboBox->addItem( strings[i], ids[i]);
    m_ui->runTypesComboBox->setCurrentIndex( m_ui->runTypesComboBox->findText( "unknown"));

    strings.clear();
    ids.clear();
    data.list( "surfaces", strings, ids);
    for( int i = 0; i < strings.size(); i++)
        m_ui->surfaceComboBox->addItem( strings[i], ids[i]);
    m_ui->surfaceComboBox->setCurrentIndex( m_ui->surfaceComboBox->findText( "unknown"));

    QList<Shoe>     shoeList = Shoe::shoeList();
    for( int i = 0; i < shoeList.count(); i++)
    {
        Shoe        s = shoeList.at( i);
        m_ui->shoeComboBox->addItem( s.name(), s.id());
        if( !s.active())
            ((QStandardItemModel *) m_ui->shoeComboBox->model())->item( i)->setEnabled( false);
    }
    m_ui->shoeComboBox->setCurrentIndex( m_ui->shoeComboBox->findText( "unknown"));

    m_ui->distanceLabel->setText( "");
    m_ui->timeLabel->setText( "");
    m_ui->paceLabel->setText( "");
    m_ui->hrLabel->setText( "");
}

void RunEditor::restoreValues()
{
    m_ui->startTimeEdit->setTime( mRun.starttime());
    m_ui->endTimeEdit->setTime( mRun.endtime());
    m_ui->locationComboBox->setCurrentIndex( m_ui->locationComboBox->findText( mRun.location()));
    m_ui->runTypesComboBox->setCurrentIndex( m_ui->runTypesComboBox->findText( mRun.kindofworkout()));
    m_ui->surfaceComboBox->setCurrentIndex( m_ui->surfaceComboBox->findText( mRun.surface()));
    m_ui->commentLineEdit->setText( mRun.comment());
    m_ui->ratingComboBox->setCurrentIndex( mRun.rating());
    m_ui->shoeComboBox->setCurrentIndex( m_ui->shoeComboBox->findText( mRun.shoeId()));

    if( mRace.id() > -1)
    {
        m_ui->raceCheckBox->setChecked( true);
        m_ui->raceInfoButton->setText( mRace.raceName() + "...");
    }

    if( mRun.deviceFile().isEmpty())
    {
        m_ui->deviceFileLabel->hide();
        m_ui->reloadButton->hide();
    }
    else
    {
        m_ui->deviceFileLabel->setText( mRun.deviceFile());
        m_ui->deviceFileLabel->show();
        m_ui->reloadButton->show();
    }
}

void RunEditor::on_raceCheckBox_toggled( bool checked)
{
    m_ui->raceInfoButton->setEnabled( checked);
}

void
RunEditor::buildTableModel()
{
    int				nrows = 1;
    bool			nodata = false;


    if( mRun.numberOfSplits() > 0)
        nrows = mRun.numberOfSplits();
    else
        nodata = true;

    mModel = new QStandardItemModel( nrows, 5, m_ui->inputTable);

    m_ui->inputTable->setModel( mModel);
    m_ui->inputTable->setItemDelegate( new RunTableDelegate( m_ui->inputTable));
    m_ui->inputTable->setEditTriggers(QAbstractItemView::CurrentChanged);

    // Build the input table

    for( int row = 0; row < nrows; row++)
    {
        for( int column = 0; column < 5; column++)
        {
            QModelIndex			index = mModel->index( row, column, QModelIndex());
            RunDistanceString	rs;

            if( nodata)	// empty table
            {
                rs.setValue( 0.0);

                if( column == 0)
                {
                    mModel->setData( index, 0.0, Qt::UserRole);
                    mModel->setData( index, rs.text( 2), Qt::DisplayRole);
                }
                else if( column == 1)
                {
                    mModel->setData( index, QVariant( QTime( 0, 0, 0)));
                }
                else if( column == 2)
                {
                    mModel->setData( index, rs.pace( 0), Qt::DisplayRole);
                }
                else
                {
                    mModel->setData( index, "");
                }
            }
            else
            {
                Split       *s = mRun.split( row);
                rs.setValue( s->distance());

                if( column == 0)	// distance
                {
                    mModel->setData( index, s->distance(), Qt::UserRole);
                    mModel->setData( index, rs.text( 2), Qt::DisplayRole);
                }
                else if( column == 1)	// time
                {
                    mModel->setData( index, QTime( 0, 0, 0).addSecs( cGeneral::rnd( s->time())).toString( "HH:mm:ss"));
                }
                else if( column == 2)	// pace
                {
                    mModel->setData( index, rs.pace( cGeneral::rnd( s->time())), Qt::DisplayRole);
                }
                else if( column == 3)	// heartrate
                {
                    mModel->setData( index, s->heartrate());
                }
                else if( column == 4)	// comment
                {
                    mModel->setData( index, s->comment());
                }
            }
        }
    }

    mModel->setHeaderData( 0, Qt::Horizontal, "Distance");
    mModel->setHeaderData( 1, Qt::Horizontal, "Time");
    mModel->setHeaderData( 2, Qt::Horizontal, "Pace");
    mModel->setHeaderData( 3, Qt::Horizontal, "Heartrate");
    mModel->setHeaderData( 4, Qt::Horizontal, "Comment");

    m_ui->inputTable->resizeRowsToContents();
    m_ui->inputTable->resizeColumnsToContents();
    m_ui->inputTable->setColumnWidth( 1, 90);

    if( nrows >= 1)
        updateTable( mModel->item( mModel->rowCount() - 1));
}

void
RunEditor::updateTable( QStandardItem *item)
{
    int		row = item->row();

    updatePace( row);
    updateLabels();

    // append a new row if the change occurred on the last row in the table
    if( row == mModel->rowCount() - 1)
    {
        QList<QStandardItem *>		itemList;
        for( int i = 0; i < 5; i++)
        {
            QStandardItem		*item = new QStandardItem( "");
            itemList.append( item);
        }
        mModel->appendRow( itemList);
        m_ui->inputTable->resizeRowsToContents();
    }
}

void
RunEditor::updatePace( const int row)
{
    QStandardItem		*distanceItem = mModel->item( row, 0);
    QStandardItem		*timeItem = mModel->item( row, 1);

    RunDistanceString		distance;

    distance.setText( distanceItem->data( Qt::DisplayRole).toString());
    QTime		t = timeItem->data( Qt::EditRole).toTime();
    int			nsecs = t.second() + t.minute() * 60 + t.hour() * 3600;

    QString		pstr = distance.pace( nsecs);

    QStandardItem		*paceItem = mModel->item( row, 2);
    paceItem->setData( pstr, Qt::DisplayRole);
}

void
RunEditor::updateLabels()
{
    double		d = 0.0;
    double		t = 0.0;
    double              hsecs = 0.0;
    int			hr = 0;

    RunDistanceString		distance;

    if( mModel->rowCount() > 1)
    {
        for( int i = 0; i < ( mModel->rowCount() - 1); i++)
        {
            distance.setValue( mModel->item( i, 0)->data( Qt::UserRole).toDouble());
            QTime		tt = mModel->item( i, 1)->data( Qt::EditRole).toTime();

            double      secs;
            int         h;

            d += distance.value();
            secs = tt.second() + tt.minute() * 60 + tt.hour() * 3600;
            t += secs;

            h = mModel->item( i, 3)->data( Qt::EditRole).toInt();

            if( h != 0 && secs != 0)
            {
                hr += ( h * secs);
                hsecs += secs;
            }
        }
    }

    distance.setValue( d);

    m_ui->distanceLabel->setText( distance.text());
    m_ui->timeLabel->setText( cTime::t2str( t));
    m_ui->paceLabel->setText( distance.pace( t));
    m_ui->hrLabel->setText( "");
    int		aveHR = 0;
    if( hr > 0)
    {
        // average heartrate is weighted by split duration

        aveHR = cGeneral::rnd( (double) hr / hsecs);
        if( aveHR > 0)
            m_ui->hrLabel->setText( QString::number( aveHR));
    }
}

void
RunEditor::storeRun()
{
    mRun.setJulianDay( mDate.toJulianDay());
    mRun.setLocation( m_ui->locationComboBox->currentText());
    mRun.setStartTime( m_ui->startTimeEdit->time());
    mRun.setEndTime( m_ui->endTimeEdit->time());
    mRun.setComment( m_ui->commentLineEdit->text());
    mRun.setRating( m_ui->ratingComboBox->currentIndex());
    mRun.setIndoors( m_ui->indoorsCheckBox->isChecked());
    mRun.setSurface( m_ui->surfaceComboBox->currentText());
    mRun.setShoe( m_ui->shoeComboBox->currentText());
    mRun.setKindOfWorkout( m_ui->runTypesComboBox->currentText());

    mRun.removeAllSplits();     // remove all splits from memory to avoid adding splits.

    for( int i = 0; i < mModel->rowCount(); i++)
    {
        QTime		tt = mModel->item( i, 1)->data( Qt::EditRole).toTime();
        double		d = mModel->item( i, 0)->data( Qt::UserRole).toDouble();
        double		t = tt.second() + tt.minute() * 60.0 + tt.hour() * 3600.0;

        if( d > 0.0)
        {
            Split	*s = new Split( d, t, mModel->item( i, 3)->data( Qt::EditRole).toInt(), mModel->item( i, 4)->data( Qt::EditRole).toString());

            mRun.addSplit( s);
        }
    }

    mRun.save( mRunId);

    if( m_ui->raceCheckBox->isChecked())
    {
        mRace.setRunId( mRunId);
        mRace.save( mRace.id());
    }
    else
    {
        mRace.remove();
    }

    MainWindow::getInstance()->updateStatus();
}

void RunEditor::setRaceInfo()
{
    RaceInfoDialog			ri( this);

    ri.setRunRace( mRace);
    if( ri.exec() == QDialog::Accepted)
    {
        mRace = ri.runRace();

        m_ui->raceInfoButton->setText( mRace.raceName() + "...");
    }
}

void RunEditor::on_deleteButton_clicked()
{
    mRace.remove();
    mRun.remove();

    MainWindow::getInstance()->updateStatus();

    accept();
}


void RunEditor::on_reloadButton_clicked()
{
    QSettings       settings;
    QFileInfo       dbFile = settings.value( "Options/dbfilename").toString();
    QFileInfo       tcxFile( dbFile.absoluteDir().absolutePath() + "/" + mRun.deviceFile());

    TcxImporter     tcxImporter;

    int     answer = QMessageBox::question( this, tr( "Reload Run data"),
                           tr( "Are you sure you want to reload the Run data? All information will be replaced with data from the device file."),
                           QMessageBox::Yes|QMessageBox::No);

    if( answer == QMessageBox::Yes)
    {
        mRun.removeAllSplits();
        tcxImporter.loadDeviceData( &mRun, tcxFile);

        restoreValues();
        buildTableModel();
        updateLabels();
    }
}
