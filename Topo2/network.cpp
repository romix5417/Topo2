#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>

int httpRequest()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager;

    QJsonObject obj;

    obj.insert("route", QString("10.0.0.102"));
    obj.insert("gw", QString("10.0.0.101"));

    QNetworkRequest req;

    req.setUrl(QUrl("http://localhost:5000/hello"));

    manager->post(req, QJsonDocument(obj).toJson());

    //QByteArray postArray;

    //postArray.append("/hello");

    //manager->post(req, postArray);

    QObject::connect(manager, &QNetworkAccessManager::finished, [](QNetworkReply *reply){
        if(reply->error() != QNetworkReply::NoError){
            qDebug()<<"Error:"<<reply->errorString();
            return;
        }

        QByteArray buf = reply->readAll();
        qDebug()<<"OK:"<<buf;
    });

    return 0;
}
