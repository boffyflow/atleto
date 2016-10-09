/********************************************************************************
** Form generated from reading UI file 'athleteselector.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATHLETESELECTOR_H
#define UI_ATHLETESELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "src/gui/heightlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_AthleteSelector
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QComboBox *athleteComboBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *newButton;
    QPushButton *deleteButton;
    QSpacerItem *verticalSpacer;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *editName;
    QLabel *label_2;
    QDateEdit *editDoB;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *boxGender;
    HeightLineEdit *boxHeight;
    QSpacerItem *verticalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AthleteSelector)
    {
        if (AthleteSelector->objectName().isEmpty())
            AthleteSelector->setObjectName(QStringLiteral("AthleteSelector"));
        AthleteSelector->resize(295, 316);
        QIcon icon;
        icon.addFile(QStringLiteral(":/main/icons/athlete.png"), QSize(), QIcon::Normal, QIcon::Off);
        AthleteSelector->setWindowIcon(icon);
        layoutWidget = new QWidget(AthleteSelector);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 273, 291));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        athleteComboBox = new QComboBox(layoutWidget);
        athleteComboBox->setObjectName(QStringLiteral("athleteComboBox"));
        athleteComboBox->setEnabled(true);

        verticalLayout->addWidget(athleteComboBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        newButton = new QPushButton(layoutWidget);
        newButton->setObjectName(QStringLiteral("newButton"));
        newButton->setEnabled(true);

        horizontalLayout->addWidget(newButton);

        deleteButton = new QPushButton(layoutWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setEnabled(false);

        horizontalLayout->addWidget(deleteButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        editName = new QLineEdit(layoutWidget);
        editName->setObjectName(QStringLiteral("editName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, editName);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        editDoB = new QDateEdit(layoutWidget);
        editDoB->setObjectName(QStringLiteral("editDoB"));
        editDoB->setCalendarPopup(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, editDoB);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        boxGender = new QComboBox(layoutWidget);
        boxGender->setObjectName(QStringLiteral("boxGender"));

        formLayout->setWidget(4, QFormLayout::FieldRole, boxGender);

        boxHeight = new HeightLineEdit(layoutWidget);
        boxHeight->setObjectName(QStringLiteral("boxHeight"));

        formLayout->setWidget(2, QFormLayout::FieldRole, boxHeight);


        verticalLayout_2->addLayout(formLayout);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setEnabled(true);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);

        QWidget::setTabOrder(athleteComboBox, newButton);
        QWidget::setTabOrder(newButton, deleteButton);
        QWidget::setTabOrder(deleteButton, editName);
        QWidget::setTabOrder(editName, editDoB);
        QWidget::setTabOrder(editDoB, boxHeight);
        QWidget::setTabOrder(boxHeight, boxGender);
        QWidget::setTabOrder(boxGender, buttonBox);

        retranslateUi(AthleteSelector);
        QObject::connect(buttonBox, SIGNAL(rejected()), AthleteSelector, SLOT(reject()));

        QMetaObject::connectSlotsByName(AthleteSelector);
    } // setupUi

    void retranslateUi(QDialog *AthleteSelector)
    {
        AthleteSelector->setWindowTitle(QApplication::translate("AthleteSelector", "Select Athlete", 0));
        newButton->setText(QApplication::translate("AthleteSelector", "New...", 0));
        deleteButton->setText(QApplication::translate("AthleteSelector", "Delete", 0));
        label->setText(QApplication::translate("AthleteSelector", "Name:", 0));
        label_2->setText(QApplication::translate("AthleteSelector", "DoB:", 0));
        editDoB->setDisplayFormat(QApplication::translate("AthleteSelector", "dd-MMM-yyyy", 0));
        label_3->setText(QApplication::translate("AthleteSelector", "Height:", 0));
        label_4->setText(QApplication::translate("AthleteSelector", "Gender:", 0));
        boxGender->clear();
        boxGender->insertItems(0, QStringList()
         << QApplication::translate("AthleteSelector", "male", 0)
         << QApplication::translate("AthleteSelector", "female", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class AthleteSelector: public Ui_AthleteSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATHLETESELECTOR_H
