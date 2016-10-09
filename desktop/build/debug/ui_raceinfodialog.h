/********************************************************************************
** Form generated from reading UI file 'raceinfodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RACEINFODIALOG_H
#define UI_RACEINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RaceInfoDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_5;
    QVBoxLayout *verticalLayout;
    QLineEdit *raceNameLineEdit;
    QHBoxLayout *horizontalLayout;
    QLineEdit *bibLineEdit;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QTimeEdit *chipTimeEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    QTimeEdit *gunTimeEdit;
    QGroupBox *groupBox;
    QGridLayout *_7;
    QHBoxLayout *_8;
    QLineEdit *overallPlaceLineEdit;
    QLabel *label_2;
    QLineEdit *overallNumLineEdit;
    QSpacerItem *spacerItem;
    QLabel *overallPercentLabel;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout1;
    QHBoxLayout *_2;
    QComboBox *divComboBox;
    QSpacerItem *spacerItem1;
    QHBoxLayout *_3;
    QLineEdit *divPlaceLineEdit;
    QLabel *label_3;
    QLineEdit *divNumLineEdit;
    QSpacerItem *spacerItem2;
    QLabel *divisionPercentLabel;
    QSpacerItem *spacer;
    QHBoxLayout *_4;
    QSpacerItem *spacerItem3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *RaceInfoDialog)
    {
        if (RaceInfoDialog->objectName().isEmpty())
            RaceInfoDialog->setObjectName(QStringLiteral("RaceInfoDialog"));
        RaceInfoDialog->resize(358, 321);
        gridLayout = new QGridLayout(RaceInfoDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_7 = new QLabel(RaceInfoDialog);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_2->addWidget(label_7);

        label = new QLabel(RaceInfoDialog);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        label_5 = new QLabel(RaceInfoDialog);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        raceNameLineEdit = new QLineEdit(RaceInfoDialog);
        raceNameLineEdit->setObjectName(QStringLiteral("raceNameLineEdit"));

        verticalLayout->addWidget(raceNameLineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        bibLineEdit = new QLineEdit(RaceInfoDialog);
        bibLineEdit->setObjectName(QStringLiteral("bibLineEdit"));

        horizontalLayout->addWidget(bibLineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        chipTimeEdit = new QTimeEdit(RaceInfoDialog);
        chipTimeEdit->setObjectName(QStringLiteral("chipTimeEdit"));

        horizontalLayout_2->addWidget(chipTimeEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_6 = new QLabel(RaceInfoDialog);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_2->addWidget(label_6);

        gunTimeEdit = new QTimeEdit(RaceInfoDialog);
        gunTimeEdit->setObjectName(QStringLiteral("gunTimeEdit"));

        horizontalLayout_2->addWidget(gunTimeEdit);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        groupBox = new QGroupBox(RaceInfoDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        _7 = new QGridLayout(groupBox);
        _7->setObjectName(QStringLiteral("_7"));
        _8 = new QHBoxLayout();
        _8->setObjectName(QStringLiteral("_8"));
        overallPlaceLineEdit = new QLineEdit(groupBox);
        overallPlaceLineEdit->setObjectName(QStringLiteral("overallPlaceLineEdit"));

        _8->addWidget(overallPlaceLineEdit);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        _8->addWidget(label_2);

        overallNumLineEdit = new QLineEdit(groupBox);
        overallNumLineEdit->setObjectName(QStringLiteral("overallNumLineEdit"));

        _8->addWidget(overallNumLineEdit);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _8->addItem(spacerItem);

        overallPercentLabel = new QLabel(groupBox);
        overallPercentLabel->setObjectName(QStringLiteral("overallPercentLabel"));

        _8->addWidget(overallPercentLabel);


        _7->addLayout(_8, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(RaceInfoDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout1 = new QGridLayout(groupBox_2);
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        _2 = new QHBoxLayout();
        _2->setObjectName(QStringLiteral("_2"));
        divComboBox = new QComboBox(groupBox_2);
        divComboBox->setObjectName(QStringLiteral("divComboBox"));
        divComboBox->setMinimumSize(QSize(80, 0));
        divComboBox->setEditable(true);
        divComboBox->setInsertPolicy(QComboBox::InsertAlphabetically);

        _2->addWidget(divComboBox);

        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _2->addItem(spacerItem1);


        gridLayout1->addLayout(_2, 0, 0, 1, 1);

        _3 = new QHBoxLayout();
        _3->setObjectName(QStringLiteral("_3"));
        divPlaceLineEdit = new QLineEdit(groupBox_2);
        divPlaceLineEdit->setObjectName(QStringLiteral("divPlaceLineEdit"));

        _3->addWidget(divPlaceLineEdit);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        _3->addWidget(label_3);

        divNumLineEdit = new QLineEdit(groupBox_2);
        divNumLineEdit->setObjectName(QStringLiteral("divNumLineEdit"));

        _3->addWidget(divNumLineEdit);

        spacerItem2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _3->addItem(spacerItem2);

        divisionPercentLabel = new QLabel(groupBox_2);
        divisionPercentLabel->setObjectName(QStringLiteral("divisionPercentLabel"));

        _3->addWidget(divisionPercentLabel);


        gridLayout1->addLayout(_3, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 2, 0, 1, 1);

        spacer = new QSpacerItem(340, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer, 3, 0, 1, 1);

        _4 = new QHBoxLayout();
        _4->setObjectName(QStringLiteral("_4"));
        spacerItem3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _4->addItem(spacerItem3);

        buttonBox = new QDialogButtonBox(RaceInfoDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        _4->addWidget(buttonBox);


        gridLayout->addLayout(_4, 4, 0, 1, 1);


        retranslateUi(RaceInfoDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), RaceInfoDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RaceInfoDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(RaceInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *RaceInfoDialog)
    {
        RaceInfoDialog->setWindowTitle(QApplication::translate("RaceInfoDialog", "Dialog", 0));
        label_7->setStyleSheet(QApplication::translate("RaceInfoDialog", "QFrame { background:none}", 0));
        label_7->setText(QApplication::translate("RaceInfoDialog", "Race Name", 0));
        label->setStyleSheet(QApplication::translate("RaceInfoDialog", "QFrame { background:none}", 0));
        label->setText(QApplication::translate("RaceInfoDialog", "Bib", 0));
        label_5->setStyleSheet(QApplication::translate("RaceInfoDialog", "QFrame { background:none}", 0));
        label_5->setText(QApplication::translate("RaceInfoDialog", "Chip time:", 0));
        chipTimeEdit->setDisplayFormat(QApplication::translate("RaceInfoDialog", "HH:mm:ss", 0));
        label_6->setStyleSheet(QApplication::translate("RaceInfoDialog", "QFrame { background:none}", 0));
        label_6->setText(QApplication::translate("RaceInfoDialog", "Gun time:", 0));
        gunTimeEdit->setDisplayFormat(QApplication::translate("RaceInfoDialog", "HH:mm:ss", 0));
        groupBox->setTitle(QApplication::translate("RaceInfoDialog", "Overall Place", 0));
        label_2->setStyleSheet(QApplication::translate("RaceInfoDialog", "QFrame { background:none}", 0));
        label_2->setText(QApplication::translate("RaceInfoDialog", "out of", 0));
        overallPercentLabel->setStyleSheet(QApplication::translate("RaceInfoDialog", "QFrame { background:none}", 0));
        overallPercentLabel->setText(QApplication::translate("RaceInfoDialog", "top 100%", 0));
        groupBox_2->setTitle(QApplication::translate("RaceInfoDialog", "Age Division Place", 0));
        divComboBox->setStyleSheet(QApplication::translate("RaceInfoDialog", "QFrame { background:none}", 0));
        label_3->setStyleSheet(QApplication::translate("RaceInfoDialog", "QFrame { background:none}", 0));
        label_3->setText(QApplication::translate("RaceInfoDialog", "out of", 0));
        divisionPercentLabel->setStyleSheet(QApplication::translate("RaceInfoDialog", "QFrame { background:none}", 0));
        divisionPercentLabel->setText(QApplication::translate("RaceInfoDialog", "top 100%l", 0));
    } // retranslateUi

};

namespace Ui {
    class RaceInfoDialog: public Ui_RaceInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RACEINFODIALOG_H
