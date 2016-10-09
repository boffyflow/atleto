/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "src/gui/calendarwidget.h"
#include "src/gui/raceswidget.h"
#include "src/gui/reportwidget.h"
#include "src/gui/searchrunwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionAbout_Qt;
    QAction *actionAbout_Atleto;
    QAction *actionReport_Generator;
    QAction *actionQuit;
    QAction *actionAthlete;
    QAction *actionSearch_Run;
    QAction *actionRun_Calculator;
    QAction *actionShoes;
    QAction *actionCalendar;
    QAction *actionRaces;
    QAction *actionPlot;
    QAction *actionOptions;
    QAction *actionImport_TCX;
    QAction *actionPlotTest;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QStackedWidget *mainContent;
    CalendarWidget *calendarPage;
    ReportWidget *reportPage;
    SearchRunWidget *searchRunPage;
    RacesWidget *racesPage;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuHelp;
    QMenu *menuTools;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(600, 533);
        QIcon icon;
        icon.addFile(QStringLiteral(":/main/icons/runner32.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowClass->setWindowIcon(icon);
        actionAbout_Qt = new QAction(MainWindowClass);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        actionAbout_Atleto = new QAction(MainWindowClass);
        actionAbout_Atleto->setObjectName(QStringLiteral("actionAbout_Atleto"));
        actionReport_Generator = new QAction(MainWindowClass);
        actionReport_Generator->setObjectName(QStringLiteral("actionReport_Generator"));
        actionReport_Generator->setCheckable(true);
        actionReport_Generator->setEnabled(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/main/icons/report.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReport_Generator->setIcon(icon1);
        actionQuit = new QAction(MainWindowClass);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionAthlete = new QAction(MainWindowClass);
        actionAthlete->setObjectName(QStringLiteral("actionAthlete"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/main/icons/athlete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAthlete->setIcon(icon2);
        actionSearch_Run = new QAction(MainWindowClass);
        actionSearch_Run->setObjectName(QStringLiteral("actionSearch_Run"));
        actionSearch_Run->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/main/icons/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSearch_Run->setIcon(icon3);
        actionRun_Calculator = new QAction(MainWindowClass);
        actionRun_Calculator->setObjectName(QStringLiteral("actionRun_Calculator"));
        actionShoes = new QAction(MainWindowClass);
        actionShoes->setObjectName(QStringLiteral("actionShoes"));
        actionCalendar = new QAction(MainWindowClass);
        actionCalendar->setObjectName(QStringLiteral("actionCalendar"));
        actionCalendar->setCheckable(true);
        actionCalendar->setChecked(true);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/main/icons/cal.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCalendar->setIcon(icon4);
        actionRaces = new QAction(MainWindowClass);
        actionRaces->setObjectName(QStringLiteral("actionRaces"));
        actionRaces->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/main/icons/trophy.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        actionRaces->setIcon(icon5);
        actionPlot = new QAction(MainWindowClass);
        actionPlot->setObjectName(QStringLiteral("actionPlot"));
        actionOptions = new QAction(MainWindowClass);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        actionImport_TCX = new QAction(MainWindowClass);
        actionImport_TCX->setObjectName(QStringLiteral("actionImport_TCX"));
        actionPlotTest = new QAction(MainWindowClass);
        actionPlotTest->setObjectName(QStringLiteral("actionPlotTest"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        mainContent = new QStackedWidget(centralWidget);
        mainContent->setObjectName(QStringLiteral("mainContent"));
        mainContent->setMinimumSize(QSize(0, 460));
        mainContent->setFrameShape(QFrame::Box);
        calendarPage = new CalendarWidget();
        calendarPage->setObjectName(QStringLiteral("calendarPage"));
        mainContent->addWidget(calendarPage);
        reportPage = new ReportWidget();
        reportPage->setObjectName(QStringLiteral("reportPage"));
        mainContent->addWidget(reportPage);
        searchRunPage = new SearchRunWidget();
        searchRunPage->setObjectName(QStringLiteral("searchRunPage"));
        mainContent->addWidget(searchRunPage);
        racesPage = new RacesWidget();
        racesPage->setObjectName(QStringLiteral("racesPage"));
        mainContent->addWidget(racesPage);

        gridLayout->addWidget(mainContent, 0, 0, 1, 1);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionImport_TCX);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuView->addAction(actionAthlete);
        menuView->addAction(actionShoes);
        menuView->addSeparator();
        menuView->addAction(actionCalendar);
        menuView->addAction(actionReport_Generator);
        menuView->addAction(actionSearch_Run);
        menuView->addAction(actionRaces);
        menuHelp->addAction(actionAbout_Qt);
        menuHelp->addAction(actionAbout_Atleto);
        menuHelp->addSeparator();
        menuTools->addAction(actionRun_Calculator);
        menuTools->addSeparator();
        menuTools->addAction(actionOptions);
        mainToolBar->addAction(actionCalendar);
        mainToolBar->addAction(actionReport_Generator);
        mainToolBar->addAction(actionSearch_Run);
        mainToolBar->addAction(actionRaces);

        retranslateUi(MainWindowClass);

        mainContent->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "Atleto", 0));
        actionAbout_Qt->setText(QApplication::translate("MainWindowClass", "About Qt", 0));
        actionAbout_Atleto->setText(QApplication::translate("MainWindowClass", "About Atleto", 0));
        actionReport_Generator->setText(QApplication::translate("MainWindowClass", "Report Generator", 0));
        actionReport_Generator->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+G", 0));
        actionQuit->setText(QApplication::translate("MainWindowClass", "Quit", 0));
        actionQuit->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+Q", 0));
        actionAthlete->setText(QApplication::translate("MainWindowClass", "Athlete...", 0));
        actionAthlete->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+A", 0));
        actionSearch_Run->setText(QApplication::translate("MainWindowClass", "Search Run", 0));
        actionSearch_Run->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+F", 0));
        actionRun_Calculator->setText(QApplication::translate("MainWindowClass", "Run Calculator", 0));
        actionRun_Calculator->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+P", 0));
        actionShoes->setText(QApplication::translate("MainWindowClass", "Shoes", 0));
        actionShoes->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+S", 0));
        actionCalendar->setText(QApplication::translate("MainWindowClass", "Calendar", 0));
        actionCalendar->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+C", 0));
        actionRaces->setText(QApplication::translate("MainWindowClass", "Races", 0));
        actionRaces->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+R", 0));
        actionPlot->setText(QApplication::translate("MainWindowClass", "plot", 0));
        actionOptions->setText(QApplication::translate("MainWindowClass", "Options...", 0));
        actionImport_TCX->setText(QApplication::translate("MainWindowClass", "Import TCX...", 0));
        actionPlotTest->setText(QApplication::translate("MainWindowClass", "PlotTest", 0));
        mainContent->setStyleSheet(QString());
        reportPage->setStyleSheet(QString());
        menuFile->setTitle(QApplication::translate("MainWindowClass", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindowClass", "Edit", 0));
        menuView->setTitle(QApplication::translate("MainWindowClass", "View", 0));
        menuHelp->setTitle(QApplication::translate("MainWindowClass", "Help", 0));
        menuTools->setTitle(QApplication::translate("MainWindowClass", "Tools", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
