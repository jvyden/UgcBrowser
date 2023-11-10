#ifndef UGCBROWSER_APIBACKEND_H
#define UGCBROWSER_APIBACKEND_H


#include <QString>

struct ApiBackend {
    virtual QString GetBackendName() = 0;
    virtual ~ApiBackend() = default;
};

#endif //UGCBROWSER_APIBACKEND_H
