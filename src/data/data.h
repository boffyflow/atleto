// $Id: data.h 372 2013-03-05 22:04:13Z boffyflow $
// (c) 2006, Parallel Pixels Ltd.

#ifndef ATLETODATA_H
#define ATLETODATA_H

#include <QDate>

static const int     DAY_CREATED = 0;
static const int	 DAY_EXISTED = 1;

namespace atleto
{
    class Data : public QObject
    {
    public:

        Data();
        ~Data();

        int	createDay( const QDate &day);

        void setActiveAthlete( const int id) { athleteID = id;}
        int activeAthlete() { return athleteID;}
        void athleteList( QStringList &athleteList, QStringList &idList);

        void athlete( QString &name, QDate &dob, double &height, bool &male);

        int num( const QString &type);
        int dayExists( const QDate& day);

        bool dayData( const int day_id, QString &notes);
        bool weatherData( const int day_id, int &sky, float &temperature, QString &comment);
        bool physicalData( const int day_id, float &weight, int &bodyfat, int &restinghr, int &rating);

        bool workoutList( const int day_id, const QString& wtype, QList<int> &ids);
        bool runData( const int id, QString& location, float& distance, float &t);
        bool cycleData( const int id);

        int insertNotes( const QDate& day, const QString &notes);
        int insertWeatherData( const QDate &day, const int sky, const float temperature, const QString &comment);
        int insertPhysicalData( const QDate &day, const int rating, const float weight, const int bodyfat, const int hr);

        void list( const QString &, QStringList &, QList<int> &, const QString& condition = "", const bool value = false);
        QString value( const QString &table, const int id) const;
        int exists( const QString &table, const QString &name) const;
        int create( const QString &table, const QString &name) const;

        QDate   firstDay( const QStringList &tables) const;
        QDate   lastDay( const QStringList &tables) const;

        void runTypes( QStringList &runTypes);

    private:

        static int  athleteID;
    };
} // namespace

#endif // DATA_H

