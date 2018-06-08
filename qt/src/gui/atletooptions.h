// (c) 2009 Parallel Pixels Ltd.
// $Id: atletooptions.h 372 2013-03-05 22:04:13Z boffyflow $

#ifndef ATLETOOPTIONS_H
#define ATLETOOPTIONS_H

#include <QDialog>

const       int     DB_SQLITE = 0;
const       int     DB_MYSQL = 1;

class QAbstractButton;

namespace Ui
{
    class AtletoOptions;
}

class AtletoOptions : public QDialog
{
    Q_OBJECT

public:

    AtletoOptions( QWidget *parent = 0);
    ~AtletoOptions();

    static      int     sqlDriver();

protected:
    void changeEvent( QEvent *e);

private slots:
    void on_buttonBox_accepted();
    void on_dbButton_clicked();

    void on_buttonBox_clicked(QAbstractButton* button);
    void on_sqliteRadio_clicked();
    void on_mySqlRadio_clicked();

private:

    Ui::AtletoOptions   *ui;

    int                 mSqlDriver;
    QString             mDbFileName;
    QString             mMySqlServer;
    QString             mMySqlUser;
    QString             mMySqlPassword;
    QString             mLanguageName;
};

#endif // ATLETOOPTIONS_H
