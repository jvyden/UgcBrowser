//
// Created by jvyden on 11/10/23.
//

#ifndef UGCBROWSER_REFRESHAPIBACKEND_H
#define UGCBROWSER_REFRESHAPIBACKEND_H

#include <QString>
#include <QUrl>
#include <QNetworkAccessManager>
#include "../types/ApiLevel.h"
#include "ApiBackend.h"
#include "../ApiClient.h"

class RefreshApiBackend : public ApiBackend {
private:
    ApiClient* apiClient;
    
    QJsonObject* getJson(QUrl* url);
    QJsonArray* getJsonList(QUrl* url);
    
public:
    explicit RefreshApiBackend(QObject* parent) : apiClient(new ApiClient(parent)) {}
    ~RefreshApiBackend() override = default;
    
    QString GetPrettyName() override;
    QUrl* GetApiBaseUrl() override;
    QUrl* GetApiBaseUrl(QString endpoint) override;

    ApiLevel GetLevelById(const std::string& levelId) override;
    void GetRecentLevels(uint skip, std::vector<ApiLevel>* levels) override;
};

ApiLevel levelFromRefreshJson(QJsonObject data);

#endif //UGCBROWSER_REFRESHAPIBACKEND_H
