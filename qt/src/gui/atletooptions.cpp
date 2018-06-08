// (c) 2009 Parallel Pixels Ltd.
// $Id: atletooptions.cpp 372 2013-03-05 22:04:13Z boffyflow $

#include "atletooptions.h"
#include "ui_atletooptions.h"
#include "src/util/lengthunits.h"
#include "src/data/settings.h"

#include <QSettings>
#include <QFileDialog>
#include <QMessageBox>
#include <QTranslator>

AtletoOptions::AtletoOptions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AtletoOptions)
{

    ui->setupUi(this);
    ui->retranslateUi(this);

    ui->ruComboBox->addItem( LENGTH_STRINGS[KILOMETERS]);
    ui->ruComboBox->addItem( LENGTH_STRINGS[MILES]);

    mSqlDriver = sqlDriver();

    QSettings        settings;

    settings.beginGroup( "Options");
    mDbFileName = settings.value( "dbfilename").toString();
    mMySqlServer = settings.value( "mysql_server").toString();
    mMySqlUser = settings.value( "mysql_user").toString();
    mMySqlPassword = settings.value( "mysql_password").toString();
    mLanguageName = settings.value( "language").toString();
    settings.endGroup();

    ui->dbLineEdit->setText( mDbFileName);
    ui->lineEditMySqlServer->setText( mMySqlServer);
    ui->lineEditMySqlUser->setText( mMySqlUser);
    ui->lineEditMySqlPassword->setText( mMySqlPassword);

    if( mSqlDriver == DB_SQLITE)
        ui->sqliteRadio->click();
    else
        ui->mySqlRadio->click();

    ui->lngComboBox->setCurrentIndex( ui->lngComboBox->findText(mLanguageName));

    ui->ruComboBox->setCurrentIndex( ui->ruComboBox->findText( Settings::value( "run_distance_units")));

//    connect( ui->dbLineEdit, SIGNAL(textChanged(QString)), this, SLOT(dbLineEditChanged()));
//    connect( ui->lngComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(langComboBoxChanged()));
}

AtletoOptions::~AtletoOptions()
{
    delete ui;
}


int AtletoOptions::sqlDriver()
{
    QSettings        settings;

    settings.beginGroup( "Options");
    return settings.value( "sql_driver").toInt();
}

void AtletoOptions::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->setupUi(this);
        break;
    default:
        break;
    }
}

void AtletoOptions::on_dbButton_clicked()
{
    QString     fname = QFileDialog::getOpenFileName( this, tr("Select Atleto DB file"), QDir::homePath(), tr("Atleto (*.atl)"));

    if( !fname.isEmpty())
        ui->dbLineEdit->setText( fname);
}

void AtletoOptions::on_buttonBox_accepted()
{
    if( ui->sqliteRadio->isChecked())
        mSqlDriver = DB_SQLITE;
    else
        mSqlDriver = DB_MYSQL;
    mDbFileName = ui->dbLineEdit->text();
    mMySqlServer = ui->lineEditMySqlServer->text();
    mMySqlUser = ui->lineEditMySqlUser->text();
    mMySqlPassword = ui->lineEditMySqlPassword->text();
    mLanguageName = ui->lngComboBox->currentText();

    QSettings        settings;

    settings.beginGroup( "Options");
    settings.setValue( "sql_driver", mSqlDriver);
    settings.setValue( "dbfilename", mDbFileName);
    settings.setValue( "mysql_server", mMySqlServer);
    settings.setValue( "mysql_user", mMySqlUser);
    settings.setValue( "mysql_password", mMySqlPassword);
    settings.setValue( "language", mLanguageName);
    settings.endGroup();

    Settings::setValue( "run_distance_units", ui->ruComboBox->currentText());

    QMessageBox::information( this, tr( "Restart required"), tr( "For these changes to take effect Atleto must be restarted!"));

}

void AtletoOptions::on_buttonBox_clicked( QAbstractButton* button)
{
    if( ui->buttonBox->standardButton( button) == QDialogButtonBox::Apply)
    {
        Settings::setValue( "run_distance_units", ui->ruComboBox->currentText());
    }
}

void AtletoOptions::on_sqliteRadio_clicked()
{
    ui->labelSqliteFilename->setEnabled( true);
    ui->dbLineEdit->setEnabled( true);

    ui->labelMySqlServer->setEnabled( false);
    ui->labelMySqlUser->setEnabled( false);
    ui->labelMySqlPassword->setEnabled( false);
    ui->lineEditMySqlServer->setEnabled( false);
    ui->lineEditMySqlUser->setEnabled( false);
    ui->lineEditMySqlPassword->setEnabled( false);
}

void AtletoOptions::on_mySqlRadio_clicked()
{
    ui->labelMySqlServer->setEnabled( true);
    ui->labelMySqlUser->setEnabled( true);
    ui->labelMySqlPassword->setEnabled( true);
    ui->lineEditMySqlServer->setEnabled( true);
    ui->lineEditMySqlUser->setEnabled( true);
    ui->lineEditMySqlPassword->setEnabled( true);

    ui->labelSqliteFilename->setEnabled( false);
    ui->dbLineEdit->setEnabled( false);
}
