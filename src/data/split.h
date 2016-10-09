// $Id: split.h 369 2010-09-25 00:02:33Z boffyflow $
// (c) 2006, Parallel Pixels Ltd.

#ifndef SPLIT_H
#define SPLIT_H

#include <QString>
#include <QTime>

class Split
{
public:

    static void removeRunSplits( const int run_id);
    static float sum( const QDate &startDate, const QDate &endDate, const QString& property);
    static int  maxHeartRate( const QDate &startDate, const QDate &endDate);
    static int  aveHeartRate( const QDate &startDate, const QDate &endDate);

    Split();
    Split( const float dist, const float time, const int hr, const QString& comment);
    ~Split();

    Split( const Split& split);

    bool     operator ==( const Split& split);
	
    void     setDistance( const float dist) { mDistance = dist;};
    void     setTime( const float &time) { mTime = time;};
    void     setHeartRate( const int hr) { mHeartrate = hr;};
    void     setComment( const QString &comment) { mComment = comment;};

    float		distance() const  { return mDistance;};
    float		time() const  { return mTime;};
    int			heartrate() const  { return mHeartrate;};
    QString		comment() const  { return mComment;};

    int         save( const int run_id);

private:
   
    float		mDistance;
    float		mTime;
    int			mHeartrate;
    QString		mComment;
};

#endif
