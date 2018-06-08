// $Id: editorwidget.h 340 2010-03-22 21:24:50Z boffyflow $
// (c) 2009, Parallel Pixels Ltd.

#ifndef EDITORWIDGET_H
#define EDITORWIDGET_H

#include <QtWidgets/QWidget>
#include <QDate>

namespace Ui
{
    class EditorWidget;
}

class EditorWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(EditorWidget)

public:

    explicit EditorWidget(QWidget *parent = 0);
    virtual ~EditorWidget();

    QDate   currentDate() const { return mCurDate;};

public slots:

    void dayChanged();

protected:

    virtual void changeEvent(QEvent *e);

private:

    void populateData();
    void displayBMI( const double weight);

    Ui::EditorWidget    *m_ui;
    QDate               mCurDate;

private slots:

    void on_todayButton_clicked();
    void on_nextButton_clicked();
    void on_prevButton_clicked();
    void on_dateEdit_dateChanged(QDate date);
    void on_pushButton_clicked();
    void on_editWeather_clicked();
    void on_editPhysical_clicked();
    void on_addButton_clicked();

    void setButtons();
    void editRun( int row = -1, int column = -1);
    void deleteRun();
};

#endif // EDITORWIDGET_H
