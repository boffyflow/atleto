/********************************************************************************
** Form generated from reading UI file 'atletooptions.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATLETOOPTIONS_H
#define UI_ATLETOOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_AtletoOptions
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QLineEdit *dbLineEdit;
    QPushButton *dbButton;
    QLineEdit *lineEditMySqlServer;
    QLineEdit *lineEditMySqlUser;
    QLineEdit *lineEditMySqlPassword;
    QLabel *labelMySqlServer;
    QLabel *labelMySqlUser;
    QLabel *labelMySqlPassword;
    QLabel *labelSqliteFilename;
    QRadioButton *sqliteRadio;
    QRadioButton *mySqlRadio;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QComboBox *ruComboBox;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QComboBox *lngComboBox;
    QSpacerItem *horizontalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AtletoOptions)
    {
        if (AtletoOptions->objectName().isEmpty())
            AtletoOptions->setObjectName(QStringLiteral("AtletoOptions"));
        AtletoOptions->resize(535, 347);
        gridLayout_3 = new QGridLayout(AtletoOptions);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(AtletoOptions);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        dbLineEdit = new QLineEdit(groupBox);
        dbLineEdit->setObjectName(QStringLiteral("dbLineEdit"));

        gridLayout_4->addWidget(dbLineEdit, 2, 1, 1, 1);

        dbButton = new QPushButton(groupBox);
        dbButton->setObjectName(QStringLiteral("dbButton"));
        dbButton->setMaximumSize(QSize(30, 16777215));

        gridLayout_4->addWidget(dbButton, 2, 2, 1, 1);

        lineEditMySqlServer = new QLineEdit(groupBox);
        lineEditMySqlServer->setObjectName(QStringLiteral("lineEditMySqlServer"));

        gridLayout_4->addWidget(lineEditMySqlServer, 5, 1, 1, 1);

        lineEditMySqlUser = new QLineEdit(groupBox);
        lineEditMySqlUser->setObjectName(QStringLiteral("lineEditMySqlUser"));

        gridLayout_4->addWidget(lineEditMySqlUser, 6, 1, 1, 1);

        lineEditMySqlPassword = new QLineEdit(groupBox);
        lineEditMySqlPassword->setObjectName(QStringLiteral("lineEditMySqlPassword"));

        gridLayout_4->addWidget(lineEditMySqlPassword, 7, 1, 1, 1);

        labelMySqlServer = new QLabel(groupBox);
        labelMySqlServer->setObjectName(QStringLiteral("labelMySqlServer"));

        gridLayout_4->addWidget(labelMySqlServer, 5, 0, 1, 1);

        labelMySqlUser = new QLabel(groupBox);
        labelMySqlUser->setObjectName(QStringLiteral("labelMySqlUser"));

        gridLayout_4->addWidget(labelMySqlUser, 6, 0, 1, 1);

        labelMySqlPassword = new QLabel(groupBox);
        labelMySqlPassword->setObjectName(QStringLiteral("labelMySqlPassword"));

        gridLayout_4->addWidget(labelMySqlPassword, 7, 0, 1, 1);

        labelSqliteFilename = new QLabel(groupBox);
        labelSqliteFilename->setObjectName(QStringLiteral("labelSqliteFilename"));

        gridLayout_4->addWidget(labelSqliteFilename, 2, 0, 1, 1);

        sqliteRadio = new QRadioButton(groupBox);
        sqliteRadio->setObjectName(QStringLiteral("sqliteRadio"));
        sqliteRadio->setChecked(true);

        gridLayout_4->addWidget(sqliteRadio, 1, 0, 1, 1);

        mySqlRadio = new QRadioButton(groupBox);
        mySqlRadio->setObjectName(QStringLiteral("mySqlRadio"));

        gridLayout_4->addWidget(mySqlRadio, 4, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(AtletoOptions);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        ruComboBox = new QComboBox(groupBox_2);
        ruComboBox->setObjectName(QStringLiteral("ruComboBox"));

        gridLayout_2->addWidget(ruComboBox, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(AtletoOptions);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        lngComboBox = new QComboBox(groupBox_3);
        lngComboBox->setObjectName(QStringLiteral("lngComboBox"));

        gridLayout_5->addWidget(lngComboBox, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(192, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox_3, 2, 0, 1, 1);

        buttonBox = new QDialogButtonBox(AtletoOptions);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(AtletoOptions);
        QObject::connect(buttonBox, SIGNAL(accepted()), AtletoOptions, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AtletoOptions, SLOT(reject()));

        QMetaObject::connectSlotsByName(AtletoOptions);
    } // setupUi

    void retranslateUi(QDialog *AtletoOptions)
    {
        AtletoOptions->setWindowTitle(QApplication::translate("AtletoOptions", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("AtletoOptions", "Database", 0));
        dbButton->setText(QApplication::translate("AtletoOptions", "...", 0));
        labelMySqlServer->setText(QApplication::translate("AtletoOptions", "Server:", 0));
        labelMySqlUser->setText(QApplication::translate("AtletoOptions", "User:", 0));
        labelMySqlPassword->setText(QApplication::translate("AtletoOptions", "Password:", 0));
        labelSqliteFilename->setText(QApplication::translate("AtletoOptions", "File:", 0));
        sqliteRadio->setText(QApplication::translate("AtletoOptions", "Sqlite", 0));
        mySqlRadio->setText(QApplication::translate("AtletoOptions", "MySql database:", 0));
        groupBox_2->setTitle(QApplication::translate("AtletoOptions", "Run Settings", 0));
        label->setText(QApplication::translate("AtletoOptions", "Distance units:", 0));
        groupBox_3->setTitle(QApplication::translate("AtletoOptions", "Language", 0));
        lngComboBox->clear();
        lngComboBox->insertItems(0, QStringList()
         << QApplication::translate("AtletoOptions", "en_US", 0)
         << QApplication::translate("AtletoOptions", "de_DE", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class AtletoOptions: public Ui_AtletoOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATLETOOPTIONS_H
