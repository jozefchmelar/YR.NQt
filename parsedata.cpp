#include "parsedata.h"

ParseData::ParseData(QObject *parent) : QObject(parent)
{

}

WeatherData ParseData::getWeatherData(QString url)
{
    d.doDownload(QUrl(url));
    QDomElement doc = d.domdoc->documentElement();

    QDomNode node;
    QDomElement currentElement;
    //location
    node= doc.firstChildElement("location");
    weatherdata.setCityName(node.firstChildElement("name").toElement().text());
    weatherdata.setCountry(node.firstChildElement("country").toElement().text());
    weatherdata.setLatitude(node.firstChildElement("location").toElement().attribute("latitude"));
    weatherdata.setLongitude(node.firstChildElement("location").toElement().attribute("longitude"));

    //META
    node= doc.firstChildElement("meta");

    weatherdata.setLastupdate(convertTime(node.firstChildElement("lastupdate").toElement().text()));
    weatherdata.setNextupdate(convertTime(node.firstChildElement("nextupdate").toElement().text()));


    //Sun
    node= doc.firstChildElement("sun");
    weatherdata.setSunrise(convertTime(node.toElement().attribute("rise")));
    weatherdata.setSunset(convertTime(node.toElement().attribute("set")));

    //forecast /tabular
    node= doc.firstChildElement("forecast");
    node= node.firstChildElement("tabular");

    //time FIRST
    QDomNode firstNodeTime = node.firstChildElement("time");
    QDomNode currentTimeNode= firstNodeTime;
    currentElement = firstNodeTime.toElement();
    QList<ForecastData> list;
    //1// toto by som mal jebnut do slucky.---------------------------------1
    while(!firstNodeTime.isNull()) {
        ForecastData forecastdata;
        currentElement = currentTimeNode.toElement();
        forecastdata.setFrom(convertTime(currentElement.attribute("from")));
        forecastdata.setTo(convertTime(currentElement.attribute("to")));
        forecastdata.setPeriod((currentElement.attribute("period")));
        //Symbol
        currentTimeNode=currentTimeNode.firstChildElement("symbol");
        currentElement = currentTimeNode.toElement();
        forecastdata.setSymbolName(currentElement.attribute("name"));
        forecastdata.setSymbolVar(currentElement.attribute("var"));
        //windDirection
        currentElement = currentElement.nextSiblingElement("windDirection");
        forecastdata.setWindDirectionName(currentElement.attribute("name"));
        //windSpeed
        currentElement = currentElement.nextSiblingElement("windSpeed");

        forecastdata.setWindSpeedName(currentElement.attribute("name"));
        forecastdata.setWindSpeedMps(currentElement.attribute("mps"));
        //temperature
        currentElement = currentElement.nextSiblingElement("temperature");
        forecastdata.setTemperature(currentElement.attribute("value"));
        list.append(forecastdata);
        //qDebug()<<""+forecastdata.toQString();
        currentTimeNode=firstNodeTime.nextSibling();
        firstNodeTime=firstNodeTime.nextSibling();
    }
    weatherdata.setForecast(list);
    return weatherdata;
}

WeatherData ParseData::getWeatherData(QUrl url)
{
    d.doDownload(url);
    QDomElement doc = d.domdoc->documentElement();

    QDomNode node;
    QDomElement currentElement;
    //location
    node= doc.firstChildElement("location");
    weatherdata.setCityName(node.firstChildElement("name").toElement().text());
    weatherdata.setCountry(node.firstChildElement("country").toElement().text());
    weatherdata.setLatitude(node.firstChildElement("location").toElement().attribute("latitude"));
    weatherdata.setLongitude(node.firstChildElement("location").toElement().attribute("longitude"));

    //META
    node= doc.firstChildElement("meta");

    weatherdata.setLastupdate(convertTime(node.firstChildElement("lastupdate").toElement().text()));
    weatherdata.setNextupdate(convertTime(node.firstChildElement("nextupdate").toElement().text()));


    //Sun
    node= doc.firstChildElement("sun");
    weatherdata.setSunrise(convertTime(node.toElement().attribute("rise")));
    weatherdata.setSunset(convertTime(node.toElement().attribute("set")));

    //forecast /tabular
    node= doc.firstChildElement("forecast");
    node= node.firstChildElement("tabular");

    //time FIRST
    QDomNode firstNodeTime = node.firstChildElement("time");
    QDomNode currentTimeNode= firstNodeTime;
    currentElement = firstNodeTime.toElement();
    QList<ForecastData> list;
    //1// toto by som mal jebnut do slucky.---------------------------------1
    while(!firstNodeTime.isNull()) {
        ForecastData forecastdata;
        currentElement = currentTimeNode.toElement();
        forecastdata.setFrom(convertTime(currentElement.attribute("from")));
        forecastdata.setTo(convertTime(currentElement.attribute("to")));
        forecastdata.setPeriod((currentElement.attribute("period")));
        //Symbol
        currentTimeNode=currentTimeNode.firstChildElement("symbol");
        currentElement = currentTimeNode.toElement();
        forecastdata.setSymbolName(currentElement.attribute("name"));
        forecastdata.setSymbolVar(currentElement.attribute("var"));
        //windDirection
        currentElement = currentElement.nextSiblingElement("windDirection");
        forecastdata.setWindDirectionName(currentElement.attribute("name"));
        //windSpeed
        currentElement = currentElement.nextSiblingElement("windSpeed");

        forecastdata.setWindSpeedName(currentElement.attribute("name"));
        forecastdata.setWindSpeedMps(currentElement.attribute("mps"));
        //temperature
        currentElement = currentElement.nextSiblingElement("temperature");
        forecastdata.setTemperature(currentElement.attribute("value"));
        list.append(forecastdata);
        //qDebug()<<""+forecastdata.toQString();
        currentTimeNode=firstNodeTime.nextSibling();
        firstNodeTime=firstNodeTime.nextSibling();
    }
    weatherdata.setForecast(list);
    return weatherdata;
}

QDateTime ParseData::convertTime(QString time)
{
    //"2015-11-18T06:00:00"
    const QString toParse = time.remove('T').remove('-').remove(':');
    QDateTime result = QDateTime::fromString(toParse, "yyyyMMddHHmmss");
    return result;
}

