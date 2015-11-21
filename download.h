#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QObject>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDomDocument>
#include <QDebug>
class download : public QObject
{
    Q_OBJECT
public:
    explicit download(QObject *parent = 0);
    void doDownload(QUrl urlAdress);
    QDomDocument doDownDoc(QUrl urlAdress);
    QDomDocument* domdoc;
private:
    QNetworkRequest *request;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
private slots:
    void error(QNetworkReply::NetworkError err);
    void finished();
};

#endif // DOWNLOAD_H
