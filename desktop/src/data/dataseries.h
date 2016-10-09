// $Id: dataseries.h 369 2010-09-25 00:02:33Z boffyflow $
// (c) 2010 Parallel Pixels Ltd.

#ifndef DATASERIES_H
#define DATASERIES_H

#include <QMap>
#include <QColor>

enum
{
    SERIES_DISTANCE = 0,
    SERIES_WEIGHT
};

class DataXY
{
public:

    DataXY();
    DataXY( float x, float y);

    float   x() const { return mX;};
    float   y() const { return mY;};

    void    setX( const float x) { mX = x;};
    void    setY( const float y) { mY = y;};

private:

    float       mX;
    float       mY;
};

class DataSeries
{
public:

    DataSeries();

    void        setContent( const int contentType);

private:

    void                    initialize();


    int                     mContent;
    QMap<DataXY,QString>    mData;

    int                     mStyle;
    float                   mLineWidth;
    QColor                  mColor;
    int                     mSymbol;
};

#endif // DATASERIES_H
