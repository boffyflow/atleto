// $Id: runviewer.h 371 2010-12-14 23:25:23Z boffyflow $
// (c) 2010 Parallel Pixels Ltd.

#ifndef RUNVIEWER_H
#define RUNVIEWER_H

#include <QDialog>
#include "src/data/run.h"

namespace Ui
{
    class RunViewer;
}

class RunViewer : public QDialog
{
    Q_OBJECT

public:
    explicit RunViewer( const int run_id, QWidget *parent = 0);
    ~RunViewer();

private:

    void	populateTable();
    void        updateLabels();
    void        updatePlot();
    void        loadRun();

    Ui::RunViewer       *ui;
    Run                 mRun;
    int                 mRunId;
    bool                mShowPace;
    bool                mShowHeartrate;

private slots:
    void on_inputTable_itemSelectionChanged();
    void on_editRunButton_clicked();
    void on_paceCheckBox_clicked();
    void on_hrCheckBox_clicked();
};

#endif // RUNVIEWER_H
