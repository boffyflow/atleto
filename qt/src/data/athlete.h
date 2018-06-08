#ifndef ATHLETE_H
#define ATHLETE_H

#include <QString>
#include <QDate>

class Athlete
{
public:
    static Athlete* getInstance();
    static void newAthlete();
    static void setAthleteById(int id);
    static void setAthleteByName(QString name);
    static void saveAthlete();
    static void insertNewAthlete();

    int getId() { return mId; }
    void setId(int val) { mId = val; }
    QString getName() { return mName; }
    void setName(QString val) { mName = val; }
    QDate getDoB() { return mDoB; }
    void setDoB(QDate val) { mDoB = val; }
    double getHeight() { return mHeight; }
    void setHeight(double val) { mHeight = val; }
    bool isMale() { return mGender; }
    void setGender(bool val) { mGender = val; }

private:
    static Athlete* instance;
    Athlete();

    int mId;
    QString mName;
    double mHeight;
    QDate mDoB;
    bool mGender;
};

#endif // ATHLETE_H
