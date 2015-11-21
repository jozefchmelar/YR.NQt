#ifndef GOOGLEAPI_H
#define GOOGLEAPI_H

#include <QObject>
#include "download.h"
class GoogleAPI : public QObject
{
    Q_OBJECT
public:
    explicit GoogleAPI(QObject *parent = 0);
    QString getRef(QString lat,QString longt);

private:
    download d;



signals:

public slots:
};

#endif // GOOGLEAPI_H
