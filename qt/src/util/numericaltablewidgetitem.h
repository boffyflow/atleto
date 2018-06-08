// (c) 2009 Parallel Pixels Ltd.
// $Id: numericaltablewidgetitem.h 294 2010-03-05 18:37:10Z  $

#ifndef NUMERICALTABLEWIDGETITEM_H
#define NUMERICALTABLEWIDGETITEM_H

#include <QTableWidgetItem>

class NumericalTableWidgetItem : public QTableWidgetItem
{
public:

    NumericalTableWidgetItem(  const QString &text);

    bool operator<(const QTableWidgetItem &other ) const;
};

#endif // NUMERICALTABLEWIDGETITEM_H
