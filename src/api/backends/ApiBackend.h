#ifndef UGCBROWSER_APIBACKEND_H
#define UGCBROWSER_APIBACKEND_H

#include <QString>
#include <iostream>
#include <QUrl>
#include "../types/ApiLevel.h"

struct ApiBackend {
public:
    virtual ~ApiBackend() = default;
    
    virtual QString GetPrettyName() = 0;
    virtual QUrl* GetApiBaseUrl() = 0;
    virtual QUrl* GetApiBaseUrl(QString endpoint) = 0;

    virtual ApiLevel GetLevelById(const std::string& levelId) = 0;
    virtual void GetRecentLevels(uint skip, std::vector<ApiLevel>* levels) = 0;
};

#endif //UGCBROWSER_APIBACKEND_H
