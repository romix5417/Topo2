#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>

#include <QDebug>

int httpRequest(QString url, QJsonObject obj)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager();

    //设置发送的数据
    //obj.insert("route", QString("10.0.0.102"));
    //obj.insert("gw", QString("10.0.0.101"));

    QNetworkRequest req;
    QSslConfiguration config;

    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    config.setProtocol(QSsl::SslV2);
    req.setSslConfiguration(config);

    qDebug()<<"url:"<<url<<endl;
    req.setUrl(QUrl(url));

    req.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json;charset=UTF-8"));
    //req.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/x-www-form-urlencoded"));
    manager->post(req, QJsonDocument(obj).toJson());


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
