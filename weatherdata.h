#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <QDateTime>
#include <QList>
#include "forecastdata.h"

class WeatherData
{

public:
    explicit WeatherData();

    QString getCityName() ;
    void setCityName(QString value);

    QString getLongitude() ;
    void setLongitude(QString value);

    QString getLatitude() ;
    void setLatitude(QString value);

    QDateTime getLastupdate() ;
    void setLastupdate(QDateTime value);

    QDateTime getNextupdate() ;
    void setNextupdate(QDateTime value);

    QDateTime getSunrise() ;
    void setSunrise(QDateTime value);

    QDateTime getSunset() ;
    void setSunset(QDateTime value);

    QString toQString();
    double averageTemperature(QDate date) ;

    QList<ForecastData> getForecast()  ;
    void setForecast( QList<ForecastData> value);

    QString getCountry()  ;
    void setCountry(  QString  value);

private:
    QString cityName;
    QString country;
    QString longitude;
    QString latitude;
    QDateTime lastupdate;
    QDateTime nextupdate;
    QDateTime sunrise;
    QDateTime sunset;
    QList<ForecastData> forecast;



};

#endif // WEATHERDATA_H
