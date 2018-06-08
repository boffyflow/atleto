// $Id: journaleditor.h 294 2010-03-05 18:37:10Z  $
// (c) 2009, Parallel Pixels Ltd.

#ifndef JOURNALEDITOR_H
#define JOURNALEDITOR_H

#include <QDialog>
#include <QDate>

#include "src/data/journalentry.h"

namespace Ui
{
    class JournalEditor;
}

class JournalEditor : public QDialog
{
    Q_OBJECT

public:

    JournalEditor( const QDate &day, const int id = -1, QWidget *parent = 0);
    ~JournalEditor();

protected:

    void changeEvent(QEvent *e);

private:

    JournalEntry        mEntry;
    Ui::JournalEditor   *ui;

private slots:

    void on_deleteButton_clicked();
    void on_buttonBox_accepted();
};

#endif // JOURNALEDITOR_H
