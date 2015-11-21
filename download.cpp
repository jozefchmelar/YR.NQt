#include "download.h"
#include <QCoreApplication>

download::download(QObject *parent) : QObject(parent)
{
    domdoc = new QDomDocument();
    manager = new QNetworkAccessManager(this);
}

void download:: doDownload(QUrl urlAdress)
{
    QNetworkRequest request;
    request.setUrl(urlAdress);
    reply = manager->get(request);
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),
            this, SLOT(error(QNetworkReply::NetworkError)));
    connect(reply, SIGNAL(finished()),
            this, SLOT(finished()));
    QTime dieTime= QTime::currentTime().addMSecs(200);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

QDomDocument download::doDownDoc(QUrl urlAdress)
{
    QNetworkRequest request;
    request.setUrl(urlAdress);
    reply = manager->get(request);
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),
            this, SLOT(error(QNetworkReply::NetworkError)));
    connect(reply, SIGNAL(finished()),
            this, SLOT(finished()));
    QDomDocument d;
    d.setContent(reply->readAll());
    return d;
}

void download::error(QNetworkReply::NetworkError err)
{
    reply->deleteLater();
}


void download::finished()
{
    domdoc->setContent(reply->readAll());
    reply->deleteLater();
}
