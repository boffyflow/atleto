// $Id: plot.h 370 2010-12-14 23:23:50Z boffyflow $
// (c) 2010 Parallel Pixels Ltd.

#ifndef PLOT_H
#define PLOT_H

#include <QWidget>

class   PlotGraph;
class   QGraphicsScene;
class   QGraphicsRectItem;

const float PI = 3.14159265358979323846f;

const   int     PLOT_LEFT_MARGIN = 15;
const   int     PLOT_RIGHT_MARGIN = 15;
const   int     PLOT_TOP_MARGIN = 15;
const   int     PLOT_BOTTOM_MARGIN = 15;
const   int     PLOT_TIC_LENGTH = 5;

namespace Ui
{
    class Plot;
}

class Plot : public QWidget
{
    Q_OBJECT

public:

    explicit Plot( QWidget *parent = 0);
    ~Plot();

    void resizeEvent( QResizeEvent *event);

    void setTitle( const QString &title);
    void addGraph( PlotGraph *graph);

    void draw();
    void clear();

private:

    void drawHistogram( PlotGraph *graph, const QRectF &graphRect);

    QGraphicsRectItem       *drawLeftRect( const qreal width, const qreal height);
    QGraphicsRectItem       *drawRightRect( const qreal width, const qreal height);
    QGraphicsRectItem       *drawCenterRect( const qreal width, const qreal height);
    QGraphicsRectItem       *drawBottomRect( const qreal width, const qreal height);

    qreal                   computeLeftWidth();
    qreal                   computeRightWidth();
    qreal                   computeBottomHeight();
    qreal                   computeXStep( const int index);
    qreal                   computeYStep( const int index);
    qreal                   computeStep( const qreal delta, const qreal base);

    Ui::Plot            *ui;
    QGraphicsScene      *mScene;
    QList<PlotGraph *>  mGraphs;
    qreal               mRotationAngleXAxis;
    bool                mHorizontalGridLines;
};

#endif // PLOT_H
