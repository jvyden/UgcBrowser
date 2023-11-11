//
// Created by jvyden on 11/10/23.
//

#ifndef UGCBROWSER_APICLIENT_H
#define UGCBROWSER_APICLIENT_H


#include <QNetworkAccessManager>

class ApiClient {
private:
    QNetworkAccessManager* networkManager;

public:
    explicit ApiClient(QObject* parent) : networkManager(new QNetworkAccessManager(parent))
    {}
    
    QJsonObject getJson(QUrl* url);
};


#endif //UGCBROWSER_APICLIENT_H
