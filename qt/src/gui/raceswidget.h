// (c) 2009 Parallel Pixels Ltd.
// $Id: raceswidget.h 368 2010-06-12 22:08:44Z boffyflow $

#ifndef RACESWIDGET_H
#define RACESWIDGET_H

#include <QWidget>

class QTableWidgetItem;

namespace Ui
{
    class RacesWidget;
}

class RacesWidget : public QWidget
{
    Q_OBJECT

public:

    RacesWidget(QWidget *parent = 0);
    ~RacesWidget();

public slots:

    void updateYears();
    void rebuildTable();

protected:

    void changeEvent(QEvent *e);

private:

    Ui::RacesWidget *ui;

private slots:

    void on_racesTable_itemDoubleClicked( QTableWidgetItem* item);
    void on_gunTimeCheckBox_toggled(bool checked);
    void on_pbCheckBox_toggled(bool checked);
    void on_yearCombo_activated(QString );
    void on_distanceCombo_activated(QString );
};

#endif // RACESWIDGET_H
