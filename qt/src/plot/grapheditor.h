// (c) 2010 Parallel Pixels Ltd.
// $Id: grapheditor.h 372 2013-03-05 22:04:13Z boffyflow $

#ifndef GRAPHEDITOR_H
#define GRAPHEDITOR_H

#include <QDialog>
#include <QMap>
#include <QModelIndex>

class Graph;
class QListWidgetItem;

namespace Ui
{
    class GraphEditor;
}

class GraphEditor : public QDialog
{
    Q_OBJECT
public:

    GraphEditor( Graph *graph, QWidget *parent = 0);
    ~GraphEditor();

    virtual void accept();

protected:
    void changeEvent(QEvent *e);

private:

    Graph               *mGraph;
    Ui::GraphEditor     *ui;

private slots:


};

#endif // GRAPHEDITOR_H
