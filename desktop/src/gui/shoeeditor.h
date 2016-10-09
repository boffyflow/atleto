// (c) 2009 Parallel Pixels Ltd.
// $Id: shoeeditor.h 294 2010-03-05 18:37:10Z  $

#ifndef SHOEEDITOR_H
#define SHOEEDITOR_H

#include <QDialog>
#include <QTableWidgetItem>

namespace Ui
{
    class ShoeEditor;
}

class ShoeEditor : public QDialog
{
    Q_OBJECT

public:

    ShoeEditor( QWidget *parent = 0, const int id = -1);
    ~ShoeEditor();

protected:

    void changeEvent( QEvent *e);

private:

    void refreshShoeList();
    void loadShoe();
    void saveShoe();

    int                 mShoeId;
    Ui::ShoeEditor      *ui;

private slots:

    void on_activeBox_clicked(bool checked);
    void on_buttonBox_accepted();
};

#endif // SHOEEDITOR_H
