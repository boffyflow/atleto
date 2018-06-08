// (c) 2009 Parallel Pixels Ltd.
// $Id: mainwindow.h 372 2013-03-05 22:04:13Z boffyflow $

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QMap>

namespace Ui
{
    class MainWindowClass;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    static MainWindow* getInstance() { return mInstance; }

    QMap<QString,QString>    templateMap() { return mGraphTemplates;}

public slots:

    void updateStatus();

private:
    void writeSettings();
    void readSettings();
    void openConnection();
    void closeConnection();
    void readGraphTemplates();

    Ui::MainWindowClass     *ui;
    QString                 mDBName;
    static MainWindow       *mInstance;
    QMap<QString,QString>   mGraphTemplates;

private slots:

    void on_actionPlotTest_triggered();
    void on_actionImport_TCX_triggered();
    void on_actionOptions_triggered();
    void on_actionAbout_Atleto_triggered();
    void on_actionRaces_triggered( bool);
    void on_actionCalendar_triggered( bool);
    void on_actionShoes_triggered();
    void on_actionRun_Calculator_triggered();
    void on_actionSearch_Run_triggered( bool);
    void on_actionAthlete_triggered();
    void on_actionReport_Generator_triggered( bool);
    void on_actionQuit_triggered();
    void on_actionAbout_Qt_triggered();
};

#endif // MAINWINDOW_H
