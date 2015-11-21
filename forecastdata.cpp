#include "forecastdata.h"

ForecastData::ForecastData()
{

}

QDateTime ForecastData::getFrom() const
{
    return from;
}

void ForecastData::setFrom(  QDateTime value)
{
    from = value;
}

QDateTime ForecastData::getTo() const
{
    return to;
}

void ForecastData::setTo(  QDateTime value)
{
    to = value;
}

QString ForecastData::getPeriod()
{
    return period;
}

void ForecastData::setPeriod(  QString value)
{
    period = value;
}

QString ForecastData::getSymbolName()
{
    return symbolName;
}

void ForecastData::setSymbolName(  QString value)
{
    symbolName = value;
}

QString ForecastData::getWindDirectionName()
{
    return windDirectionName;
}

void ForecastData::setWindDirectionName(  QString value)
{
    windDirectionName = value;
}

QString ForecastData::getWindSpeedName()
{
    return windSpeedName;
}

void ForecastData::setWindSpeedName(  QString value)
{
    windSpeedName = value;
}

QString ForecastData::getWindSpeedMps()
{
    return windSpeedMps;
}

void ForecastData::setWindSpeedMps(  QString value)
{
    windSpeedMps = value;
}

QString ForecastData::getTemperature() const
{
    return temperature;
}

void ForecastData::setTemperature(  QString value)
{
    temperature = value;
}

QString ForecastData::toString()
{
    QString result = "From: "+from.toString("ddd.HH:mm") +"\n";
    result += "to:"+to.toString("ddd.HH:mm") +"\n";
    result += "period: "+ period +"\n";
    result += "symbolName: "+ symbolName +"\n";
    result += "symbolVar: "+ symbolVar +"\n";
    result += "windDirectionName: "+ windDirectionName  +"\n";
    result += "windSpeedName: "+ windSpeedName +"\n";
    result += "windSpeedMps: "+ windSpeedMps +"\n";
    result += "temperature: "+temperature  +"°C\n";
    result += "------------------";
    return result;
}

QString ForecastData::getToday()
{
    QString result;
    return result;
}

QString ForecastData::getSymbolVar() const
{
    return symbolVar;
}

void ForecastData::setSymbolVar(  QString  value)
{
    symbolVar = value;
}


