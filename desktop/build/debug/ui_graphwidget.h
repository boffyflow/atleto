/********************************************************************************
** Form generated from reading UI file 'graphwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHWIDGET_H
#define UI_GRAPHWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *propsButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *csvButton;
    QGraphicsView *plotView;

    void setupUi(QWidget *GraphWidget)
    {
        if (GraphWidget->objectName().isEmpty())
            GraphWidget->setObjectName(QStringLiteral("GraphWidget"));
        GraphWidget->resize(406, 300);
        gridLayout = new QGridLayout(GraphWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(3, -1, 3, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        propsButton = new QPushButton(GraphWidget);
        propsButton->setObjectName(QStringLiteral("propsButton"));

        horizontalLayout->addWidget(propsButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        csvButton = new QPushButton(GraphWidget);
        csvButton->setObjectName(QStringLiteral("csvButton"));

        horizontalLayout->addWidget(csvButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        plotView = new QGraphicsView(GraphWidget);
        plotView->setObjectName(QStringLiteral("plotView"));

        gridLayout->addWidget(plotView, 1, 0, 1, 1);


        retranslateUi(GraphWidget);

        QMetaObject::connectSlotsByName(GraphWidget);
    } // setupUi

    void retranslateUi(QWidget *GraphWidget)
    {
        GraphWidget->setWindowTitle(QApplication::translate("GraphWidget", "Form", 0));
        propsButton->setText(QApplication::translate("GraphWidget", "Properties", 0));
        csvButton->setText(QApplication::translate("GraphWidget", "Export to CSV...", 0));
    } // retranslateUi

};

namespace Ui {
    class GraphWidget: public Ui_GraphWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHWIDGET_H
