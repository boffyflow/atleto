// (c) 2010 Parallel Pixels Ltd.
// $Id: queryfilter.cpp 370 2010-12-14 23:23:50Z boffyflow $

#include "src/util/queryfilter.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include "src/gui/runlineedit.h"
#include "src/data/data.h"


QueryFilter::QueryFilter( const int filterType) :
        mFilterType( filterType)
{
    if( mFilterType == FILTER_LOCATION)
    {
        createLocationFilter();
    }
    else if( mFilterType == FILTER_DISTANCE)
    {
        createDistanceFilter();
    }
    else if( mFilterType == FILTER_RUNTYPE)
    {
        createRunTypeFilter();
    }
}

void QueryFilter::createLocationFilter()
{
    mLayout = new QHBoxLayout;

    QLabel              *label = new QLabel( tr( "Location contains:"));
    QLineEdit           *lineEdit = new QLineEdit();
    QPushButton         *closeButton = new QPushButton( QIcon( ":/main/icons/close.png"), "");

    closeButton->setFlat( true);

    mWidgets.append( label);
    mWidgets.append( lineEdit);
    mWidgets.append( closeButton);

    mLayout->addWidget( label);
    mLayout->addWidget( lineEdit);
    mLayout->addStretch();
    mLayout->addWidget( closeButton);
    mLayout->setContentsMargins( 3, 3, 3, 3);

    connect( closeButton, SIGNAL( clicked()), this, SLOT( removeFilter()));
}

void QueryFilter::createDistanceFilter()
{
    mLayout = new QHBoxLayout;

    QLabel              *label = new QLabel( tr( "Distance is between:"));
    RunLineEdit         *lineEditFrom = new RunLineEdit();
    QLabel              *labelAnd = new QLabel( tr( "and"));
    RunLineEdit         *lineEditTo = new RunLineEdit();
    QPushButton         *closeButton = new QPushButton( QIcon( ":/main/icons/close.png"), "");

    closeButton->setFlat( true);
    lineEditFrom->setValue( 0.0);
    lineEditFrom->displayValue( 0);
    lineEditTo->setValue( 100000.0);
    lineEditTo->displayValue( 0);

    mWidgets.append( label);
    mWidgets.append( lineEditFrom);
    mWidgets.append( labelAnd);
    mWidgets.append( lineEditTo);
    mWidgets.append( closeButton);

    mLayout->addWidget( label);
    mLayout->addWidget( lineEditFrom);
    mLayout->addWidget( labelAnd);
    mLayout->addWidget( lineEditTo);

    mLayout->addStretch();
    mLayout->addWidget( closeButton);
    mLayout->setContentsMargins( 3, 3, 3, 3);

    connect( closeButton, SIGNAL( clicked()), this, SLOT( removeFilter()));
}

void QueryFilter::createRunTypeFilter()
{
    mLayout = new QHBoxLayout;

    atleto::Data        d;
    QLabel              *label = new QLabel( tr( "Run type:"));
    QComboBox           *comboBox = new QComboBox();
    QPushButton         *closeButton = new QPushButton( QIcon( ":/main/icons/close.png"), "");

    QStringList         runtypes;
    d.runTypes( runtypes);
    comboBox->addItems( runtypes);

    closeButton->setFlat( true);

    mWidgets.append( label);
    mWidgets.append( comboBox);
    mWidgets.append( closeButton);

    mLayout->addWidget( label);
    mLayout->addWidget( comboBox);
    mLayout->addStretch();
    mLayout->addWidget( closeButton);
    mLayout->setContentsMargins( 3, 3, 3, 3);

    connect( closeButton, SIGNAL( clicked()), this, SLOT( removeFilter()));
}


void QueryFilter::removeFilter()
{
    for( int i = 0; i < mWidgets.count(); i++)
    {
        delete mWidgets.at( i);
    }

    emit filterRemoved( mFilterType);

    delete mLayout;
}

QString QueryFilter::result() const
{
    QString     queryResult;

    if( mFilterType == FILTER_LOCATION)
    {
        queryResult = ((QLineEdit *) mWidgets.at( 1))->text();
    }
    else if( mFilterType == FILTER_DISTANCE)
    {
        queryResult = QString::number( ( ( RunLineEdit *) mWidgets.at( 1))->value()) + " " + QString::number( ( ( RunLineEdit *) mWidgets.at( 3))->value());
    }
    else if( mFilterType == FILTER_RUNTYPE)
    {
        queryResult = ((QComboBox *) mWidgets.at( 1))->currentText();
    }

    return queryResult;
}

void QueryFilter::setValueString( const QString &valueString)
{
    if( mFilterType == FILTER_LOCATION)
    {
        ((QLineEdit *) mWidgets.at( 1))->setText( valueString);
    }
    else if( mFilterType == FILTER_DISTANCE)
    {
        QString         dist1 = valueString.split( " ").at( 0);
        QString         dist2 = valueString.split( " ").at( 1);
        ((RunLineEdit *) mWidgets.at( 1))->setValue( dist1.toDouble());
        ((RunLineEdit *) mWidgets.at( 1))->displayValue( 1);
        ((RunLineEdit *) mWidgets.at( 3))->setValue( dist2.toDouble());
        ((RunLineEdit *) mWidgets.at( 3))->displayValue( 1);
    }
    else if( mFilterType == FILTER_RUNTYPE)
    {
        QComboBox   *cb = (QComboBox *) mWidgets.at( 1);
        cb->setCurrentIndex( cb->findText( valueString));
    }
}
