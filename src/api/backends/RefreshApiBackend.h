//
// Created by jvyden on 11/10/23.
//

#ifndef UGCBROWSER_REFRESHAPIBACKEND_H
#define UGCBROWSER_REFRESHAPIBACKEND_H

#include <QString>
#include <QUrl>
#include "../types/ApiLevel.h"
#include "ApiBackend.h"

class RefreshApiBackend : public ApiBackend {
    ~RefreshApiBackend() override = default;
    
    QString GetPrettyName() override;
    QUrl* GetApiBaseUrl() override;
    
    ApiLevel* GetLevelById(const std::string& levelId) override;
};

#endif //UGCBROWSER_REFRESHAPIBACKEND_H
