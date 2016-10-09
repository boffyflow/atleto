/********************************************************************************
** Form generated from reading UI file 'plot.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOT_H
#define UI_PLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Plot
{
public:
    QGridLayout *gridLayout;
    QLabel *titleLabel;
    QGraphicsView *plotView;

    void setupUi(QWidget *Plot)
    {
        if (Plot->objectName().isEmpty())
            Plot->setObjectName(QStringLiteral("Plot"));
        Plot->resize(460, 316);
        gridLayout = new QGridLayout(Plot);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 3, 0, 0);
        titleLabel = new QLabel(Plot);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        titleLabel->setFont(font);
        titleLabel->setAutoFillBackground(false);
        titleLabel->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        titleLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(titleLabel, 0, 0, 1, 1);

        plotView = new QGraphicsView(Plot);
        plotView->setObjectName(QStringLiteral("plotView"));
        plotView->setFrameShape(QFrame::NoFrame);
        plotView->setFrameShadow(QFrame::Plain);
        plotView->setLineWidth(0);
        plotView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plotView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plotView->setSceneRect(QRectF(0, 0, 580, 400));

        gridLayout->addWidget(plotView, 1, 0, 1, 1);


        retranslateUi(Plot);

        QMetaObject::connectSlotsByName(Plot);
    } // setupUi

    void retranslateUi(QWidget *Plot)
    {
        Plot->setWindowTitle(QApplication::translate("Plot", "Form", 0));
        titleLabel->setText(QApplication::translate("Plot", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class Plot: public Ui_Plot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOT_H
