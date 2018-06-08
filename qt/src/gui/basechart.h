// $Id: basechart.h 214 2009-05-28 17:44:45Z robert $
// (c) 2009, Parallel Pixels Ltd.

#ifndef BASECHART_H
#define BASECHART_H

#include <QObject>
#include <QGraphicsRectItem>

class BaseChart : public QObject
{
public:

    BaseChart();
    virtual ~BaseChart();

    QGraphicsItem       *graphicsItem() { return (QGraphicsItem *) mRectItem;};
    void addValue( const QString &label, const double value);

    virtual void draw() {};

protected:

    QMap< QString, double>      mData;

private:

    QGraphicsRectItem           *mRectItem;
};

#endif // BASECHART_H
