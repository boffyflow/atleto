// (c)2007 Parallel Pixels Ltd. 
// $Id: shoe.h 294 2010-03-05 18:37:10Z  $

#ifndef SHOE_H
#define SHOE_H

#include <QDate>
#include <QList>

class Shoe
{
public:

    Shoe();
    Shoe( const int id);
    ~Shoe();

    static      QList<Shoe>    shoeList();

    void        setName( const QString &name) { mName = name;};
    void        setBrand( const QString &brand) { mBrand = brand;};
    void        setModel( const QString &model) { mModel = model;};
    void        setSize( const QString &size) { mSize = size;};
    void        setNotes( QString notes) { mNotes = notes;};
    void        setUseStart( QDate start) { mUseStart = start;};
    void        setUseEnd( QDate end) { mUseEnd = end;};
    void        setActive( const bool active) { mActive = active;};
    void        setStartMileage( const float startMileage) { mStartMileage = startMileage;};
    void        setMaxMileage( const float maxMileage) { mMaxMileage = maxMileage;};

    int         id() const { return mId;};
    QString     name() const { return mName;};
    QString     brand() const { return mBrand;};
    QString     model() const { return mModel;};
    QString     size() const { return mSize;};
    QString     notes() const { return mNotes;};
    QDate       useStart() const { return mUseStart;};
    QDate       useEnd() const { return mUseEnd;};
    bool        active() const { return mActive;};
    float       startMileage() const { return mStartMileage;};
    float       maxMileage() const { return mMaxMileage;};

    double      mileage();

    void        restore();
    void        restore( const int id);
    int         save( const int shoe_id = -1);
    void        remove();

private:

    int         mId;
    QString     mName;
    QString     mBrand;
    QString     mModel;
    QString     mSize;
    QString	mNotes;
    QDate       mUseStart;
    QDate       mUseEnd;
    bool        mActive;
    float       mStartMileage;
    float       mMaxMileage;

    void        initialize();
};

#endif
