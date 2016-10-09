// $Id: reportwidget.h 366 2010-06-04 21:16:57Z boffyflow $
// (c) 2009, Parallel Pixels Ltd.

#ifndef REPORTWIDGET_H
#define REPORTWIDGET_H

#include <QtWidgets/QWidget>
#include <QStandardItemModel>

namespace Ui
{
    class ReportWidget;
}

class ReportWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY( ReportWidget)

public:

    explicit    ReportWidget(QWidget *parent = 0);
    virtual     ~ReportWidget();

protected:

    virtual void changeEvent(QEvent *e);

private:

    void                    restoreGraphs();

    Ui::ReportWidget        *m_ui;

private slots:
    void on_tileButton_clicked();
    void on_cascadeButton_clicked();
    void on_addGraphButton_clicked();
    void updateTitles();
};

#endif // REPORTWIDGET_H
