/********************************************************************************
** Form generated from reading UI file 'previewplot.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREVIEWPLOT_H
#define UI_PREVIEWPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include "src/plot/svgview.h"

QT_BEGIN_NAMESPACE

class Ui_PreviewPlot
{
public:
    QGridLayout *gridLayout;
    SvgView *plotView;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PreviewPlot)
    {
        if (PreviewPlot->objectName().isEmpty())
            PreviewPlot->setObjectName(QStringLiteral("PreviewPlot"));
        PreviewPlot->resize(415, 324);
        PreviewPlot->setModal(true);
        gridLayout = new QGridLayout(PreviewPlot);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        plotView = new SvgView(PreviewPlot);
        plotView->setObjectName(QStringLiteral("plotView"));

        gridLayout->addWidget(plotView, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(PreviewPlot);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(PreviewPlot);
        QObject::connect(buttonBox, SIGNAL(accepted()), PreviewPlot, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PreviewPlot, SLOT(reject()));

        QMetaObject::connectSlotsByName(PreviewPlot);
    } // setupUi

    void retranslateUi(QDialog *PreviewPlot)
    {
        PreviewPlot->setWindowTitle(QApplication::translate("PreviewPlot", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class PreviewPlot: public Ui_PreviewPlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREVIEWPLOT_H
