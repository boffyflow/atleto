// (c) 2009 Parallel Pixels Ltd.
// $Id: previewplot.h 324 2010-03-16 22:33:59Z boffyflow $

#ifndef PREVIEWPLOT_H
#define PREVIEWPLOT_H

#include <QDialog>
#include <QFile>

namespace Ui
{
    class PreviewPlot;
}

class PreviewPlot : public QDialog
{
    Q_OBJECT
public:

    PreviewPlot( const QFile &svgFileName, QWidget *parent = 0);
    ~PreviewPlot();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::PreviewPlot *ui;
};

#endif // PREVIEWPLOT_H
