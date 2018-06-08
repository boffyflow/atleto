// (c) 2009 Parallel Pixels Ltd.
// $Id: shoelist.h 369 2010-09-25 00:02:33Z boffyflow $

#ifndef SHOELIST_H
#define SHOELIST_H

#include <QDialog>
#include <QTableWidgetItem>
#include <QFile>

namespace Ui {
    class ShoeList;
}

class ShoeList : public QDialog
{
    Q_OBJECT

public:

    ShoeList(QWidget *parent = 0);
    ~ShoeList();

protected:

    void changeEvent(QEvent *e);

private:

    void refreshShoeList();
    void editShoe( const int id);

    bool            mShowOnlyActive;
    Ui::ShoeList    *ui;

private slots:

    void on_addButton_clicked();
    void on_tableWidget_itemSelectionChanged();
    void on_editButton_clicked();
    void on_tableWidget_itemDoubleClicked( QTableWidgetItem* item);
    void on_showActiveCheckBox_clicked( bool checked);
};

#endif // SHOELIST_H
