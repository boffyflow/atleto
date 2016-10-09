// (c) 2009 Parallel Pixels Ltd.
// $Id: athleteselector.h 319 2010-03-13 17:20:16Z stefan $

#ifndef ATHLETESELECTOR_H
#define ATHLETESELECTOR_H

#include <QtWidgets/QDialog>

namespace Ui {
    class AthleteSelector;
}

class AthleteSelector : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(AthleteSelector)
public:
    explicit AthleteSelector(QWidget *parent = 0);
    virtual ~AthleteSelector();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::AthleteSelector *m_ui;

    // hold the value, if the user does some changes
    bool isEdit;
    bool isNewAthlete;
    int lastKnownId;

    void saveChanges();

private slots:
    void athleteChange();
    void newAthlete();
    void saveChangesAndQuit();
    void athleteWasEdit();
};

#endif // ATHLETESELECTOR_H
