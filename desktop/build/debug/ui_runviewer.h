/********************************************************************************
** Form generated from reading UI file 'runviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNVIEWER_H
#define UI_RUNVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <src/plot/plot.h>

QT_BEGIN_NAMESPACE

class Ui_RunViewer
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout;
    QTableWidget *inputTable;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_3;
    QGridLayout *_5;
    QLabel *distanceLabel;
    QGroupBox *groupBox_4;
    QGridLayout *_6;
    QLabel *timeLabel;
    QGroupBox *groupBox_5;
    QGridLayout *_7;
    QLabel *paceLabel;
    QGroupBox *groupBox_6;
    QGridLayout *_8;
    QLabel *aveHrLabel;
    QGroupBox *groupBox_7;
    QGridLayout *_9;
    QLabel *maxHrLabel;
    Plot *plot;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QCheckBox *paceCheckBox;
    QCheckBox *hrCheckBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *editRunButton;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *RunViewer)
    {
        if (RunViewer->objectName().isEmpty())
            RunViewer->setObjectName(QStringLiteral("RunViewer"));
        RunViewer->setWindowModality(Qt::NonModal);
        RunViewer->resize(698, 496);
        gridLayout_2 = new QGridLayout(RunViewer);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox_2 = new QGroupBox(RunViewer);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        inputTable = new QTableWidget(groupBox_2);
        if (inputTable->columnCount() < 4)
            inputTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        inputTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        inputTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        inputTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        inputTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        inputTable->setObjectName(QStringLiteral("inputTable"));
        inputTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        inputTable->setAlternatingRowColors(true);
        inputTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        inputTable->setShowGrid(false);
        inputTable->horizontalHeader()->setVisible(false);

        verticalLayout->addWidget(inputTable);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        _5 = new QGridLayout(groupBox_3);
        _5->setSpacing(3);
        _5->setContentsMargins(3, 3, 3, 3);
        _5->setObjectName(QStringLiteral("_5"));
        distanceLabel = new QLabel(groupBox_3);
        distanceLabel->setObjectName(QStringLiteral("distanceLabel"));
        distanceLabel->setTextFormat(Qt::RichText);

        _5->addWidget(distanceLabel, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        _6 = new QGridLayout(groupBox_4);
        _6->setSpacing(3);
        _6->setContentsMargins(3, 3, 3, 3);
        _6->setObjectName(QStringLiteral("_6"));
        timeLabel = new QLabel(groupBox_4);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));

        _6->addWidget(timeLabel, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_4, 0, 1, 1, 2);

        groupBox_5 = new QGroupBox(groupBox_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        _7 = new QGridLayout(groupBox_5);
        _7->setSpacing(3);
        _7->setContentsMargins(3, 3, 3, 3);
        _7->setObjectName(QStringLiteral("_7"));
        paceLabel = new QLabel(groupBox_5);
        paceLabel->setObjectName(QStringLiteral("paceLabel"));

        _7->addWidget(paceLabel, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_5, 0, 3, 1, 1);

        groupBox_6 = new QGroupBox(groupBox_2);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        _8 = new QGridLayout(groupBox_6);
        _8->setSpacing(3);
        _8->setContentsMargins(3, 3, 3, 3);
        _8->setObjectName(QStringLiteral("_8"));
        aveHrLabel = new QLabel(groupBox_6);
        aveHrLabel->setObjectName(QStringLiteral("aveHrLabel"));

        _8->addWidget(aveHrLabel, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_6, 1, 0, 1, 2);

        groupBox_7 = new QGroupBox(groupBox_2);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        _9 = new QGridLayout(groupBox_7);
        _9->setSpacing(3);
        _9->setContentsMargins(3, 3, 3, 3);
        _9->setObjectName(QStringLiteral("_9"));
        maxHrLabel = new QLabel(groupBox_7);
        maxHrLabel->setObjectName(QStringLiteral("maxHrLabel"));

        _9->addWidget(maxHrLabel, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_7, 1, 2, 1, 2);


        verticalLayout->addLayout(gridLayout_3);


        gridLayout_4->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 0, 0, 1, 1);

        plot = new Plot(RunViewer);
        plot->setObjectName(QStringLiteral("plot"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(plot, 0, 1, 1, 1);

        groupBox = new QGroupBox(RunViewer);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        paceCheckBox = new QCheckBox(groupBox);
        paceCheckBox->setObjectName(QStringLiteral("paceCheckBox"));
        paceCheckBox->setChecked(true);

        gridLayout->addWidget(paceCheckBox, 0, 0, 1, 1);

        hrCheckBox = new QCheckBox(groupBox);
        hrCheckBox->setObjectName(QStringLiteral("hrCheckBox"));
        hrCheckBox->setChecked(true);

        gridLayout->addWidget(hrCheckBox, 0, 1, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        editRunButton = new QPushButton(RunViewer);
        editRunButton->setObjectName(QStringLiteral("editRunButton"));

        horizontalLayout->addWidget(editRunButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout, 2, 0, 1, 1);

        buttonBox = new QDialogButtonBox(RunViewer);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        gridLayout_2->addWidget(buttonBox, 2, 1, 1, 1);


        retranslateUi(RunViewer);
        QObject::connect(buttonBox, SIGNAL(accepted()), RunViewer, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RunViewer, SLOT(reject()));

        QMetaObject::connectSlotsByName(RunViewer);
    } // setupUi

    void retranslateUi(QDialog *RunViewer)
    {
        RunViewer->setWindowTitle(QApplication::translate("RunViewer", "View Run", 0));
        groupBox_2->setTitle(QApplication::translate("RunViewer", "Run", 0));
        QTableWidgetItem *___qtablewidgetitem = inputTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("RunViewer", "Distance", 0));
        QTableWidgetItem *___qtablewidgetitem1 = inputTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("RunViewer", "Time", 0));
        QTableWidgetItem *___qtablewidgetitem2 = inputTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("RunViewer", "Pace", 0));
        QTableWidgetItem *___qtablewidgetitem3 = inputTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("RunViewer", "Heartrate", 0));
        groupBox_3->setTitle(QApplication::translate("RunViewer", "Distance", 0));
        distanceLabel->setStyleSheet(QApplication::translate("RunViewer", "QLabel{font:bold;font-size:14px}\n"
"QFrame { background:none}\n"
"", 0));
        distanceLabel->setText(QApplication::translate("RunViewer", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">TextLabel</span></p></body></html>", 0));
        groupBox_4->setTitle(QApplication::translate("RunViewer", "Time", 0));
        timeLabel->setStyleSheet(QApplication::translate("RunViewer", "QLabel{font:bold;font-size:14px}\n"
"QFrame { background:none}", 0));
        timeLabel->setText(QApplication::translate("RunViewer", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">TextLabel</span></p></body></html>", 0));
        groupBox_5->setTitle(QApplication::translate("RunViewer", "Pace", 0));
        paceLabel->setStyleSheet(QApplication::translate("RunViewer", "QLabel{font:bold;font-size:14px}\n"
"QFrame { background:none}", 0));
        paceLabel->setText(QApplication::translate("RunViewer", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">TextLabel</span></p></body></html>", 0));
        groupBox_6->setTitle(QApplication::translate("RunViewer", "Average Heartrate", 0));
        aveHrLabel->setStyleSheet(QApplication::translate("RunViewer", "QLabel{font:bold;font-size:14px}\n"
"QFrame { background:none}", 0));
        aveHrLabel->setText(QApplication::translate("RunViewer", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">TextLabel</span></p></body></html>", 0));
        groupBox_7->setTitle(QApplication::translate("RunViewer", "Max Heartrate", 0));
        maxHrLabel->setStyleSheet(QApplication::translate("RunViewer", "QLabel{font:bold;font-size:14px}\n"
"QFrame { background:none}", 0));
        maxHrLabel->setText(QApplication::translate("RunViewer", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">TextLabel</span></p></body></html>", 0));
        groupBox->setTitle(QApplication::translate("RunViewer", "Show", 0));
        paceCheckBox->setText(QApplication::translate("RunViewer", "Pace", 0));
        hrCheckBox->setText(QApplication::translate("RunViewer", "Heartrate", 0));
        editRunButton->setText(QApplication::translate("RunViewer", "Edit...", 0));
    } // retranslateUi

};

namespace Ui {
    class RunViewer: public Ui_RunViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNVIEWER_H
