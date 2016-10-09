/********************************************************************************
** Form generated from reading UI file 'periodwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERIODWIDGET_H
#define UI_PERIODWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_PeriodWidget
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QComboBox *reportTypeCombo;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *periodCombo;
    QLineEdit *numUnitsEdit;
    QComboBox *unitsCombo;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QDateEdit *fromDate;
    QLabel *label_2;
    QDateEdit *toDate;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer;

    void setupUi(QGroupBox *PeriodWidget)
    {
        if (PeriodWidget->objectName().isEmpty())
            PeriodWidget->setObjectName(QStringLiteral("PeriodWidget"));
        PeriodWidget->resize(291, 110);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PeriodWidget->sizePolicy().hasHeightForWidth());
        PeriodWidget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(PeriodWidget);
        gridLayout_2->setContentsMargins(3, 3, 3, 3);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(3);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(PeriodWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 2);

        reportTypeCombo = new QComboBox(PeriodWidget);
        reportTypeCombo->setObjectName(QStringLiteral("reportTypeCombo"));

        gridLayout->addWidget(reportTypeCombo, 0, 2, 1, 4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 6, 1, 1);

        periodCombo = new QComboBox(PeriodWidget);
        periodCombo->setObjectName(QStringLiteral("periodCombo"));

        gridLayout->addWidget(periodCombo, 1, 0, 1, 3);

        numUnitsEdit = new QLineEdit(PeriodWidget);
        numUnitsEdit->setObjectName(QStringLiteral("numUnitsEdit"));
        numUnitsEdit->setMaximumSize(QSize(32, 16777215));

        gridLayout->addWidget(numUnitsEdit, 1, 3, 1, 2);

        unitsCombo = new QComboBox(PeriodWidget);
        unitsCombo->setObjectName(QStringLiteral("unitsCombo"));

        gridLayout->addWidget(unitsCombo, 1, 5, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 7, 1, 1);

        label = new QLabel(PeriodWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        fromDate = new QDateEdit(PeriodWidget);
        fromDate->setObjectName(QStringLiteral("fromDate"));
        fromDate->setEnabled(false);
        fromDate->setCalendarPopup(true);

        gridLayout->addWidget(fromDate, 2, 1, 1, 3);

        label_2 = new QLabel(PeriodWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 4, 1, 2);

        toDate = new QDateEdit(PeriodWidget);
        toDate->setObjectName(QStringLiteral("toDate"));
        toDate->setEnabled(false);
        toDate->setCalendarPopup(true);

        gridLayout->addWidget(toDate, 2, 6, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 7, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(1, 80, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);


        retranslateUi(PeriodWidget);

        reportTypeCombo->setCurrentIndex(1);
        periodCombo->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(PeriodWidget);
    } // setupUi

    void retranslateUi(QGroupBox *PeriodWidget)
    {
        PeriodWidget->setWindowTitle(QApplication::translate("PeriodWidget", "Period", 0));
        PeriodWidget->setTitle(QApplication::translate("PeriodWidget", "Period", 0));
        label_3->setText(QApplication::translate("PeriodWidget", "Report type:", 0));
        reportTypeCombo->clear();
        reportTypeCombo->insertItems(0, QStringList()
         << QApplication::translate("PeriodWidget", "Daily", 0)
         << QApplication::translate("PeriodWidget", "Weekly", 0)
         << QApplication::translate("PeriodWidget", "Monthly", 0)
         << QApplication::translate("PeriodWidget", "Yearly", 0)
        );
        reportTypeCombo->setStyleSheet(QApplication::translate("PeriodWidget", "QWidget { background:none}", 0));
        periodCombo->clear();
        periodCombo->insertItems(0, QStringList()
         << QApplication::translate("PeriodWidget", "This week", 0)
         << QApplication::translate("PeriodWidget", "This month", 0)
         << QApplication::translate("PeriodWidget", "This year", 0)
         << QApplication::translate("PeriodWidget", "Last week", 0)
         << QApplication::translate("PeriodWidget", "Last month", 0)
         << QApplication::translate("PeriodWidget", "Last year", 0)
         << QApplication::translate("PeriodWidget", "Last", 0)
         << QApplication::translate("PeriodWidget", "Custom dates", 0)
        );
        periodCombo->setStyleSheet(QApplication::translate("PeriodWidget", "QWidget { background:none}", 0));
        numUnitsEdit->setStyleSheet(QApplication::translate("PeriodWidget", "QWidget { background:none}", 0));
        unitsCombo->clear();
        unitsCombo->insertItems(0, QStringList()
         << QApplication::translate("PeriodWidget", "days", 0)
         << QApplication::translate("PeriodWidget", "weeks", 0)
         << QApplication::translate("PeriodWidget", "months", 0)
         << QApplication::translate("PeriodWidget", "years", 0)
        );
        unitsCombo->setStyleSheet(QApplication::translate("PeriodWidget", "QWidget { background:none}", 0));
        label->setText(QApplication::translate("PeriodWidget", "From:", 0));
        fromDate->setStyleSheet(QApplication::translate("PeriodWidget", "QWidget { background:none}", 0));
        label_2->setText(QApplication::translate("PeriodWidget", "To:", 0));
        toDate->setStyleSheet(QApplication::translate("PeriodWidget", "QWidget { background:none}", 0));
    } // retranslateUi

};

namespace Ui {
    class PeriodWidget: public Ui_PeriodWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERIODWIDGET_H
