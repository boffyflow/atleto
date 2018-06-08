// (c) 2009 Parallel Pixels Ltd.
// $Id: numericaltablewidgetitem.cpp 294 2010-03-05 18:37:10Z  $

#include "numericaltablewidgetitem.h"

NumericalTableWidgetItem::NumericalTableWidgetItem(  const QString &text)
    : QTableWidgetItem( text)
{
}


bool NumericalTableWidgetItem::operator< ( const QTableWidgetItem &other ) const
{
    if( data( Qt::UserRole + 1).toDouble() < other.data( Qt::UserRole + 1).toDouble())
        return true;
    else
        return false;
}
