//
// Created by jvyden on 11/10/23.
//

#ifndef UGCBROWSER_SOUNDSHAPESAPIBACKEND_H
#define UGCBROWSER_SOUNDSHAPESAPIBACKEND_H


#include "ApiBackend.h"
#include "../ApiClient.h"

class SoundShapesApiBackend : public ApiBackend {
private:
    ApiClient* apiClient;

public:
    explicit SoundShapesApiBackend(QObject* parent) : apiClient(new ApiClient(parent)) {}
    ~SoundShapesApiBackend() override = default;

    QString GetPrettyName() override;
    QUrl* GetApiBaseUrl() override;
    QUrl* GetApiBaseUrl(QString endpoint) override;

    ApiLevel GetLevelById(const std::string& levelId) override;
};


#endif //UGCBROWSER_SOUNDSHAPESAPIBACKEND_H
