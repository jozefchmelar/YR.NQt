#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "download.h"
#include "parsedata.h"
#include "weatherdata.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    //void on_listView_itemClicked(QListWidgetItem *item);

//    void on_calendarWidget_clicked(const QDate &date);

    void on_checkBox_clicked();

    void on_UrlAdress_editingFinished();

    void on_next_clicked();

    void on_previous_clicked();

private:
    Ui::MainWindow *ui;
    ParseData data;
    int forecastPlus;
    WeatherData weather;
    void displayToday(int plus);
    void displayPlusOne();
    ForecastData now;
    QImage img;
    QString symbolToDisplay;
    void displaySymbol(QString symbolVar,QLabel *label,bool big);
    void forecastToday(int numberOfHours);
    QList<ForecastData> currentForecast;
    QList<QString> listOfDays();
    QList<QString> days;
    void initComponents(ForecastData now,QLabel *TodaySymbol,QLabel *temp,QLabel *symbolName,QLabel *CityCountry, QLabel *Sunrise, QLabel *Sunset,QLabel *FromTo);
};

#endif // MAINWINDOW_H
