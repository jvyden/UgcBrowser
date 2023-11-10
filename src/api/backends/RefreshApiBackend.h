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
    ~RefreshApiBackend() override = default;
    
    QString GetPrettyName() override;
    QUrl* GetApiBaseUrl() override;
    QUrl* GetApiBaseUrl(QString endpoint) override;
    
    ApiLevel* GetLevelById(const std::string& levelId) override;

private:
    ApiClient* apiClient;
    
public:
    explicit RefreshApiBackend(QObject* parent) : apiClient(new ApiClient(parent))
    {}
};

#endif //UGCBROWSER_REFRESHAPIBACKEND_H
