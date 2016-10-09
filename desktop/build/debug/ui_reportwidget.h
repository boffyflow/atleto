/********************************************************************************
** Form generated from reading UI file 'reportwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTWIDGET_H
#define UI_REPORTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *addGraphButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *cascadeButton;
    QPushButton *tileButton;
    QSplitter *splitter;
    QMdiArea *mdiArea;

    void setupUi(QWidget *ReportWidget)
    {
        if (ReportWidget->objectName().isEmpty())
            ReportWidget->setObjectName(QStringLiteral("ReportWidget"));
        ReportWidget->resize(789, 580);
        gridLayout = new QGridLayout(ReportWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addGraphButton = new QPushButton(ReportWidget);
        addGraphButton->setObjectName(QStringLiteral("addGraphButton"));
        addGraphButton->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(addGraphButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cascadeButton = new QPushButton(ReportWidget);
        cascadeButton->setObjectName(QStringLiteral("cascadeButton"));

        horizontalLayout->addWidget(cascadeButton);

        tileButton = new QPushButton(ReportWidget);
        tileButton->setObjectName(QStringLiteral("tileButton"));

        horizontalLayout->addWidget(tileButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        splitter = new QSplitter(ReportWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        mdiArea = new QMdiArea(splitter);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        mdiArea->setViewMode(QMdiArea::SubWindowView);
        mdiArea->setDocumentMode(false);
        splitter->addWidget(mdiArea);

        gridLayout->addWidget(splitter, 1, 0, 1, 1);


        retranslateUi(ReportWidget);

        QMetaObject::connectSlotsByName(ReportWidget);
    } // setupUi

    void retranslateUi(QWidget *ReportWidget)
    {
        ReportWidget->setWindowTitle(QApplication::translate("ReportWidget", "Form", 0));
        ReportWidget->setStyleSheet(QApplication::translate("ReportWidget", "QFrame {background: none;}", 0));
        addGraphButton->setText(QApplication::translate("ReportWidget", "Add Graph...", 0));
        cascadeButton->setText(QApplication::translate("ReportWidget", "Cascade", 0));
        tileButton->setText(QApplication::translate("ReportWidget", "Tile", 0));
    } // retranslateUi

};

namespace Ui {
    class ReportWidget: public Ui_ReportWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTWIDGET_H
