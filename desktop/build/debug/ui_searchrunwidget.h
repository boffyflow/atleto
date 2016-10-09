/********************************************************************************
** Form generated from reading UI file 'searchrunwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHRUNWIDGET_H
#define UI_SEARCHRUNWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include <src/util/querywidget.h>

QT_BEGIN_NAMESPACE

class Ui_SearchRunWidget
{
public:
    QGridLayout *gridLayout;
    QueryWidget *queryWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *searchButton;
    QSpacerItem *horizontalSpacer;
    QTreeWidget *resultsWidget;

    void setupUi(QWidget *SearchRunWidget)
    {
        if (SearchRunWidget->objectName().isEmpty())
            SearchRunWidget->setObjectName(QStringLiteral("SearchRunWidget"));
        SearchRunWidget->resize(400, 300);
        gridLayout = new QGridLayout(SearchRunWidget);
        gridLayout->setSpacing(3);
        gridLayout->setContentsMargins(3, 3, 3, 3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        queryWidget = new QueryWidget(SearchRunWidget);
        queryWidget->setObjectName(QStringLiteral("queryWidget"));

        gridLayout->addWidget(queryWidget, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        searchButton = new QPushButton(SearchRunWidget);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setAutoDefault(true);
        searchButton->setFlat(false);

        horizontalLayout_2->addWidget(searchButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        resultsWidget = new QTreeWidget(SearchRunWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        resultsWidget->setHeaderItem(__qtreewidgetitem);
        resultsWidget->setObjectName(QStringLiteral("resultsWidget"));
        resultsWidget->setAlternatingRowColors(true);
        resultsWidget->setExpandsOnDoubleClick(false);
        resultsWidget->header()->setVisible(false);

        gridLayout->addWidget(resultsWidget, 2, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 10);

        retranslateUi(SearchRunWidget);

        searchButton->setDefault(false);


        QMetaObject::connectSlotsByName(SearchRunWidget);
    } // setupUi

    void retranslateUi(QWidget *SearchRunWidget)
    {
        SearchRunWidget->setWindowTitle(QApplication::translate("SearchRunWidget", "Form", 0));
        searchButton->setText(QApplication::translate("SearchRunWidget", "Search", 0));
        resultsWidget->setStyleSheet(QApplication::translate("SearchRunWidget", "QTreeWidget { background: white;}", 0));
    } // retranslateUi

};

namespace Ui {
    class SearchRunWidget: public Ui_SearchRunWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHRUNWIDGET_H
