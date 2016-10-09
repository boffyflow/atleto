/********************************************************************************
** Form generated from reading UI file 'grapheditor.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHEDITOR_H
#define UI_GRAPHEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <src/util/querywidget.h>

QT_BEGIN_NAMESPACE

class Ui_GraphEditor
{
public:
    QGridLayout *gridLayout_2;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QueryWidget *queryWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *templateCombo;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *GraphEditor)
    {
        if (GraphEditor->objectName().isEmpty())
            GraphEditor->setObjectName(QStringLiteral("GraphEditor"));
        GraphEditor->resize(400, 367);
        gridLayout_2 = new QGridLayout(GraphEditor);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        buttonBox = new QDialogButtonBox(GraphEditor);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);

        groupBox = new QGroupBox(GraphEditor);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        nameLineEdit = new QLineEdit(groupBox);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        horizontalLayout->addWidget(nameLineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        queryWidget = new QueryWidget(groupBox_2);
        queryWidget->setObjectName(QStringLiteral("queryWidget"));

        gridLayout->addWidget(queryWidget, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        templateCombo = new QComboBox(groupBox);
        templateCombo->setObjectName(QStringLiteral("templateCombo"));

        horizontalLayout_2->addWidget(templateCombo);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout_3->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 138, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 3, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(GraphEditor);
        QObject::connect(buttonBox, SIGNAL(accepted()), GraphEditor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GraphEditor, SLOT(reject()));

        QMetaObject::connectSlotsByName(GraphEditor);
    } // setupUi

    void retranslateUi(QDialog *GraphEditor)
    {
        GraphEditor->setWindowTitle(QApplication::translate("GraphEditor", "Dialog", 0));
        label->setText(QApplication::translate("GraphEditor", "Name:", 0));
        groupBox_2->setTitle(QApplication::translate("GraphEditor", "Range", 0));
        label_2->setText(QApplication::translate("GraphEditor", "Template:", 0));
    } // retranslateUi

};

namespace Ui {
    class GraphEditor: public Ui_GraphEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHEDITOR_H
