/********************************************************************************
** Form generated from reading UI file 'shoeeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOEEDITOR_H
#define UI_SHOEEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include "src/gui/runlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_ShoeEditor
{
public:
    QGridLayout *gridLayout_2;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *shoeName;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLineEdit *shoeBrand;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QLineEdit *shoeModel;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_7;
    QLineEdit *shoeSize;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_4;
    QLineEdit *shoeNotes;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer;
    QGroupBox *activeBox;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QDateEdit *endUse;
    QDateEdit *startUse;
    QLabel *label_8;
    QLabel *label_9;
    RunLineEdit *startMileage;
    RunLineEdit *maxMileage;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QDialog *ShoeEditor)
    {
        if (ShoeEditor->objectName().isEmpty())
            ShoeEditor->setObjectName(QStringLiteral("ShoeEditor"));
        ShoeEditor->setWindowModality(Qt::ApplicationModal);
        ShoeEditor->resize(400, 361);
        gridLayout_2 = new QGridLayout(ShoeEditor);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        buttonBox = new QDialogButtonBox(ShoeEditor);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 1, 1, 2);

        groupBox = new QGroupBox(ShoeEditor);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        shoeName = new QLineEdit(groupBox);
        shoeName->setObjectName(QStringLiteral("shoeName"));

        gridLayout->addWidget(shoeName, 0, 1, 1, 4);

        horizontalSpacer_2 = new QSpacerItem(158, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 5, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        shoeBrand = new QLineEdit(groupBox);
        shoeBrand->setObjectName(QStringLiteral("shoeBrand"));

        gridLayout->addWidget(shoeBrand, 1, 1, 1, 4);

        horizontalSpacer_3 = new QSpacerItem(121, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 5, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        shoeModel = new QLineEdit(groupBox);
        shoeModel->setObjectName(QStringLiteral("shoeModel"));

        gridLayout->addWidget(shoeModel, 2, 1, 1, 4);

        horizontalSpacer_4 = new QSpacerItem(158, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 5, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        shoeSize = new QLineEdit(groupBox);
        shoeSize->setObjectName(QStringLiteral("shoeSize"));

        gridLayout->addWidget(shoeSize, 3, 1, 1, 4);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 3, 5, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        shoeNotes = new QLineEdit(groupBox);
        shoeNotes->setObjectName(QStringLiteral("shoeNotes"));

        gridLayout->addWidget(shoeNotes, 4, 1, 1, 5);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 7, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(189, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 7, 4, 1, 2);

        horizontalSpacer_7 = new QSpacerItem(195, 50, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 9, 3, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 10, 0, 1, 1);

        activeBox = new QGroupBox(groupBox);
        activeBox->setObjectName(QStringLiteral("activeBox"));
        activeBox->setCheckable(true);
        gridLayout_3 = new QGridLayout(activeBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_6 = new QLabel(activeBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        endUse = new QDateEdit(activeBox);
        endUse->setObjectName(QStringLiteral("endUse"));
        endUse->setCalendarPopup(true);

        gridLayout_3->addWidget(endUse, 0, 1, 1, 1);


        gridLayout->addWidget(activeBox, 9, 0, 1, 3);

        startUse = new QDateEdit(groupBox);
        startUse->setObjectName(QStringLiteral("startUse"));
        startUse->setCalendarPopup(true);

        gridLayout->addWidget(startUse, 7, 2, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 6, 0, 1, 1);

        startMileage = new RunLineEdit(groupBox);
        startMileage->setObjectName(QStringLiteral("startMileage"));

        gridLayout->addWidget(startMileage, 5, 1, 1, 4);

        maxMileage = new RunLineEdit(groupBox);
        maxMileage->setObjectName(QStringLiteral("maxMileage"));

        gridLayout->addWidget(maxMileage, 6, 1, 1, 4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 5, 5, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 6, 5, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 3);


        retranslateUi(ShoeEditor);
        QObject::connect(buttonBox, SIGNAL(accepted()), ShoeEditor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ShoeEditor, SLOT(reject()));

        QMetaObject::connectSlotsByName(ShoeEditor);
    } // setupUi

    void retranslateUi(QDialog *ShoeEditor)
    {
        ShoeEditor->setWindowTitle(QApplication::translate("ShoeEditor", "Shoe Editor", 0));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("ShoeEditor", "Name", 0));
        label_2->setText(QApplication::translate("ShoeEditor", "Brand", 0));
        label_3->setText(QApplication::translate("ShoeEditor", "Model", 0));
        label_7->setText(QApplication::translate("ShoeEditor", "Size", 0));
        label_4->setText(QApplication::translate("ShoeEditor", "Notes", 0));
        label_5->setText(QApplication::translate("ShoeEditor", "Start  use", 0));
        activeBox->setTitle(QApplication::translate("ShoeEditor", "Active", 0));
        label_6->setText(QApplication::translate("ShoeEditor", "End use", 0));
        label_8->setText(QApplication::translate("ShoeEditor", "Start mileage", 0));
        label_9->setText(QApplication::translate("ShoeEditor", "Max mileage", 0));
    } // retranslateUi

};

namespace Ui {
    class ShoeEditor: public Ui_ShoeEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOEEDITOR_H
