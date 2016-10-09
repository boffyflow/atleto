/********************************************************************************
** Form generated from reading UI file 'physicaleditor.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHYSICALEDITOR_H
#define UI_PHYSICALEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include "src/gui/weightlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_PhysicalEditor
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    WeightLineEdit *weightEdit;
    QLabel *bmiLabel;
    QLabel *label_2;
    QLineEdit *hrEdit;
    QLabel *label_3;
    QLineEdit *bodyfatEdit;
    QLabel *label_4;
    QComboBox *ratingCombo;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QDialogButtonBox *buttonBox;
    QPushButton *deleteButton;

    void setupUi(QDialog *PhysicalEditor)
    {
        if (PhysicalEditor->objectName().isEmpty())
            PhysicalEditor->setObjectName(QStringLiteral("PhysicalEditor"));
        PhysicalEditor->resize(312, 173);
        PhysicalEditor->setSizeGripEnabled(true);
        PhysicalEditor->setModal(true);
        gridLayout_2 = new QGridLayout(PhysicalEditor);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(PhysicalEditor);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        weightEdit = new WeightLineEdit(PhysicalEditor);
        weightEdit->setObjectName(QStringLiteral("weightEdit"));

        gridLayout->addWidget(weightEdit, 0, 1, 1, 1);

        bmiLabel = new QLabel(PhysicalEditor);
        bmiLabel->setObjectName(QStringLiteral("bmiLabel"));

        gridLayout->addWidget(bmiLabel, 0, 2, 1, 1);

        label_2 = new QLabel(PhysicalEditor);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        hrEdit = new QLineEdit(PhysicalEditor);
        hrEdit->setObjectName(QStringLiteral("hrEdit"));

        gridLayout->addWidget(hrEdit, 1, 1, 1, 1);

        label_3 = new QLabel(PhysicalEditor);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        bodyfatEdit = new QLineEdit(PhysicalEditor);
        bodyfatEdit->setObjectName(QStringLiteral("bodyfatEdit"));

        gridLayout->addWidget(bodyfatEdit, 2, 1, 1, 1);

        label_4 = new QLabel(PhysicalEditor);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        ratingCombo = new QComboBox(PhysicalEditor);
        ratingCombo->setObjectName(QStringLiteral("ratingCombo"));

        gridLayout->addWidget(ratingCombo, 3, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(21, 97, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 3, 1, 1);

        verticalSpacer = new QSpacerItem(199, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        buttonBox = new QDialogButtonBox(PhysicalEditor);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 2, 1, 1, 1);

        deleteButton = new QPushButton(PhysicalEditor);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        gridLayout_2->addWidget(deleteButton, 2, 2, 1, 2);

        gridLayout_2->setColumnStretch(0, 2);
        gridLayout_2->setColumnStretch(1, 2);
        gridLayout_2->setColumnStretch(2, 2);
        gridLayout_2->setColumnStretch(3, 1);

        retranslateUi(PhysicalEditor);
        QObject::connect(buttonBox, SIGNAL(accepted()), PhysicalEditor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PhysicalEditor, SLOT(reject()));

        QMetaObject::connectSlotsByName(PhysicalEditor);
    } // setupUi

    void retranslateUi(QDialog *PhysicalEditor)
    {
        PhysicalEditor->setWindowTitle(QApplication::translate("PhysicalEditor", "Dialog", 0));
        label->setText(QApplication::translate("PhysicalEditor", "Weight:", 0));
        bmiLabel->setText(QApplication::translate("PhysicalEditor", "TextLabel", 0));
        label_2->setText(QApplication::translate("PhysicalEditor", "Resting Heartrate:", 0));
        label_3->setText(QApplication::translate("PhysicalEditor", "Bodyfat in %:", 0));
        label_4->setText(QApplication::translate("PhysicalEditor", "Rating:", 0));
        deleteButton->setText(QApplication::translate("PhysicalEditor", "Delete", 0));
    } // retranslateUi

};

namespace Ui {
    class PhysicalEditor: public Ui_PhysicalEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHYSICALEDITOR_H
