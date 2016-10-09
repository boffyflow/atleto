/********************************************************************************
** Form generated from reading UI file 'shoelist.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOELIST_H
#define UI_SHOELIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <src/plot/plot.h>

QT_BEGIN_NAMESPACE

class Ui_ShoeList
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *tableWidget;
    Plot *shoePlot;
    QHBoxLayout *horizontalLayout;
    QCheckBox *showActiveCheckBox;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addButton;
    QPushButton *editButton;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ShoeList)
    {
        if (ShoeList->objectName().isEmpty())
            ShoeList->setObjectName(QStringLiteral("ShoeList"));
        ShoeList->resize(531, 362);
        gridLayout = new QGridLayout(ShoeList);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        tableWidget = new QTableWidget(ShoeList);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMinimumSize(QSize(200, 0));
        tableWidget->setMaximumSize(QSize(250, 16777215));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setShowGrid(false);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->setSortingEnabled(true);
        tableWidget->setRowCount(0);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setVisible(false);

        horizontalLayout_3->addWidget(tableWidget);

        shoePlot = new Plot(ShoeList);
        shoePlot->setObjectName(QStringLiteral("shoePlot"));

        horizontalLayout_3->addWidget(shoePlot);

        horizontalLayout_3->setStretch(1, 1);

        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        showActiveCheckBox = new QCheckBox(ShoeList);
        showActiveCheckBox->setObjectName(QStringLiteral("showActiveCheckBox"));
        showActiveCheckBox->setChecked(true);

        horizontalLayout->addWidget(showActiveCheckBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);

        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        addButton = new QPushButton(ShoeList);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout_2->addWidget(addButton);

        editButton = new QPushButton(ShoeList);
        editButton->setObjectName(QStringLiteral("editButton"));
        editButton->setEnabled(false);

        horizontalLayout_2->addWidget(editButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        buttonBox = new QDialogButtonBox(ShoeList);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 1);


        retranslateUi(ShoeList);
        QObject::connect(buttonBox, SIGNAL(accepted()), ShoeList, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ShoeList, SLOT(reject()));

        QMetaObject::connectSlotsByName(ShoeList);
    } // setupUi

    void retranslateUi(QDialog *ShoeList)
    {
        ShoeList->setWindowTitle(QApplication::translate("ShoeList", "Shoes", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ShoeList", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ShoeList", "Mileage", 0));
        showActiveCheckBox->setText(QApplication::translate("ShoeList", "Show only active", 0));
        addButton->setText(QApplication::translate("ShoeList", "Add", 0));
        editButton->setText(QApplication::translate("ShoeList", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class ShoeList: public Ui_ShoeList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOELIST_H
