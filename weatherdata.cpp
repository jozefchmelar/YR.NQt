#include "weatherdata.h"

WeatherData::WeatherData() {

}

QString WeatherData::getCityName()
{
    return cityName;
}

void WeatherData::setCityName(QString value)
{
    cityName = value;
}

QString WeatherData::getLongitude()
{
    return longitude;
}

void WeatherData::setLongitude( QString value)
{
    longitude = value;
}

QString WeatherData::getLatitude()
{
    return latitude;
}

void WeatherData::setLatitude( QString value)
{
    latitude = value;
}

QDateTime WeatherData::getLastupdate()
{
    return lastupdate;
}

void WeatherData::setLastupdate( QDateTime value)
{
    lastupdate = value;
}

QDateTime WeatherData::getNextupdate()
{
    return nextupdate;
}

void WeatherData::setNextupdate( QDateTime value)
{
    nextupdate = value;
}

QDateTime WeatherData::getSunrise()
{
    return sunrise;
}

void WeatherData::setSunrise( QDateTime value)
{
    sunrise = value;
}

QDateTime WeatherData::getSunset()
{
    return sunset;
}

void WeatherData::setSunset( QDateTime value)
{
    sunset = value;
}


QString WeatherData::toQString()
{
    QString result= "City: " + cityName +"\n";
    result+= "longitude: " + longitude +"\n";
    result+= "latitude: " + latitude +"\n";
    result+= "lastupdate: " + lastupdate.toString("HH:mm") +"\n";
    result+= "nextupdate: " + nextupdate.toString("HH:mm") +"\n";
    result+= "sunrise: " + sunrise.toString("HH:mm") +"\n";
    result+= "sunset: " + sunset.toString("HH:mm") +"\n";
    return result;
}

double WeatherData::averageTemperature(QDate date)
{
    double avg=0;
    double count=1;
    for(int i=0;i<forecast.size();i++){
        if(forecast.at(i).getTo().date()==date){
            avg += forecast.at(i).getTemperature().toDouble();
            count++;
        }
    }
    double result = avg/count;
    return result;
}



QList<ForecastData> WeatherData::getForecast()
{
    return forecast;
}

void WeatherData::setForecast( QList<ForecastData> value)
{
    forecast = value;
}

QString WeatherData::getCountry()
{
    return country;
}

void WeatherData::setCountry( QString value)
{
    country = value;
}



