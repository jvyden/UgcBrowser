#include "ApiBackend.h"
#include "../ApiClient.h"
#include <QtNetwork>
#include "RefreshApiBackend.h"

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
    QJsonObject data = *this->apiClient->getJson(url);

    return ApiLevel::fromJson(data);
}
