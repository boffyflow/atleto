// $Id: ploteditor.h 369 2010-09-25 00:02:33Z boffyflow $
// (c) 2006, Parallel Pixels Ltd.

#ifndef PLOTEDITOR_H
#define PLOTEDITOR_H

#include <QDialog>
#include "src/data/plot.h"

namespace Ui
{
    class PlotEditor;
}

class PlotEditor : public QDialog
{
    Q_OBJECT

public:

    PlotEditor( QWidget *parent = 0);
    ~PlotEditor();

protected:

    void changeEvent( QEvent *e);
    void resizeEvent( QResizeEvent *e);

private:

    Ui::PlotEditor  *ui;

private slots:
    void on_pushButton_clicked();
};

#endif // PLOTEDITOR_H
