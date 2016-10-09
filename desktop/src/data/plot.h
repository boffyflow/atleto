// $Id: plot.h 351 2010-03-27 22:42:25Z boffyflow $
// (c) 2010, Parallel Pixels Ltd.

#ifndef PLOT_H
#define PLOT_H

#include <QString>
#include <QMap>

// plot types
enum
{
    PLOT_GRAPH = 0,
    PLOT_TITLE,
    PLOT_SUMMARY
};

// plot y data
enum
{
    PLOT_TYPE_NONE = 0,
    PLOT_TYPE_DISTANCE,
    PLOT_TYPE_TIME,
    PLOT_TYPE_PACE,
    PLOT_TYPE_WEIGHT,
    PLOT_TYPE_BMI,
    PLOT_TYPE_SHOES
};

// plot aggregation
enum
{
    PLOT_AG_DAILY = 0,
    PLOT_AG_WEEKLY,
    PLOT_AG_MONTHLY,
    PLOT_AG_YEARLY
};

class Plot
{
public:

    static      QMap<int,QString>   yMap();
    static      QList<Plot>         plotList();

    Plot();
    Plot( const int id);
    ~Plot();

    int         id() const { return mId;};
    QString     name() const { return mName;};
    int         plotType() const { return mType;};
    int         y1Data() const { return mY1;};
    int         y2Data() const { return mY2;};
    int         aggregation() const { return mAggregation;};

    void        setName( const QString &name) { mName = name;};
    void        setPlotType( const int &type) { mType = type;};
    void        setY1Data( const int &y1) { mY1 = y1;};
    void        setY2Data( const int &y2) { mY2 = y2;};
    void        setAggregation( const int &aggregation) { mAggregation = aggregation;};

    void        restore();
    void        restore( const int id);
    int         save();
    void        remove();

private:

    void        initialize();

    int             mId;
    QString         mName;
    int             mType;
    int             mY1;
    int             mY2;
    int             mAggregation;
};

#endif // PLOT_H
