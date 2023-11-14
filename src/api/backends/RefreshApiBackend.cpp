#include <QtNetwork>
#include "RefreshApiBackend.h"

ApiLevel levelFromRefreshJson(QJsonObject data) {
    return ApiLevel {
            .levelId = data["levelId"].toString(),
            .title = data["title"].toString(),
            .description = data["description"].toString(),
            .publishDate = 0,
    };
}

QJsonObject* RefreshApiBackend::getJson(QUrl *url) {
    QJsonObject jsonObject = this->apiClient->getJson(url);

    bool success = jsonObject["success"].toBool(false);
    if(!success) {
        return nullptr;
    }

    QJsonObject dataObject = jsonObject["data"].toObject();
    return new QJsonObject(dataObject);
}

QJsonArray* RefreshApiBackend::getJsonList(QUrl *url) {
    QJsonObject jsonObject = this->apiClient->getJson(url);

    bool success = jsonObject["success"].toBool(false);
    if(!success) {
        return nullptr;
    }

    QJsonArray dataObject = jsonObject["data"].toArray();
    return new QJsonArray(dataObject);
}

QUrl *RefreshApiBackend::GetApiBaseUrl() {
    return new QUrl(QStringLiteral("https://lbp.littlebigrefresh.com/api/v3/"));
}

QUrl *RefreshApiBackend::GetApiBaseUrl(QString endpoint) {
    return new QUrl(QStringLiteral("https://lbp.littlebigrefresh.com/api/v3/").append(endpoint));
}

QString RefreshApiBackend::GetPrettyName() {
    return QStringLiteral("Refresh");
}

ApiLevel RefreshApiBackend::GetLevelById(const std::string &levelId) {
    QUrl* url = this->GetApiBaseUrl(QStringLiteral("levels/id/").append(levelId));
    QJsonObject data = *this->getJson(url);

    return levelFromRefreshJson(data);
}

void RefreshApiBackend::GetRecentLevels(uint skip, std::vector<ApiLevel>* levels) {
    QUrl* url = this->GetApiBaseUrl(QStringLiteral("levels/newest"));

    QString skipQuery = QStringLiteral("skip=").append(std::to_string(skip));
    QString countQuery = QStringLiteral("&count=").append(std::to_string(levels->capacity()));

    QUrlQuery query(skipQuery.append(countQuery));

    url->setQuery(query);

    QJsonArray data = *this->getJsonList(url);
    for (int i = 0; i < data.size(); i++) {
        ApiLevel level = levelFromRefreshJson(data[i].toObject());
        (*levels)[i] = level;
    }
}
