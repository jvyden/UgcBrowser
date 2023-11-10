//
// Created by jvyden on 11/10/23.
//

#include <QtWidgets>
#include <QtNetwork>
#include "ApiClient.h"

QJsonObject* ApiClient::getJson(QUrl *url) {
    QNetworkRequest request(*url);
    QNetworkReply* reply = this->networkManager->get(request);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    reply->deleteLater();
    
    QByteArray responseData = reply->readAll();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData);
    QJsonObject jsonObject = jsonDocument.object();
    
    bool success = jsonObject["success"].toBool(false);
    if(!success) {
        return nullptr;
    }
    
    QJsonObject dataObject = jsonObject["data"].toObject();
    return new QJsonObject(dataObject);
}
