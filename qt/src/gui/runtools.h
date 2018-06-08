// (c) 2010 Parallel Pixels Ltd.
// $Id: runtools.h 294 2010-03-05 18:37:10Z  $

#ifndef RUNTOOLS_H
#define RUNTOOLS_H

#include <QtWidgets/QDialog>
#include <QDateTime>

#include "src/util/rununits.h"

namespace Ui
{
    class RunTools;
}

class RunTools : public QDialog
{
    Q_OBJECT

public:

    RunTools(QWidget *parent = 0);
    ~RunTools();

protected:

    void changeEvent(QEvent *e);

private:

    void        updatePziTable();
    void        updatePredictor();

    double      mInputDistance;
    double      mInputTime;
    double      mOutputDistance;
    RunUnits    mUnits;
    Ui::RunTools *m_ui;

private slots:

    void on_outputDistanceCombo_activated(QString );
    void on_inputTimeEdit_timeChanged(QTime date);
    void on_inputDistanceLineEdit_editingFinished();
    void on_raceTime_timeChanged(QTime date);
    void on_raceTime_editingFinished();
    void on_raceCombo_activated(int index);
    void on_unitsComboBox_currentIndexChanged( QString units );
    void on_inputTimeEdit_dateTimeChanged( QDateTime inputTime);
};

#endif // RUNTOOLS_H
