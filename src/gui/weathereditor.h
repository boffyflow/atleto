// $Id: weathereditor.h 294 2010-03-05 18:37:10Z  $
// (c) 2009, Parallel Pixels Ltd.

#ifndef WEATHEREDITOR_H
#define WEATHEREDITOR_H

#include <QDialog>
#include <QDate>

#include "src/data/weather.h"

namespace Ui
{
    class WeatherEditor;
}

class WeatherEditor : public QDialog
{
    Q_OBJECT

public:

    WeatherEditor( const QDate &day, const int id = -1, QWidget *parent = 0);
    ~WeatherEditor();

protected:

    void changeEvent(QEvent *e);

private:

    Ui::WeatherEditor   *ui;
    Weather             mWeather;

private slots:

    void on_deleteButton_clicked();
    void on_buttonBox_accepted();
};

#endif // WEATHEREDITOR_H
