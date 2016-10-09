// (c) 2009 Parallel Pixels Ltd.
// $Id: shoelist.cpp 370 2010-12-14 23:23:50Z boffyflow $

#include "shoelist.h"
#include "ui_shoelist.h"

#include <QList>
#include <QProcess>
#include <QTextStream>
#include <QDir>

#include "src/data/shoe.h"
#include "src/util/rununits.h"
#include "src/gui/shoeeditor.h"
#include "src/util/numericaltablewidgetitem.h"
#include "src/plot/gnuplotcommand.h"
#include "src/plot/plotseries.h"
#include "src/plot/plotpoint.h"
#include "src/plot/plotgraph.h"
#include "src/data/settings.h"

ShoeList::ShoeList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShoeList)
{
    ui->setupUi( this);

    mShowOnlyActive = ui->showActiveCheckBox->isChecked();

    ui->shoePlot->setMinimumSize( 600, 480);

    refreshShoeList();
}

ShoeList::~ShoeList()
{
    delete ui;
}

void ShoeList::refreshShoeList()
{
    PlotSeries      plotData;

    ui->tableWidget->clear();

    QList<Shoe>     shoeList = Shoe::shoeList();
    QVector<int>    indices;

    for( int i = 0; i < shoeList.count(); i++)
    {
        if( mShowOnlyActive)
        {
            if( shoeList.at( i).active())
            {
                indices.append( i);
            }
        }
        else
        {
            indices.append( i);
        }
    }

    ui->tableWidget->setRowCount( indices.count());

    for( int row = 0; row < indices.count(); row++)
    {
        Shoe        s = shoeList.at( indices.at( row));
        bool        pointflag = true;

        QTableWidgetItem        *nameItem = new QTableWidgetItem( s.name());
        nameItem->setData( Qt::UserRole, s.id());
        ui->tableWidget->setItem( row, 0, nameItem);
        RunDistanceString       distance;
        distance.setValue( s.mileage());
        if( s.mileage() > s.maxMileage())
            pointflag = false;
        plotData.addPoint( PlotPoint( 1.0 * row, distance.text( 0, false).toDouble(), s.name(), distance.text( 0), pointflag));
        NumericalTableWidgetItem   *mileageItem = new NumericalTableWidgetItem( distance.text( 0, true));
        mileageItem->setData( Qt::UserRole, s.id());
        mileageItem->setData( Qt::UserRole + 1, s.mileage());
        ui->tableWidget->setItem( row, 1, mileageItem);
        if( s.mileage() > s.maxMileage())
        {
            nameItem->setForeground( QBrush( QColor( Qt::red)));
            mileageItem->setForeground( QBrush( QColor( Qt::red)));
        }
        if( !s.active()) // make italic and strike through non active shoes
        {
            QFont   fn = nameItem->font();
            fn.setItalic( true);
            fn.setStrikeOut( true);
            nameItem->setFont( fn);
            QFont   fm = mileageItem->font();
            fm.setItalic( true);
            fm.setStrikeOut( true);
            mileageItem->setFont( fm);
        }
    }

    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->sortItems( 1, Qt::DescendingOrder);

    // sort data by mileage
    RunUnits        ru;

    plotData.sort( PLOT_SORT_Y);
    plotData.setUnitStringY( ru.current());
    plotData.setColor( Qt::darkGreen);

    ui->shoePlot->setTitle( tr( "Shoe usage"));
    ui->shoePlot->addGraph( new PlotGraph( plotData));
    ui->shoePlot->draw();
}

void ShoeList::on_showActiveCheckBox_clicked( bool checked)
{
    mShowOnlyActive = checked;
    refreshShoeList();
}

void ShoeList::changeEvent(QEvent *e)
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

void ShoeList::on_tableWidget_itemDoubleClicked(QTableWidgetItem* item)
{
    editShoe( item->data( Qt::UserRole).toInt());
}

void ShoeList::editShoe( const int id)
{
    ShoeEditor      shoeEditor( this, id);

    shoeEditor.exec();

    if( shoeEditor.result() == QDialog::Accepted)
        refreshShoeList();
}

void ShoeList::on_editButton_clicked()
{
    QTableWidgetItem    *item = ui->tableWidget->currentItem();

    editShoe( item->data( Qt::UserRole).toInt());
}

void ShoeList::on_tableWidget_itemSelectionChanged()
{
    if( ui->tableWidget->selectedItems().count() == 0)
        ui->editButton->setEnabled( false);
    else
        ui->editButton->setEnabled( true);
}

void ShoeList::on_addButton_clicked()
{
    editShoe( -1);
}
