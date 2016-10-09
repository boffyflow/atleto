// $Id: graphwidget.cpp 372 2013-03-05 22:04:13Z boffyflow $
// (c) 2010, Parallel Pixels Ltd.

#include <QFile>

#include "src/plot/graphwidget.h"
#include "ui_graphwidget.h"

#include "src/plot/grapheditor.h"
#include "src/data/graph.h"
#include "src/gui/mainwindow.h"
//#include "src/data/series.h"


GraphWidget::GraphWidget( Graph *props, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphWidget)
{
    ui->setupUi(this);

    mProps = props;
}

GraphWidget::~GraphWidget()
{
    delete ui;
    delete mProps;
}

void GraphWidget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void GraphWidget::closeEvent( QCloseEvent *event)
{
    mProps->remove();

    QWidget::closeEvent( event);
}

void GraphWidget::on_propsButton_clicked()
{
    GraphEditor     ge( mProps, this);

    if( ge.exec() == QDialog::Accepted)
    {
        emit titleChanged();
        return;
    }
}

void GraphWidget::on_csvButton_clicked()
{
    QFile       f( MainWindow::getInstance()->templateMap().value( mProps->templateName()));

    if( f.open( QIODevice::ReadOnly | QIODevice::Text))
    {
        QString     name = f.readLine().trimmed();
        QStringList s = ((QString ) f.readLine()).trimmed().split( ',');

//        Series      series( name);

        for( int i = 0; i < s.size(); i++)
        {
//            series.addSeries( s.at( i));
        }
//        series.setTimeFrame( mProps->queryParameters()->startDate(), mProps->queryParameters()->endDate());

//        series.toCSV( "dummy.csv");
    }
}
