/********************************************************************************
** Form generated from reading UI file 'montheditor.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONTHEDITOR_H
#define UI_MONTHEDITOR_H

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
#include "src/util/monthgraphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_MonthEditor
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
    MonthGraphicsView *mainView;
    QFrame *line;

    void setupUi(QWidget *MonthEditor)
    {
        if (MonthEditor->objectName().isEmpty())
            MonthEditor->setObjectName(QStringLiteral("MonthEditor"));
        MonthEditor->resize(600, 400);
        MonthEditor->setMinimumSize(QSize(600, 400));
        gridLayout = new QGridLayout(MonthEditor);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        prevButton = new QPushButton(MonthEditor);
        prevButton->setObjectName(QStringLiteral("prevButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/main/icons/leftarrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        prevButton->setIcon(icon);
        prevButton->setFlat(true);

        horizontalLayout->addWidget(prevButton);

        dateEdit = new QDateEdit(MonthEditor);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit);

        todayButton = new QPushButton(MonthEditor);
        todayButton->setObjectName(QStringLiteral("todayButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/main/icons/cal.png"), QSize(), QIcon::Normal, QIcon::Off);
        todayButton->setIcon(icon1);
        todayButton->setFlat(true);

        horizontalLayout->addWidget(todayButton);

        nextButton = new QPushButton(MonthEditor);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/main/icons/rightarrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextButton->setIcon(icon2);
        nextButton->setFlat(true);

        horizontalLayout->addWidget(nextButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        mainView = new MonthGraphicsView(MonthEditor);
        mainView->setObjectName(QStringLiteral("mainView"));
        mainView->setMinimumSize(QSize(600, 400));
        mainView->setLineWidth(0);

        gridLayout->addWidget(mainView, 2, 0, 1, 1);

        line = new QFrame(MonthEditor);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 1);

        gridLayout->setRowStretch(1, 1);

        retranslateUi(MonthEditor);

        QMetaObject::connectSlotsByName(MonthEditor);
    } // setupUi

    void retranslateUi(QWidget *MonthEditor)
    {
        MonthEditor->setWindowTitle(QApplication::translate("MonthEditor", "Form", 0));
#ifndef QT_NO_TOOLTIP
        prevButton->setToolTip(QApplication::translate("MonthEditor", "Previous", 0));
#endif // QT_NO_TOOLTIP
        prevButton->setText(QString());
        dateEdit->setDisplayFormat(QApplication::translate("MonthEditor", "MMMM-yyyy", 0));
#ifndef QT_NO_TOOLTIP
        todayButton->setToolTip(QApplication::translate("MonthEditor", "Today", 0));
#endif // QT_NO_TOOLTIP
        todayButton->setText(QString());
        todayButton->setShortcut(QApplication::translate("MonthEditor", "Ctrl+T", 0));
#ifndef QT_NO_TOOLTIP
        nextButton->setToolTip(QApplication::translate("MonthEditor", "Next", 0));
#endif // QT_NO_TOOLTIP
        nextButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MonthEditor: public Ui_MonthEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONTHEDITOR_H
