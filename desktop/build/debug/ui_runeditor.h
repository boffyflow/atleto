/********************************************************************************
** Form generated from reading UI file 'runeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNEDITOR_H
#define UI_RUNEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RunEditor
{
public:
    QGridLayout *gridLayoutthree;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QVBoxLayout *_2;
    QTableView *inputTable;
    QHBoxLayout *_4;
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
    QLabel *hrLabel;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_1;
    QHBoxLayout *_15;
    QLabel *labelStartTime;
    QTimeEdit *startTimeEdit;
    QLabel *labelEndTime;
    QTimeEdit *endTimeEdit;
    QSpacerItem *spacerItem;
    QHBoxLayout *_10;
    QLabel *label;
    QComboBox *locationComboBox;
    QSpacerItem *spacerItem1;
    QHBoxLayout *_11;
    QLabel *label_3;
    QComboBox *runTypesComboBox;
    QSpacerItem *spacerItem2;
    QHBoxLayout *_12;
    QLabel *label_2;
    QComboBox *surfaceComboBox;
    QCheckBox *indoorsCheckBox;
    QSpacerItem *spacerItem3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *commentLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QComboBox *ratingComboBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *_14;
    QLabel *label_6;
    QComboBox *shoeComboBox;
    QSpacerItem *spacerItem4;
    QHBoxLayout *_3;
    QCheckBox *raceCheckBox;
    QPushButton *raceInfoButton;
    QSpacerItem *spacerItem5;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_2;
    QLabel *deviceFileLabel;
    QPushButton *reloadButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QDialogButtonBox *buttonBox;
    QPushButton *deleteButton;

    void setupUi(QDialog *RunEditor)
    {
        if (RunEditor->objectName().isEmpty())
            RunEditor->setObjectName(QStringLiteral("RunEditor"));
        RunEditor->resize(696, 394);
        QIcon icon;
        icon.addFile(QStringLiteral(":/main/icons/runner32.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        RunEditor->setWindowIcon(icon);
        RunEditor->setModal(false);
        gridLayoutthree = new QGridLayout(RunEditor);
        gridLayoutthree->setObjectName(QStringLiteral("gridLayoutthree"));
        groupBox_2 = new QGroupBox(RunEditor);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        _2 = new QVBoxLayout();
        _2->setObjectName(QStringLiteral("_2"));
        inputTable = new QTableView(groupBox_2);
        inputTable->setObjectName(QStringLiteral("inputTable"));
        inputTable->setAlternatingRowColors(true);
        inputTable->setShowGrid(true);
        inputTable->setGridStyle(Qt::SolidLine);
        inputTable->setSortingEnabled(false);

        _2->addWidget(inputTable);

        _4 = new QHBoxLayout();
        _4->setObjectName(QStringLiteral("_4"));
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


        _4->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        _6 = new QGridLayout(groupBox_4);
        _6->setSpacing(3);
        _6->setContentsMargins(3, 3, 3, 3);
        _6->setObjectName(QStringLiteral("_6"));
        timeLabel = new QLabel(groupBox_4);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));

        _6->addWidget(timeLabel, 0, 0, 1, 1);


        _4->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(groupBox_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        _7 = new QGridLayout(groupBox_5);
        _7->setSpacing(3);
        _7->setContentsMargins(3, 3, 3, 3);
        _7->setObjectName(QStringLiteral("_7"));
        paceLabel = new QLabel(groupBox_5);
        paceLabel->setObjectName(QStringLiteral("paceLabel"));

        _7->addWidget(paceLabel, 0, 0, 1, 1);


        _4->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(groupBox_2);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        _8 = new QGridLayout(groupBox_6);
        _8->setSpacing(3);
        _8->setContentsMargins(3, 3, 3, 3);
        _8->setObjectName(QStringLiteral("_8"));
        hrLabel = new QLabel(groupBox_6);
        hrLabel->setObjectName(QStringLiteral("hrLabel"));

        _8->addWidget(hrLabel, 0, 0, 1, 1);


        _4->addWidget(groupBox_6);


        _2->addLayout(_4);


        gridLayout->addLayout(_2, 0, 0, 1, 1);


        gridLayoutthree->addWidget(groupBox_2, 0, 0, 2, 1);

        groupBox = new QGroupBox(RunEditor);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setAlignment(Qt::AlignLeading);
        gridLayout_1 = new QGridLayout(groupBox);
        gridLayout_1->setObjectName(QStringLiteral("gridLayout_1"));
        _15 = new QHBoxLayout();
#ifndef Q_OS_MAC
        _15->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        _15->setContentsMargins(0, 0, 0, 0);
#endif
        _15->setObjectName(QStringLiteral("_15"));
        labelStartTime = new QLabel(groupBox);
        labelStartTime->setObjectName(QStringLiteral("labelStartTime"));
        labelStartTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelStartTime->setWordWrap(false);

        _15->addWidget(labelStartTime);

        startTimeEdit = new QTimeEdit(groupBox);
        startTimeEdit->setObjectName(QStringLiteral("startTimeEdit"));

        _15->addWidget(startTimeEdit);

        labelEndTime = new QLabel(groupBox);
        labelEndTime->setObjectName(QStringLiteral("labelEndTime"));
        labelEndTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelEndTime->setWordWrap(false);

        _15->addWidget(labelEndTime);

        endTimeEdit = new QTimeEdit(groupBox);
        endTimeEdit->setObjectName(QStringLiteral("endTimeEdit"));

        _15->addWidget(endTimeEdit);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _15->addItem(spacerItem);


        gridLayout_1->addLayout(_15, 0, 0, 1, 1);

        _10 = new QHBoxLayout();
        _10->setObjectName(QStringLiteral("_10"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(100, 0));
        label->setMaximumSize(QSize(100, 16777215));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        _10->addWidget(label);

        locationComboBox = new QComboBox(groupBox);
        locationComboBox->setObjectName(QStringLiteral("locationComboBox"));
        locationComboBox->setEditable(true);
        locationComboBox->setMaxVisibleItems(20);
        locationComboBox->setInsertPolicy(QComboBox::InsertAlphabetically);

        _10->addWidget(locationComboBox);

        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _10->addItem(spacerItem1);


        gridLayout_1->addLayout(_10, 1, 0, 1, 1);

        _11 = new QHBoxLayout();
        _11->setObjectName(QStringLiteral("_11"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(100, 0));
        label_3->setMaximumSize(QSize(100, 16777215));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        _11->addWidget(label_3);

        runTypesComboBox = new QComboBox(groupBox);
        runTypesComboBox->setObjectName(QStringLiteral("runTypesComboBox"));
        runTypesComboBox->setEditable(true);
        runTypesComboBox->setInsertPolicy(QComboBox::InsertAlphabetically);

        _11->addWidget(runTypesComboBox);

        spacerItem2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _11->addItem(spacerItem2);


        gridLayout_1->addLayout(_11, 2, 0, 1, 1);

        _12 = new QHBoxLayout();
        _12->setObjectName(QStringLiteral("_12"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(100, 0));
        label_2->setMaximumSize(QSize(100, 16777215));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        _12->addWidget(label_2);

        surfaceComboBox = new QComboBox(groupBox);
        surfaceComboBox->setObjectName(QStringLiteral("surfaceComboBox"));
        surfaceComboBox->setEditable(true);
        surfaceComboBox->setInsertPolicy(QComboBox::InsertAlphabetically);

        _12->addWidget(surfaceComboBox);

        indoorsCheckBox = new QCheckBox(groupBox);
        indoorsCheckBox->setObjectName(QStringLiteral("indoorsCheckBox"));

        _12->addWidget(indoorsCheckBox);

        spacerItem3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _12->addItem(spacerItem3);


        gridLayout_1->addLayout(_12, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(100, 0));
        label_4->setMaximumSize(QSize(100, 16777215));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_4);

        commentLineEdit = new QLineEdit(groupBox);
        commentLineEdit->setObjectName(QStringLiteral("commentLineEdit"));

        horizontalLayout_3->addWidget(commentLineEdit);


        gridLayout_1->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(100, 0));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_5);

        ratingComboBox = new QComboBox(groupBox);
        ratingComboBox->setObjectName(QStringLiteral("ratingComboBox"));

        horizontalLayout_2->addWidget(ratingComboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout_1->addLayout(horizontalLayout_2, 5, 0, 1, 1);

        _14 = new QHBoxLayout();
        _14->setObjectName(QStringLiteral("_14"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(100, 0));
        label_6->setMaximumSize(QSize(100, 16777215));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        _14->addWidget(label_6);

        shoeComboBox = new QComboBox(groupBox);
        shoeComboBox->setObjectName(QStringLiteral("shoeComboBox"));
        shoeComboBox->setInsertPolicy(QComboBox::InsertAlphabetically);

        _14->addWidget(shoeComboBox);

        spacerItem4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _14->addItem(spacerItem4);


        gridLayout_1->addLayout(_14, 6, 0, 1, 1);

        _3 = new QHBoxLayout();
        _3->setObjectName(QStringLiteral("_3"));
        raceCheckBox = new QCheckBox(groupBox);
        raceCheckBox->setObjectName(QStringLiteral("raceCheckBox"));
        raceCheckBox->setMinimumSize(QSize(0, 0));

        _3->addWidget(raceCheckBox);

        raceInfoButton = new QPushButton(groupBox);
        raceInfoButton->setObjectName(QStringLiteral("raceInfoButton"));
        raceInfoButton->setEnabled(false);

        _3->addWidget(raceInfoButton);

        spacerItem5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _3->addItem(spacerItem5);


        gridLayout_1->addLayout(_3, 7, 0, 1, 1);


        gridLayoutthree->addWidget(groupBox, 0, 1, 1, 1);

        groupBox_7 = new QGroupBox(RunEditor);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        gridLayout_2 = new QGridLayout(groupBox_7);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        deviceFileLabel = new QLabel(groupBox_7);
        deviceFileLabel->setObjectName(QStringLiteral("deviceFileLabel"));

        gridLayout_2->addWidget(deviceFileLabel, 0, 0, 1, 2);

        reloadButton = new QPushButton(groupBox_7);
        reloadButton->setObjectName(QStringLiteral("reloadButton"));

        gridLayout_2->addWidget(reloadButton, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(226, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);


        gridLayoutthree->addWidget(groupBox_7, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        buttonBox = new QDialogButtonBox(RunEditor);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        horizontalLayout->addWidget(buttonBox);

        deleteButton = new QPushButton(RunEditor);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        horizontalLayout->addWidget(deleteButton);


        gridLayoutthree->addLayout(horizontalLayout, 2, 1, 1, 1);


        retranslateUi(RunEditor);
        QObject::connect(buttonBox, SIGNAL(accepted()), RunEditor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RunEditor, SLOT(reject()));

        QMetaObject::connectSlotsByName(RunEditor);
    } // setupUi

    void retranslateUi(QDialog *RunEditor)
    {
        RunEditor->setWindowTitle(QApplication::translate("RunEditor", "Run Editor", 0));
        groupBox_2->setTitle(QApplication::translate("RunEditor", "Run", 0));
        inputTable->setStyleSheet(QApplication::translate("RunEditor", "QFrame { background:none}", 0));
        groupBox_3->setTitle(QApplication::translate("RunEditor", "Distance", 0));
        distanceLabel->setStyleSheet(QApplication::translate("RunEditor", "QLabel{font:bold;font-size:14px}\n"
"QFrame { background:none}\n"
"", 0));
        distanceLabel->setText(QApplication::translate("RunEditor", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">TextLabel</span></p></body></html>", 0));
        groupBox_4->setTitle(QApplication::translate("RunEditor", "Time", 0));
        timeLabel->setStyleSheet(QApplication::translate("RunEditor", "QLabel{font:bold;font-size:14px}\n"
"QFrame { background:none}", 0));
        timeLabel->setText(QApplication::translate("RunEditor", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">TextLabel</span></p></body></html>", 0));
        groupBox_5->setTitle(QApplication::translate("RunEditor", "Pace", 0));
        paceLabel->setStyleSheet(QApplication::translate("RunEditor", "QLabel{font:bold;font-size:14px}\n"
"QFrame { background:none}", 0));
        paceLabel->setText(QApplication::translate("RunEditor", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">TextLabel</span></p></body></html>", 0));
        groupBox_6->setTitle(QApplication::translate("RunEditor", "Heartrate", 0));
        hrLabel->setStyleSheet(QApplication::translate("RunEditor", "QLabel{font:bold;font-size:14px}\n"
"QFrame { background:none}", 0));
        hrLabel->setText(QApplication::translate("RunEditor", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">TextLabel</span></p></body></html>", 0));
        groupBox->setTitle(QApplication::translate("RunEditor", "General", 0));
        labelStartTime->setStyleSheet(QApplication::translate("RunEditor", "QFrame { background:none}", 0));
        labelStartTime->setText(QApplication::translate("RunEditor", "Start time:", 0));
        startTimeEdit->setDisplayFormat(QApplication::translate("RunEditor", "HH:mm", 0));
        labelEndTime->setStyleSheet(QApplication::translate("RunEditor", "QFrame { background:none}", 0));
        labelEndTime->setText(QApplication::translate("RunEditor", "End time:", 0));
        endTimeEdit->setDisplayFormat(QApplication::translate("RunEditor", "HH:mm", 0));
        label->setStyleSheet(QApplication::translate("RunEditor", "QFrame { background:none}", 0));
        label->setText(QApplication::translate("RunEditor", "Location:", 0));
        locationComboBox->setStyleSheet(QApplication::translate("RunEditor", "QFrame { background:none}", 0));
        label_3->setStyleSheet(QApplication::translate("RunEditor", "QFrame { background:none}", 0));
        label_3->setText(QApplication::translate("RunEditor", "Type of Workout:", 0));
        runTypesComboBox->setStyleSheet(QApplication::translate("RunEditor", "QFrame { background:none}", 0));
        label_2->setStyleSheet(QApplication::translate("RunEditor", "QFrame { background:none}", 0));
        label_2->setText(QApplication::translate("RunEditor", "Surface:", 0));
        surfaceComboBox->setStyleSheet(QApplication::translate("RunEditor", "QFrame { background:none}", 0));
        indoorsCheckBox->setText(QApplication::translate("RunEditor", "Indoors", 0));
        label_4->setStyleSheet(QApplication::translate("RunEditor", "QFrame { background:none}", 0));
        label_4->setText(QApplication::translate("RunEditor", "Notes:", 0));
        label_5->setStyleSheet(QApplication::translate("RunEditor", "QFrame { background:none}", 0));
        label_5->setText(QApplication::translate("RunEditor", "Rating:", 0));
        ratingComboBox->clear();
        ratingComboBox->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("RunEditor", "Bad", 0)
         << QApplication::translate("RunEditor", "Fair", 0)
         << QApplication::translate("RunEditor", "Good", 0)
         << QApplication::translate("RunEditor", "Very good", 0)
         << QApplication::translate("RunEditor", "Excellent", 0)
        );
        ratingComboBox->setStyleSheet(QApplication::translate("RunEditor", "QFrame { background:none}", 0));
        label_6->setStyleSheet(QApplication::translate("RunEditor", "QFrame { background:none}", 0));
        label_6->setText(QApplication::translate("RunEditor", "Shoe:", 0));
        shoeComboBox->setStyleSheet(QApplication::translate("RunEditor", "QFrame { background:none}", 0));
        raceCheckBox->setText(QApplication::translate("RunEditor", "Race", 0));
        raceInfoButton->setText(QApplication::translate("RunEditor", "Info...", 0));
        groupBox_7->setTitle(QApplication::translate("RunEditor", "Device File", 0));
        deviceFileLabel->setText(QApplication::translate("RunEditor", "Device file", 0));
        reloadButton->setText(QApplication::translate("RunEditor", "Reload Splits...", 0));
        deleteButton->setText(QApplication::translate("RunEditor", "Delete", 0));
    } // retranslateUi

};

namespace Ui {
    class RunEditor: public Ui_RunEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNEDITOR_H
