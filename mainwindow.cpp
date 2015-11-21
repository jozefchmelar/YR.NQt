#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QImage>
#include<QPicture>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString url="http://www.yr.no/place/Australia/New_South_Wales/Sydney/forecast.xml";
    weather=data.getWeatherData(QUrl(url));
    displayToday(1);
    forecastPlus=1;
    ui->previous->setDisabled(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::displayToday(int plus)
{
    currentForecast = weather.getForecast();
    now= currentForecast.at(0);
    initComponents(now,ui->TodaySymbol,ui->labelTemperature,ui->labelSymbolName,ui->labelCityCountry,ui->labelSunrise,ui->labelSunSet,ui->labelFromTo);
    const int symbolForecastSize=5;
    QLabel *symbolForecast[symbolForecastSize] ={ ui->PlusHourSymb_1,ui->PlusHourSymb_2,ui->PlusHourSymb_3,ui->PlusHourSymb_4,ui->PlusHourSymb_5};
    QLabel *textForecast[symbolForecastSize] = {ui->PlusHour_1,ui->PlusHour_2,ui->PlusHour_3,ui->PlusHour_4,ui->PlusHour_5};
    for(int i=0;i<symbolForecastSize;i++ ){
        int position = i+plus;
        QString from = currentForecast.at(position).getFrom().toString("HH:mm"); //+1 because at 0 is current weather
        QString to = currentForecast.at(position).getTo().toString("HH:mm");
        QString symbolName = currentForecast.at(position).getSymbolVar();
        QString nameOfDayFrom = currentForecast.at(position).getFrom().toString("dddd");
        QString nameOfDayTo = currentForecast.at(position).getTo().toString("dddd");
        QString nameOfDay =nameOfDayFrom;
        if(nameOfDayFrom!=nameOfDayTo) nameOfDay=nameOfDayFrom+"/"+nameOfDayTo;
        QString temp = currentForecast.at(position).getTemperature();
        textForecast[i]->setText(nameOfDay+"\n"+from+"-"+to+"\n"+temp+"°C");
        textForecast[i]->setAlignment(Qt::AlignCenter);
        textForecast[i]->setAlignment(Qt::AlignHCenter);
        symbolForecast[i]->setAlignment(Qt::AlignCenter);
        symbolForecast[i]->setAlignment(Qt::AlignHCenter);
        displaySymbol(symbolName,symbolForecast[i],false);
    }
}

void MainWindow::initComponents(ForecastData now,QLabel *TodaySymbol, QLabel *temp, QLabel *symbolName,
                                QLabel *CityCountry, QLabel *Sunrise, QLabel *Sunset, QLabel *FromTo)
{
    temp->setText(now.getTemperature()+"°C");
    symbolName->setText(now.getSymbolName());
    CityCountry->setText(weather.getCityName()+", "+weather.getCountry());
    Sunrise->setText("sunset\t"+weather.getSunset().toString("HH:mm"));
    Sunset->setText("sunrise\t"+weather.getSunrise().toString("HH:mm"));
    FromTo->setText("From : "+now.getFrom().toString("HH:mm")+" to :" +now.getTo().toString("HH:mm"));
    displaySymbol(now.getSymbolVar(),TodaySymbol,true);
}

void MainWindow::displaySymbol(QString symbolVar,QLabel *label, bool big)
{
    if(big){
        label->setMinimumHeight(200);
        label->setMinimumWidth(200);
        symbolToDisplay = "://b200/";
    }
    else{
        label->setMinimumHeight(100);
        label->setMinimumWidth(100);
        symbolToDisplay = ":/b100/";
    }
    symbolToDisplay+=symbolVar+".png";
    img.load(symbolToDisplay);
    label->setPixmap(QPixmap::fromImage(img));
    forecastToday(10);
}

void MainWindow::forecastToday(int numberOfHours)
{
    //addSecs() returns a new QTime object that has been adjusted. It doesn't affect the 'this' object.
    QDateTime future= currentForecast.at(0).getFrom().addSecs(numberOfHours*60*60);
    for(int i=0;i<currentForecast.size();i++){
        ForecastData current = currentForecast.at(i);
    }
}

QList<QString> MainWindow::listOfDays()
{
    // i know i know I could do this much better.
    QString day="";
    QList<QString> list;
    for(int i=0;i<currentForecast.size();i++){
        QString currentDay=currentForecast.at(i).getFrom().toString("dddd");
        if(day!=currentDay){
            day=currentDay;
            list.append(currentDay);
        }
    }
    return list;
}

void MainWindow::on_checkBox_clicked()
{
    displaySymbol(now.getSymbolVar(),ui->TodaySymbol,ui->checkBox->isChecked());
}

void MainWindow::on_UrlAdress_editingFinished()
{
    QString url = ui->UrlAdress->text();
    if(url.contains("yr.no") && !url.contains("forecast.xml")){

        try{
            QString adress= ui->UrlAdress->text()+"forecast.xml";
            weather=data.getWeatherData(QUrl(adress));
            ui->tabWidget->setCurrentIndex(0);
            displayToday(1);
        }
        catch(int e){
            ui->UrlAdress->setText("Please enter valid url from YR.NO ");
        }
    }else{
        ui->UrlAdress->setText("Please enter url from YR.NO ");
    }
}

void MainWindow::on_next_clicked()
{
    if(currentForecast.size()>forecastPlus+5){
        displayToday(++forecastPlus);
        ui->previous->setDisabled(false);
    }else{
        ui->next->setDisabled(true);
        ui->previous->setDisabled(false);
    }
}

void MainWindow::on_previous_clicked()
{
    if(forecastPlus==1){
        ui->previous->setDisabled(true);
    }else if(forecastPlus>1){
        displayToday(--forecastPlus);

    }
    //  ui->next->setDisabled(true);
}


