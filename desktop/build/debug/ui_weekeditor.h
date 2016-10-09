/********************************************************************************
** Form generated from reading UI file 'weekeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEEKEDITOR_H
#define UI_WEEKEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "src/util/weekgraphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_WeekEditor
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *prevButton;
    QDateEdit *dateEdit;
    QPushButton *todayButton;
    QPushButton *nextButton;
    QSpacerItem *horizontalSpacer;
    WeekGraphicsView *mainView;
    QFrame *line;

    void setupUi(QWidget *WeekEditor)
    {
        if (WeekEditor->objectName().isEmpty())
            WeekEditor->setObjectName(QStringLiteral("WeekEditor"));
        WeekEditor->resize(667, 470);
        WeekEditor->setMinimumSize(QSize(600, 400));
        gridLayout = new QGridLayout(WeekEditor);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        prevButton = new QPushButton(WeekEditor);
        prevButton->setObjectName(QStringLiteral("prevButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/main/icons/leftarrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        prevButton->setIcon(icon);
        prevButton->setFlat(true);

        horizontalLayout->addWidget(prevButton);

        dateEdit = new QDateEdit(WeekEditor);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit);

        todayButton = new QPushButton(WeekEditor);
        todayButton->setObjectName(QStringLiteral("todayButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/main/icons/cal.png"), QSize(), QIcon::Normal, QIcon::Off);
        todayButton->setIcon(icon1);
        todayButton->setFlat(true);

        horizontalLayout->addWidget(todayButton);

        nextButton = new QPushButton(WeekEditor);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/main/icons/rightarrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextButton->setIcon(icon2);
        nextButton->setFlat(true);

        horizontalLayout->addWidget(nextButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        mainView = new WeekGraphicsView(WeekEditor);
        mainView->setObjectName(QStringLiteral("mainView"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainView->sizePolicy().hasHeightForWidth());
        mainView->setSizePolicy(sizePolicy);
        mainView->setMinimumSize(QSize(600, 400));
        mainView->setMaximumSize(QSize(16777215, 16777215));
        mainView->setFrameShape(QFrame::Panel);
        mainView->setFrameShadow(QFrame::Plain);
        mainView->setLineWidth(0);

        gridLayout->addWidget(mainView, 2, 0, 1, 1);

        line = new QFrame(WeekEditor);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 1);

        gridLayout->setRowStretch(2, 1);

        retranslateUi(WeekEditor);

        QMetaObject::connectSlotsByName(WeekEditor);
    } // setupUi

    void retranslateUi(QWidget *WeekEditor)
    {
        WeekEditor->setWindowTitle(QApplication::translate("WeekEditor", "Form", 0));
#ifndef QT_NO_TOOLTIP
        prevButton->setToolTip(QApplication::translate("WeekEditor", "Previous", 0));
#endif // QT_NO_TOOLTIP
        prevButton->setText(QString());
        dateEdit->setDisplayFormat(QApplication::translate("WeekEditor", "d-MMM-yyyy", 0));
#ifndef QT_NO_TOOLTIP
        todayButton->setToolTip(QApplication::translate("WeekEditor", "Today", 0));
#endif // QT_NO_TOOLTIP
        todayButton->setText(QString());
        todayButton->setShortcut(QApplication::translate("WeekEditor", "Ctrl+T", 0));
#ifndef QT_NO_TOOLTIP
        nextButton->setToolTip(QApplication::translate("WeekEditor", "Next", 0));
#endif // QT_NO_TOOLTIP
        nextButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WeekEditor: public Ui_WeekEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEEKEDITOR_H
