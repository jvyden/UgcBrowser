#ifndef UGCBROWSER_REFRESHAPIBACKEND_H
#define UGCBROWSER_REFRESHAPIBACKEND_H

#include "ApiBackend.h"

class RefreshApiBackend : public ApiBackend {
    ~RefreshApiBackend() override = default;

public:
    QString GetPrettyName() override {
        return "Refresh";
    }
    
    QUrl* GetApiBaseUrl() override {
        return new QUrl("https://lbp.littlebigrefresh.com/api/v3/");
    }
};


#endif //UGCBROWSER_REFRESHAPIBACKEND_H
