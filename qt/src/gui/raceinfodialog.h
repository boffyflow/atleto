// $Id: raceinfodialog.h 214 2009-05-28 17:44:45Z robert $
// (c) 2009, Parallel Pixels Ltd.

#ifndef RACEINFODIALOG_H
#define RACEINFODIALOG_H

#include <QtWidgets/QDialog>

#include "src/data/runrace.h"

namespace Ui
{
    class RaceInfoDialog;
}

class RaceInfoDialog : public QDialog
{
    Q_OBJECT
    Q_DISABLE_COPY( RaceInfoDialog)

public:

    explicit RaceInfoDialog( QWidget *parent = 0);
    virtual ~RaceInfoDialog();

    void        setRunRace( const RunRace &runRace);
    RunRace     runRace() const { return mRunRace;};

protected:

    virtual void changeEvent(QEvent *e);

private:

    Ui::RaceInfoDialog  *m_ui;
    RunRace             mRunRace;

private slots:

    void	storeRace();
    void    updatePercentages();
};

#endif // RACEINFODIALOG_H
