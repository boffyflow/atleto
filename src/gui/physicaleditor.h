// $Id: physicaleditor.h 357 2010-04-07 17:42:35Z boffyflow $
// (c) 2009, Parallel Pixels Ltd.

#ifndef PHYSICALEDITOR_H
#define PHYSICALEDITOR_H

#include <QDialog>
#include <QDate>

#include "src/data/physical.h"

namespace Ui
{
    class PhysicalEditor;
}

class PhysicalEditor : public QDialog
{
    Q_OBJECT

public:


    PhysicalEditor( const QDate &date, const int id = -1, QWidget *parent = 0);
    ~PhysicalEditor();

protected:

    void changeEvent(QEvent *e);

private:

    void    displayBMI();

    Physical            mPhysical;
    Ui::PhysicalEditor  *ui;

private slots:
    void on_weightEdit_editingFinished();
    void on_deleteButton_clicked();
    void on_buttonBox_accepted();
};

#endif // PHYSICALEDITOR_H
