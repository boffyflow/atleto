/********************************************************************************
** Form generated from reading UI file 'runtools.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNTOOLS_H
#define UI_RUNTOOLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>
#include "src/gui/runlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_RunTools
{
public:
    QGridLayout *gridLayout_5;
    QLabel *label;
    QComboBox *unitsComboBox;
    QSpacerItem *horizontalSpacer;
    QTabWidget *predictorTab;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QTimeEdit *inputTimeEdit;
    QLabel *label_13;
    QLabel *label_4;
    QLabel *inputPaceLabel;
    QLabel *label_5;
    QLabel *inputSpeedLabel;
    RunLineEdit *inputDistanceLineEdit;
    QSpacerItem *verticalSpacer;
    QFrame *frame_2;
    QGridLayout *gridLayout_4;
    QLabel *label_8;
    QComboBox *outputDistanceCombo;
    QLabel *label_10;
    QLabel *outputPaceLabel;
    QLabel *outputTimeLabel;
    QLabel *label_9;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QComboBox *raceCombo;
    QTimeEdit *raceTime;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    QLabel *paceZoneIndex;
    QSpacerItem *horizontalSpacer_3;
    QTableWidget *tableWidget;
    QLabel *vdotLabel;
    QLabel *label_7;

    void setupUi(QDialog *RunTools)
    {
        if (RunTools->objectName().isEmpty())
            RunTools->setObjectName(QStringLiteral("RunTools"));
        RunTools->resize(409, 356);
        gridLayout_5 = new QGridLayout(RunTools);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label = new QLabel(RunTools);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        unitsComboBox = new QComboBox(RunTools);
        unitsComboBox->setObjectName(QStringLiteral("unitsComboBox"));
        unitsComboBox->setEnabled(false);

        gridLayout_5->addWidget(unitsComboBox, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(269, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 0, 2, 1, 1);

        predictorTab = new QTabWidget(RunTools);
        predictorTab->setObjectName(QStringLiteral("predictorTab"));
        predictorTab->setEnabled(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tab->setEnabled(true);
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        frame = new QFrame(tab);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setEnabled(true);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(true);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        inputTimeEdit = new QTimeEdit(frame);
        inputTimeEdit->setObjectName(QStringLiteral("inputTimeEdit"));
        inputTimeEdit->setTime(QTime(0, 50, 0));

        gridLayout_2->addWidget(inputTimeEdit, 1, 1, 1, 1);

        label_13 = new QLabel(frame);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_2->addWidget(label_13, 1, 2, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        inputPaceLabel = new QLabel(frame);
        inputPaceLabel->setObjectName(QStringLiteral("inputPaceLabel"));
        inputPaceLabel->setStyleSheet(QStringLiteral("font: 85 12pt \"MS Shell Dlg 2\";"));

        gridLayout_2->addWidget(inputPaceLabel, 2, 1, 1, 1);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 3, 0, 1, 1);

        inputSpeedLabel = new QLabel(frame);
        inputSpeedLabel->setObjectName(QStringLiteral("inputSpeedLabel"));
        inputSpeedLabel->setEnabled(true);

        gridLayout_2->addWidget(inputSpeedLabel, 3, 1, 1, 1);

        inputDistanceLineEdit = new RunLineEdit(frame);
        inputDistanceLineEdit->setObjectName(QStringLiteral("inputDistanceLineEdit"));
        inputDistanceLineEdit->setAutoFillBackground(false);
        inputDistanceLineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        gridLayout_2->addWidget(inputDistanceLineEdit, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 4, 0, 1, 3);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 2);
        gridLayout_2->setColumnStretch(2, 3);

        gridLayout_3->addWidget(frame, 0, 0, 1, 1);

        frame_2 = new QFrame(tab);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setEnabled(true);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_4->addWidget(label_8, 1, 0, 1, 1);

        outputDistanceCombo = new QComboBox(frame_2);
        outputDistanceCombo->setObjectName(QStringLiteral("outputDistanceCombo"));
        outputDistanceCombo->setEditable(false);

        gridLayout_4->addWidget(outputDistanceCombo, 1, 1, 1, 1);

        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_4->addWidget(label_10, 4, 0, 1, 1);

        outputPaceLabel = new QLabel(frame_2);
        outputPaceLabel->setObjectName(QStringLiteral("outputPaceLabel"));
        outputPaceLabel->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));

        gridLayout_4->addWidget(outputPaceLabel, 4, 1, 1, 1);

        outputTimeLabel = new QLabel(frame_2);
        outputTimeLabel->setObjectName(QStringLiteral("outputTimeLabel"));
        outputTimeLabel->setStyleSheet(QLatin1String("color: rgb(170, 0, 0);\n"
"font: 85 12pt \"MS Shell Dlg 2\";"));

        gridLayout_4->addWidget(outputTimeLabel, 2, 1, 1, 1);

        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_4->addWidget(label_9, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 5, 0, 1, 2);

        gridLayout_4->setColumnStretch(0, 1);
        gridLayout_4->setColumnStretch(1, 2);

        gridLayout_3->addWidget(frame_2, 2, 0, 1, 1);

        predictorTab->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        raceCombo = new QComboBox(tab_2);
        raceCombo->setObjectName(QStringLiteral("raceCombo"));

        gridLayout->addWidget(raceCombo, 0, 0, 1, 1);

        raceTime = new QTimeEdit(tab_2);
        raceTime->setObjectName(QStringLiteral("raceTime"));
        raceTime->setTime(QTime(0, 20, 0));

        gridLayout->addWidget(raceTime, 0, 1, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(212, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 4);

        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 2);

        paceZoneIndex = new QLabel(tab_2);
        paceZoneIndex->setObjectName(QStringLiteral("paceZoneIndex"));
        paceZoneIndex->setStyleSheet(QStringLiteral("font: 75 8pt bold \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(paceZoneIndex, 1, 2, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(212, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 4, 1, 1);

        tableWidget = new QTableWidget(tab_2);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 6)
            tableWidget->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(4, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(5, 0, __qtablewidgetitem13);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(tableWidget, 2, 0, 1, 7);

        vdotLabel = new QLabel(tab_2);
        vdotLabel->setObjectName(QStringLiteral("vdotLabel"));

        gridLayout->addWidget(vdotLabel, 1, 6, 1, 1);

        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 1, 5, 1, 1);

        predictorTab->addTab(tab_2, QString());

        gridLayout_5->addWidget(predictorTab, 1, 0, 1, 3);

        QWidget::setTabOrder(unitsComboBox, predictorTab);
        QWidget::setTabOrder(predictorTab, inputDistanceLineEdit);
        QWidget::setTabOrder(inputDistanceLineEdit, inputTimeEdit);
        QWidget::setTabOrder(inputTimeEdit, outputDistanceCombo);
        QWidget::setTabOrder(outputDistanceCombo, raceCombo);
        QWidget::setTabOrder(raceCombo, raceTime);
        QWidget::setTabOrder(raceTime, tableWidget);

        retranslateUi(RunTools);

        predictorTab->setCurrentIndex(1);
        outputDistanceCombo->setCurrentIndex(-1);
        raceCombo->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(RunTools);
    } // setupUi

    void retranslateUi(QDialog *RunTools)
    {
        RunTools->setWindowTitle(QApplication::translate("RunTools", "Dialog", 0));
        label->setText(QApplication::translate("RunTools", "Units:", 0));
        unitsComboBox->clear();
        unitsComboBox->insertItems(0, QStringList()
         << QApplication::translate("RunTools", "km", 0)
         << QApplication::translate("RunTools", "miles", 0)
        );
        frame->setStyleSheet(QApplication::translate("RunTools", "background-color: rgb(215, 242, 244);", 0));
        label_2->setText(QApplication::translate("RunTools", "Distance", 0));
        label_3->setText(QApplication::translate("RunTools", "Time", 0));
        inputTimeEdit->setStyleSheet(QApplication::translate("RunTools", "background-color: rgb(255, 255, 255);", 0));
        label_13->setText(QApplication::translate("RunTools", "h:m:s", 0));
        label_4->setText(QApplication::translate("RunTools", "Pace", 0));
        inputPaceLabel->setText(QApplication::translate("RunTools", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:72; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#000000;\">TextLabel</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("RunTools", "Speed", 0));
        inputSpeedLabel->setText(QApplication::translate("RunTools", "TextLabel", 0));
        frame_2->setStyleSheet(QApplication::translate("RunTools", "background-color: rgb(255, 253, 211);", 0));
        label_8->setText(QApplication::translate("RunTools", "Race Distance", 0));
        outputDistanceCombo->setStyleSheet(QApplication::translate("RunTools", "background-color: rgb(255, 255, 255);", 0));
        label_10->setText(QApplication::translate("RunTools", "Predicted Pace", 0));
        outputPaceLabel->setText(QApplication::translate("RunTools", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#aa0000;\">TextLabel</span></p></body></html>", 0));
        outputTimeLabel->setText(QApplication::translate("RunTools", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#aa0000;\">TextLabel</span></p></body></html>", 0));
        label_9->setText(QApplication::translate("RunTools", "Predicted Finish Time", 0));
        predictorTab->setTabText(predictorTab->indexOf(tab), QApplication::translate("RunTools", "Predictor", 0));
        raceCombo->clear();
        raceCombo->insertItems(0, QStringList()
         << QApplication::translate("RunTools", "3K", 0)
         << QApplication::translate("RunTools", "5K", 0)
         << QApplication::translate("RunTools", "10K", 0)
        );
        label_6->setText(QApplication::translate("RunTools", "Pace Zone Index:", 0));
        paceZoneIndex->setText(QApplication::translate("RunTools", "TextLabel", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("RunTools", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("RunTools", "Pace Range", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("RunTools", "2", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("RunTools", "3", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("RunTools", "4", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("RunTools", "6", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem6->setText(QApplication::translate("RunTools", "8", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem7->setText(QApplication::translate("RunTools", "10", 0));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled);

        vdotLabel->setText(QApplication::translate("RunTools", "xxx", 0));
        label_7->setText(QApplication::translate("RunTools", "VDOT:", 0));
        predictorTab->setTabText(predictorTab->indexOf(tab_2), QApplication::translate("RunTools", "Pace Zones", 0));
    } // retranslateUi

};

namespace Ui {
    class RunTools: public Ui_RunTools {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNTOOLS_H
