//
// Created by jvyden on 11/10/23.
//

#include "SoundShapesApiBackend.h"
#include <QtNetwork>

QJsonObject* SoundShapesApiBackend::getJson(QUrl *url) {
    QJsonObject jsonObject = this->apiClient->getJson(url);

    bool success = jsonObject["success"].toBool(false);
    if(!success) {
        return nullptr;
    }

    QJsonObject dataObject = jsonObject["data"].toObject();
    return new QJsonObject(dataObject);
}

QJsonArray* SoundShapesApiBackend::getJsonList(QUrl *url) {
    std::cout << "URL: " << url->toString().toStdString() << std::endl;
    QJsonObject jsonObject = this->apiClient->getJson(url);

    bool success = jsonObject["success"].toBool(false);
    if(!success) {
        std::cout << "Request failed with status code " << jsonObject["statusCode"].toInt() << std::endl;
        return nullptr;
    }

    QJsonArray dataObject = jsonObject["data"].toArray();
    return new QJsonArray(dataObject);
}

QString SoundShapesApiBackend::GetPrettyName() {
    return QStringLiteral("Sound Shapes");
}

QUrl *SoundShapesApiBackend::GetApiBaseUrl() {
    return new QUrl(QStringLiteral("https://sound.ture.fish/api/v1/"));
}

QUrl *SoundShapesApiBackend::GetApiBaseUrl(QString endpoint) {
    return new QUrl(QStringLiteral("https://sound.ture.fish/api/v1/").append(endpoint));
}

ApiLevel levelFromJson(QJsonObject data) {
    return ApiLevel {
            .levelId = data["id"].toString(),
            .title = data["name"].toString(),
            .description = "",
            .publishDate = 0,
    };
}

ApiLevel SoundShapesApiBackend::GetLevelById(const std::string &levelId) {
    QUrl* url = this->GetApiBaseUrl(QStringLiteral("levels/id/").append(levelId));
    QJsonObject data = *this->getJson(url);
    
    return levelFromJson(data);
}

void SoundShapesApiBackend::GetRecentLevels(uint skip, std::vector<ApiLevel>* levels) {
    QUrl* url = this->GetApiBaseUrl(QStringLiteral("levels"));
    
    QString skipQuery = QStringLiteral("skip=").append(std::to_string(skip));
    QString countQuery = QStringLiteral("&count=").append(std::to_string(levels->capacity()));
    
    QUrlQuery query(skipQuery.append(countQuery));
    
    url->setQuery(query);
    
    QJsonArray data = *this->getJsonList(url);
    for (int i = 0; i < data.size(); i++) {
        ApiLevel level = levelFromJson(data[i].toObject());
        std::cout << i << ": " << level.title.toStdString() << std::endl;

        (*levels)[i] = level;
    }
}


