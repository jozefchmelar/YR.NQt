#ifndef FORECASTDATA_H
#define FORECASTDATA_H

#include <QDateTime>
#include <QList>
#include <QStaticText>

class ForecastData {
public:
    explicit ForecastData();

    QDateTime getFrom() const;
    void setFrom(QDateTime value);

    QDateTime getTo() const;
    void setTo(QDateTime value);

    QString getPeriod();
    void setPeriod(QString value);

    QString getSymbolName();
    void setSymbolName(QString value);

    QString getWindDirectionName();
    void setWindDirectionName(QString value);

    QString getWindSpeedName();
    void setWindSpeedName(QString value);

    QString getWindSpeedMps();
    void setWindSpeedMps(QString value);

    QString getTemperature() const;
    void setTemperature(QString value);

    QString toString()  ;
    QString getToday()  ;


    QString getSymbolVar() const  ;
    void setSymbolVar(  QString value);

private:
    QDateTime from;
    QDateTime to;
    QString period;
    QString symbolName;
    QString symbolVar;
    QString windDirectionName;
    QString windSpeedName;
    QString windSpeedMps;
    QString temperature;



};

#endif // FORECASTDATA_H
