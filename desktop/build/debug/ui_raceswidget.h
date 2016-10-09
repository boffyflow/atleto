/********************************************************************************
** Form generated from reading UI file 'raceswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RACESWIDGET_H
#define UI_RACESWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RacesWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *distanceCombo;
    QLabel *label_2;
    QComboBox *yearCombo;
    QCheckBox *pbCheckBox;
    QCheckBox *gunTimeCheckBox;
    QSpacerItem *horizontalSpacer;
    QTableWidget *racesTable;

    void setupUi(QWidget *RacesWidget)
    {
        if (RacesWidget->objectName().isEmpty())
            RacesWidget->setObjectName(QStringLiteral("RacesWidget"));
        RacesWidget->resize(734, 441);
        gridLayout = new QGridLayout(RacesWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(RacesWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        distanceCombo = new QComboBox(RacesWidget);
        distanceCombo->setObjectName(QStringLiteral("distanceCombo"));

        gridLayout->addWidget(distanceCombo, 0, 2, 1, 1);

        label_2 = new QLabel(RacesWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        yearCombo = new QComboBox(RacesWidget);
        yearCombo->setObjectName(QStringLiteral("yearCombo"));

        gridLayout->addWidget(yearCombo, 0, 4, 1, 1);

        pbCheckBox = new QCheckBox(RacesWidget);
        pbCheckBox->setObjectName(QStringLiteral("pbCheckBox"));
        pbCheckBox->setEnabled(true);

        gridLayout->addWidget(pbCheckBox, 0, 5, 1, 1);

        gunTimeCheckBox = new QCheckBox(RacesWidget);
        gunTimeCheckBox->setObjectName(QStringLiteral("gunTimeCheckBox"));
        gunTimeCheckBox->setEnabled(false);

        gridLayout->addWidget(gunTimeCheckBox, 0, 6, 1, 1);

        horizontalSpacer = new QSpacerItem(51, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 7, 1, 1);

        racesTable = new QTableWidget(RacesWidget);
        if (racesTable->columnCount() < 9)
            racesTable->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        racesTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        racesTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        racesTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        racesTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        racesTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        racesTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        racesTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        racesTable->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        racesTable->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        racesTable->setObjectName(QStringLiteral("racesTable"));
        racesTable->setEditTriggers(QAbstractItemView::DoubleClicked);
        racesTable->setAlternatingRowColors(true);
        racesTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        racesTable->setSortingEnabled(true);
        racesTable->verticalHeader()->setVisible(false);
        racesTable->verticalHeader()->setMinimumSectionSize(15);

        gridLayout->addWidget(racesTable, 1, 0, 1, 8);


        retranslateUi(RacesWidget);

        QMetaObject::connectSlotsByName(RacesWidget);
    } // setupUi

    void retranslateUi(QWidget *RacesWidget)
    {
        RacesWidget->setWindowTitle(QApplication::translate("RacesWidget", "Form", 0));
        label->setText(QApplication::translate("RacesWidget", "Distance:", 0));
        label_2->setText(QApplication::translate("RacesWidget", "Year:", 0));
        pbCheckBox->setText(QApplication::translate("RacesWidget", "Only Personl Bests", 0));
        gunTimeCheckBox->setText(QApplication::translate("RacesWidget", "Gun time", 0));
        QTableWidgetItem *___qtablewidgetitem = racesTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("RacesWidget", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem1 = racesTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("RacesWidget", "Distance", 0));
        QTableWidgetItem *___qtablewidgetitem2 = racesTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("RacesWidget", "Race", 0));
        QTableWidgetItem *___qtablewidgetitem3 = racesTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("RacesWidget", "Time", 0));
        QTableWidgetItem *___qtablewidgetitem4 = racesTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("RacesWidget", "Pace", 0));
        QTableWidgetItem *___qtablewidgetitem5 = racesTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("RacesWidget", "Overall", 0));
        QTableWidgetItem *___qtablewidgetitem6 = racesTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("RacesWidget", "Division", 0));
        QTableWidgetItem *___qtablewidgetitem7 = racesTable->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("RacesWidget", "Bib", 0));
        QTableWidgetItem *___qtablewidgetitem8 = racesTable->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("RacesWidget", "Comment", 0));
    } // retranslateUi

};

namespace Ui {
    class RacesWidget: public Ui_RacesWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RACESWIDGET_H
