#ifndef PARSEDATA_H
#define PARSEDATA_H

#include<QDomDocument>
#include "download.h"
#include "forecastdata.h"
#include "weatherdata.h"
class ParseData : public QObject
{
    Q_OBJECT
public:
    explicit ParseData(QObject *parent = 0);
    WeatherData getWeatherData(QString url);
    WeatherData getWeatherData(QUrl url);


private:
    download d;
    WeatherData weatherdata;

    QDateTime convertTime(QString time);

signals:


public slots:
};

#endif // PARSEDATA_H
