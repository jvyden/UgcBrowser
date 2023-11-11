//
// Created by jvyden on 11/10/23.
//

#include "SoundShapesApiBackend.h"

QString SoundShapesApiBackend::GetPrettyName() {
    return QStringLiteral("Sound Shapes");
}

QUrl *SoundShapesApiBackend::GetApiBaseUrl() {
    return new QUrl(QStringLiteral("https://sound.ture.fish/api/v1/"));
}

QUrl *SoundShapesApiBackend::GetApiBaseUrl(QString endpoint) {
    return new QUrl(QStringLiteral("https://sound.ture.fish/api/v1/").append(endpoint));
}

ApiLevel SoundShapesApiBackend::GetLevelById(const std::string &levelId) {
    QUrl* url = this->GetApiBaseUrl(QStringLiteral("levels/id/").append(levelId));
    QJsonObject data = *this->apiClient->getJson(url);

    return ApiLevel {
        .levelId = data["id"].toString(),
        .title = data["name"].toString(),
        .description = "",
        .publishDate = 0,
    };
}


