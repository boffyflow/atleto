// (c) 2009 Parallel Pixels Ltd.
// $Id: runeditor.h 361 2010-05-27 00:05:54Z boffyflow $

#ifndef RUNEDITOR_H
#define RUNEDITOR_H

#include <QtWidgets/QDialog>
#include <QDate>
#include <QStandardItem>

#include "src/data/runrace.h"
#include "src/data/run.h"

namespace Ui
{
    class RunEditor;
}

class RunEditor : public QDialog
{
    Q_OBJECT
    Q_DISABLE_COPY( RunEditor)

public:

    explicit    RunEditor( const QDate& day, const int run_id, QWidget *parent = 0);
    virtual     ~RunEditor();

protected:

    virtual void changeEvent( QEvent *e);

private:

    Ui::RunEditor       *m_ui;
    QDate               mDate;
    int                 mRunId;
    QStandardItemModel  *mModel;
    RunRace             mRace;
    Run                 mRun;

    void        setDefaultValues();
    void        restoreValues();
    void	buildTableModel();
    void	updatePace( const int row);
    void	updateLabels();

private slots:

    void on_reloadButton_clicked();
    void    on_deleteButton_clicked();
    void    on_raceCheckBox_toggled(bool checked);
    void    updateTable( QStandardItem *item);
    void    storeRun();
    void    setRaceInfo();
};

#endif // RUNEDITOR_H
