#include "ApiBackend.h"
#include "../ApiClient.h"
#include <QtNetwork>

class RefreshApiBackend : public ApiBackend {
private:
    ApiClient* apiClient;
    
public:
    ~RefreshApiBackend() override = default;
    
    QString GetPrettyName() override;
    QUrl* GetApiBaseUrl(QString endpoint) override {
        return new QUrl(QStringLiteral("https://lbp.littlebigrefresh.com/api/v3/").append(endpoint));
    }
    
    QUrl* GetApiBaseUrl() override {
        return new QUrl(QStringLiteral("https://lbp.littlebigrefresh.com/api/v3/"));
    }

    ApiLevel* GetLevelById(const std::string& levelId) override {
        QUrl* url = this->GetApiBaseUrl(QStringLiteral("levels/id/").append(levelId));
        QJsonObject data = *this->apiClient->getJson(url);
        
        return new ApiLevel {
            .levelId = data["levelId"].toString(),
            .title = data["title"].toString(),
            .description = data["description"].toString(),
            .publishDate = 0,
        };
    }
};

QString RefreshApiBackend::GetPrettyName() {
    return "Refresh";
}
