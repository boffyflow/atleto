/********************************************************************************
** Form generated from reading UI file 'querywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYWIDGET_H
#define UI_QUERYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QueryWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *periodCombo;
    QLineEdit *numUnitsEdit;
    QComboBox *unitsCombo;
    QLabel *fromLabel;
    QDateEdit *fromDate;
    QLabel *toLabel;
    QDateEdit *toDate;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *filterCombo;
    QWidget *filterWidget;

    void setupUi(QWidget *QueryWidget)
    {
        if (QueryWidget->objectName().isEmpty())
            QueryWidget->setObjectName(QStringLiteral("QueryWidget"));
        QueryWidget->resize(585, 41);
        gridLayout = new QGridLayout(QueryWidget);
        gridLayout->setSpacing(3);
        gridLayout->setContentsMargins(3, 3, 3, 3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        periodCombo = new QComboBox(QueryWidget);
        periodCombo->setObjectName(QStringLiteral("periodCombo"));

        horizontalLayout_2->addWidget(periodCombo);

        numUnitsEdit = new QLineEdit(QueryWidget);
        numUnitsEdit->setObjectName(QStringLiteral("numUnitsEdit"));
        numUnitsEdit->setMaximumSize(QSize(32, 16777215));

        horizontalLayout_2->addWidget(numUnitsEdit);

        unitsCombo = new QComboBox(QueryWidget);
        unitsCombo->setObjectName(QStringLiteral("unitsCombo"));

        horizontalLayout_2->addWidget(unitsCombo);

        fromLabel = new QLabel(QueryWidget);
        fromLabel->setObjectName(QStringLiteral("fromLabel"));

        horizontalLayout_2->addWidget(fromLabel);

        fromDate = new QDateEdit(QueryWidget);
        fromDate->setObjectName(QStringLiteral("fromDate"));
        fromDate->setEnabled(true);
        fromDate->setCalendarPopup(true);

        horizontalLayout_2->addWidget(fromDate);

        toLabel = new QLabel(QueryWidget);
        toLabel->setObjectName(QStringLiteral("toLabel"));

        horizontalLayout_2->addWidget(toLabel);

        toDate = new QDateEdit(QueryWidget);
        toDate->setObjectName(QStringLiteral("toDate"));
        toDate->setEnabled(true);
        toDate->setCalendarPopup(true);

        horizontalLayout_2->addWidget(toDate);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        filterCombo = new QComboBox(QueryWidget);
        filterCombo->setObjectName(QStringLiteral("filterCombo"));

        horizontalLayout_2->addWidget(filterCombo);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        filterWidget = new QWidget(QueryWidget);
        filterWidget->setObjectName(QStringLiteral("filterWidget"));

        gridLayout->addWidget(filterWidget, 1, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);

        retranslateUi(QueryWidget);

        periodCombo->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QueryWidget);
    } // setupUi

    void retranslateUi(QWidget *QueryWidget)
    {
        QueryWidget->setWindowTitle(QApplication::translate("QueryWidget", "Form", 0));
        periodCombo->clear();
        periodCombo->insertItems(0, QStringList()
         << QApplication::translate("QueryWidget", "All dates", 0)
         << QApplication::translate("QueryWidget", "This week", 0)
         << QApplication::translate("QueryWidget", "This month", 0)
         << QApplication::translate("QueryWidget", "This year", 0)
         << QApplication::translate("QueryWidget", "Last week", 0)
         << QApplication::translate("QueryWidget", "Last month", 0)
         << QApplication::translate("QueryWidget", "Last year", 0)
         << QApplication::translate("QueryWidget", "Last", 0)
         << QApplication::translate("QueryWidget", "Custom dates", 0)
         << QApplication::translate("QueryWidget", "Custom date through today", 0)
        );
        periodCombo->setStyleSheet(QApplication::translate("QueryWidget", "QWidget { background:none}", 0));
        numUnitsEdit->setStyleSheet(QApplication::translate("QueryWidget", "QWidget { background:none}", 0));
        unitsCombo->clear();
        unitsCombo->insertItems(0, QStringList()
         << QApplication::translate("QueryWidget", "days", 0)
         << QApplication::translate("QueryWidget", "weeks", 0)
         << QApplication::translate("QueryWidget", "months", 0)
         << QApplication::translate("QueryWidget", "years", 0)
        );
        unitsCombo->setStyleSheet(QApplication::translate("QueryWidget", "QWidget { background:none}", 0));
        fromLabel->setText(QApplication::translate("QueryWidget", "From:", 0));
        fromDate->setStyleSheet(QApplication::translate("QueryWidget", "QWidget { background:none}", 0));
        toLabel->setText(QApplication::translate("QueryWidget", "To:", 0));
        toDate->setStyleSheet(QApplication::translate("QueryWidget", "QWidget { background:none}", 0));
        filterCombo->clear();
        filterCombo->insertItems(0, QStringList()
         << QApplication::translate("QueryWidget", "Add filter", 0)
         << QApplication::translate("QueryWidget", "Location", 0)
         << QApplication::translate("QueryWidget", "Distance", 0)
         << QApplication::translate("QueryWidget", "Time", 0)
         << QApplication::translate("QueryWidget", "Type", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class QueryWidget: public Ui_QueryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYWIDGET_H
