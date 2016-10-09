/********************************************************************************
** Form generated from reading UI file 'ploteditor.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTEDITOR_H
#define UI_PLOTEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_PlotEditor
{
public:
    QGridLayout *gridLayout;
    QFrame *contentFrame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *PlotEditor)
    {
        if (PlotEditor->objectName().isEmpty())
            PlotEditor->setObjectName(QStringLiteral("PlotEditor"));
        PlotEditor->resize(474, 501);
        PlotEditor->setModal(true);
        gridLayout = new QGridLayout(PlotEditor);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        contentFrame = new QFrame(PlotEditor);
        contentFrame->setObjectName(QStringLiteral("contentFrame"));
        contentFrame->setFrameShape(QFrame::StyledPanel);
        contentFrame->setFrameShadow(QFrame::Plain);
        contentFrame->setLineWidth(2);
        contentFrame->setMidLineWidth(2);

        gridLayout->addWidget(contentFrame, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(PlotEditor);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);

        retranslateUi(PlotEditor);

        QMetaObject::connectSlotsByName(PlotEditor);
    } // setupUi

    void retranslateUi(QDialog *PlotEditor)
    {
        PlotEditor->setWindowTitle(QApplication::translate("PlotEditor", "Dialog", 0));
        pushButton->setText(QApplication::translate("PlotEditor", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class PlotEditor: public Ui_PlotEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTEDITOR_H
