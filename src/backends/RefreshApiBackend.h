#ifndef UGCBROWSER_REFRESHAPIBACKEND_H
#define UGCBROWSER_REFRESHAPIBACKEND_H

#include "ApiBackend.h"

class RefreshApiBackend : ApiBackend {
    ~RefreshApiBackend() override = default;

public:
    QString GetBackendName() override {
        return "Refresh";
    }
};


#endif //UGCBROWSER_REFRESHAPIBACKEND_H
