/********************************************************************************
** Form generated from reading UI file 'calendarwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDARWIDGET_H
#define UI_CALENDARWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "src/gui/editorwidget.h"
#include "src/gui/montheditor.h"
#include "src/gui/weekeditor.h"

QT_BEGIN_NAMESPACE

class Ui_CalendarWidget
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *summaryGroup;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_7;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *distLabel;
    QLabel *timeLabel;
    QLabel *paceLabel;
    QLabel *label_7;
    QFrame *frame;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBoxWeight;
    QGridLayout *gridLayout_5;
    QLabel *label;
    QLabel *maxWeightLabel;
    QLabel *label_2;
    QLabel *aveWeightLabel;
    QLabel *label_3;
    QLabel *minWeightLabel;
    QGroupBox *groupBoxBodyfat;
    QGridLayout *gridLayout_3;
    QLabel *label_13;
    QLabel *bfMax;
    QLabel *label_15;
    QLabel *bfAverage;
    QLabel *label_17;
    QLabel *bfMin;
    QGroupBox *groupBoxHeartrate;
    QGridLayout *gridLayout_4;
    QLabel *label_10;
    QLabel *aveHRLabel;
    QLabel *maxHRLabel;
    QLabel *label_8;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget;
    EditorWidget *dayView;
    WeekEditor *weekView;
    MonthEditor *monthView;
    QWidget *tab;
    QGridLayout *gridLayout_8;
    QTreeWidget *diaryTree;

    void setupUi(QWidget *CalendarWidget)
    {
        if (CalendarWidget->objectName().isEmpty())
            CalendarWidget->setObjectName(QStringLiteral("CalendarWidget"));
        CalendarWidget->resize(840, 661);
        gridLayout_2 = new QGridLayout(CalendarWidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        summaryGroup = new QGroupBox(CalendarWidget);
        summaryGroup->setObjectName(QStringLiteral("summaryGroup"));
        summaryGroup->setEnabled(true);
        summaryGroup->setAlignment(Qt::AlignCenter);
        summaryGroup->setFlat(false);
        gridLayout_9 = new QGridLayout(summaryGroup);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 3, 0, 0);
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(0);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        frame_2 = new QFrame(summaryGroup);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setStyleSheet(QStringLiteral("background-color: rgb(215, 250, 255);"));
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        distLabel = new QLabel(frame_2);
        distLabel->setObjectName(QStringLiteral("distLabel"));

        gridLayout->addWidget(distLabel, 1, 1, 1, 1);

        timeLabel = new QLabel(frame_2);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));

        gridLayout->addWidget(timeLabel, 2, 1, 1, 1);

        paceLabel = new QLabel(frame_2);
        paceLabel->setObjectName(QStringLiteral("paceLabel"));

        gridLayout->addWidget(paceLabel, 3, 1, 1, 1);

        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/main/icons/runner.xpm")));

        gridLayout->addWidget(label_7, 0, 0, 1, 1);


        gridLayout_7->addWidget(frame_2, 0, 0, 1, 1);

        frame = new QFrame(summaryGroup);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QStringLiteral("background-color: rgb(233, 255, 198);"));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        groupBoxWeight = new QGroupBox(frame);
        groupBoxWeight->setObjectName(QStringLiteral("groupBoxWeight"));
        groupBoxWeight->setAlignment(Qt::AlignCenter);
        gridLayout_5 = new QGridLayout(groupBoxWeight);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label = new QLabel(groupBoxWeight);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        maxWeightLabel = new QLabel(groupBoxWeight);
        maxWeightLabel->setObjectName(QStringLiteral("maxWeightLabel"));
        maxWeightLabel->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));

        gridLayout_5->addWidget(maxWeightLabel, 0, 1, 1, 1);

        label_2 = new QLabel(groupBoxWeight);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("color: rgb(0, 0, 127);"));

        gridLayout_5->addWidget(label_2, 1, 0, 1, 1);

        aveWeightLabel = new QLabel(groupBoxWeight);
        aveWeightLabel->setObjectName(QStringLiteral("aveWeightLabel"));
        aveWeightLabel->setStyleSheet(QStringLiteral("color: rgb(0, 0, 127);"));

        gridLayout_5->addWidget(aveWeightLabel, 1, 1, 1, 1);

        label_3 = new QLabel(groupBoxWeight);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("color: rgb(0, 85, 0);"));

        gridLayout_5->addWidget(label_3, 2, 0, 1, 1);

        minWeightLabel = new QLabel(groupBoxWeight);
        minWeightLabel->setObjectName(QStringLiteral("minWeightLabel"));
        minWeightLabel->setStyleSheet(QStringLiteral("color: rgb(0, 85, 0);"));

        gridLayout_5->addWidget(minWeightLabel, 2, 1, 1, 1);


        gridLayout_6->addWidget(groupBoxWeight, 0, 0, 1, 1);

        groupBoxBodyfat = new QGroupBox(frame);
        groupBoxBodyfat->setObjectName(QStringLiteral("groupBoxBodyfat"));
        groupBoxBodyfat->setAlignment(Qt::AlignCenter);
        gridLayout_3 = new QGridLayout(groupBoxBodyfat);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_13 = new QLabel(groupBoxBodyfat);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));

        gridLayout_3->addWidget(label_13, 0, 0, 1, 1);

        bfMax = new QLabel(groupBoxBodyfat);
        bfMax->setObjectName(QStringLiteral("bfMax"));
        bfMax->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));

        gridLayout_3->addWidget(bfMax, 0, 1, 1, 1);

        label_15 = new QLabel(groupBoxBodyfat);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setStyleSheet(QStringLiteral("color: rgb(0, 0, 127);"));

        gridLayout_3->addWidget(label_15, 1, 0, 1, 1);

        bfAverage = new QLabel(groupBoxBodyfat);
        bfAverage->setObjectName(QStringLiteral("bfAverage"));
        bfAverage->setStyleSheet(QStringLiteral("color: rgb(0, 0, 127);"));

        gridLayout_3->addWidget(bfAverage, 1, 1, 1, 1);

        label_17 = new QLabel(groupBoxBodyfat);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setStyleSheet(QStringLiteral("color: rgb(0, 85, 0)"));

        gridLayout_3->addWidget(label_17, 2, 0, 1, 1);

        bfMin = new QLabel(groupBoxBodyfat);
        bfMin->setObjectName(QStringLiteral("bfMin"));
        bfMin->setStyleSheet(QStringLiteral("color: rgb(0, 85, 0)"));

        gridLayout_3->addWidget(bfMin, 2, 1, 1, 1);


        gridLayout_6->addWidget(groupBoxBodyfat, 1, 0, 1, 1);

        groupBoxHeartrate = new QGroupBox(frame);
        groupBoxHeartrate->setObjectName(QStringLiteral("groupBoxHeartrate"));
        groupBoxHeartrate->setAlignment(Qt::AlignCenter);
        groupBoxHeartrate->setFlat(false);
        groupBoxHeartrate->setCheckable(false);
        gridLayout_4 = new QGridLayout(groupBoxHeartrate);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_10 = new QLabel(groupBoxHeartrate);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setStyleSheet(QStringLiteral("color: rgb(0, 0, 127);"));

        gridLayout_4->addWidget(label_10, 1, 0, 1, 1);

        aveHRLabel = new QLabel(groupBoxHeartrate);
        aveHRLabel->setObjectName(QStringLiteral("aveHRLabel"));
        aveHRLabel->setStyleSheet(QStringLiteral("color: rgb(0, 0, 127);"));

        gridLayout_4->addWidget(aveHRLabel, 1, 1, 1, 1);

        maxHRLabel = new QLabel(groupBoxHeartrate);
        maxHRLabel->setObjectName(QStringLiteral("maxHRLabel"));
        maxHRLabel->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));

        gridLayout_4->addWidget(maxHRLabel, 0, 1, 1, 1);

        label_8 = new QLabel(groupBoxHeartrate);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));

        gridLayout_4->addWidget(label_8, 0, 0, 1, 1);

        label_10->raise();
        aveHRLabel->raise();
        maxHRLabel->raise();
        label_8->raise();

        gridLayout_6->addWidget(groupBoxHeartrate, 2, 0, 1, 1);


        gridLayout_7->addWidget(frame, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer, 2, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_7, 0, 0, 1, 1);


        gridLayout_2->addWidget(summaryGroup, 0, 1, 2, 1);

        tabWidget = new QTabWidget(CalendarWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        dayView = new EditorWidget();
        dayView->setObjectName(QStringLiteral("dayView"));
        tabWidget->addTab(dayView, QString());
        weekView = new WeekEditor();
        weekView->setObjectName(QStringLiteral("weekView"));
        tabWidget->addTab(weekView, QString());
        monthView = new MonthEditor();
        monthView->setObjectName(QStringLiteral("monthView"));
        tabWidget->addTab(monthView, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_8 = new QGridLayout(tab);
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        diaryTree = new QTreeWidget(tab);
        new QTreeWidgetItem(diaryTree);
        diaryTree->setObjectName(QStringLiteral("diaryTree"));

        gridLayout_8->addWidget(diaryTree, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());

        gridLayout_2->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(CalendarWidget);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(CalendarWidget);
    } // setupUi

    void retranslateUi(QWidget *CalendarWidget)
    {
        CalendarWidget->setWindowTitle(QApplication::translate("CalendarWidget", "Form", 0));
        summaryGroup->setTitle(QApplication::translate("CalendarWidget", "Summary", 0));
        label_4->setText(QApplication::translate("CalendarWidget", "Distance", 0));
        label_5->setText(QApplication::translate("CalendarWidget", "Time", 0));
        label_6->setText(QApplication::translate("CalendarWidget", "Pace", 0));
        distLabel->setText(QApplication::translate("CalendarWidget", "TextLabel", 0));
        timeLabel->setText(QApplication::translate("CalendarWidget", "TextLabel", 0));
        paceLabel->setText(QApplication::translate("CalendarWidget", "TextLabel", 0));
        label_7->setText(QString());
        groupBoxWeight->setTitle(QApplication::translate("CalendarWidget", "Weight", 0));
        label->setText(QApplication::translate("CalendarWidget", "Max", 0));
        maxWeightLabel->setText(QApplication::translate("CalendarWidget", "TextLabel", 0));
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("CalendarWidget", "Weight", 0));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("CalendarWidget", "Average", 0));
        aveWeightLabel->setText(QApplication::translate("CalendarWidget", "TextLabel", 0));
        label_3->setText(QApplication::translate("CalendarWidget", "Min", 0));
        minWeightLabel->setText(QApplication::translate("CalendarWidget", "TextLabel", 0));
        groupBoxBodyfat->setTitle(QApplication::translate("CalendarWidget", "Bodyfat", 0));
        label_13->setText(QApplication::translate("CalendarWidget", "Max", 0));
        bfMax->setText(QApplication::translate("CalendarWidget", "TextLabel", 0));
        label_15->setText(QApplication::translate("CalendarWidget", "Average", 0));
        bfAverage->setText(QApplication::translate("CalendarWidget", "TextLabel", 0));
        label_17->setText(QApplication::translate("CalendarWidget", "Min", 0));
        bfMin->setText(QApplication::translate("CalendarWidget", "TextLabel", 0));
        groupBoxHeartrate->setTitle(QApplication::translate("CalendarWidget", "Heartrate", 0));
        label_10->setText(QApplication::translate("CalendarWidget", "Average", 0));
        aveHRLabel->setText(QApplication::translate("CalendarWidget", "TextLabel", 0));
        maxHRLabel->setText(QApplication::translate("CalendarWidget", "TextLabel", 0));
        label_8->setText(QApplication::translate("CalendarWidget", "Max", 0));
        tabWidget->setTabText(tabWidget->indexOf(dayView), QApplication::translate("CalendarWidget", "Day", 0));
        tabWidget->setTabText(tabWidget->indexOf(weekView), QApplication::translate("CalendarWidget", "Week", 0));
        tabWidget->setTabText(tabWidget->indexOf(monthView), QApplication::translate("CalendarWidget", "Month", 0));
        QTreeWidgetItem *___qtreewidgetitem = diaryTree->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("CalendarWidget", "Complete Diary", 0));

        const bool __sortingEnabled = diaryTree->isSortingEnabled();
        diaryTree->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = diaryTree->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("CalendarWidget", "All years", 0));
        diaryTree->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("CalendarWidget", "All", 0));
    } // retranslateUi

};

namespace Ui {
    class CalendarWidget: public Ui_CalendarWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDARWIDGET_H
