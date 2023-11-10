#ifndef UGCBROWSER_APIBACKEND_H
#define UGCBROWSER_APIBACKEND_H

#include <QString>
#include <iostream>
#include <QUrl>

struct ApiBackend {
    virtual QString GetPrettyName() = 0;
    virtual QUrl* GetApiBaseUrl() = 0;
    virtual ~ApiBackend() = default;
};

#endif //UGCBROWSER_APIBACKEND_H
