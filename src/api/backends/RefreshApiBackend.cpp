#include "ApiBackend.h"
#include <QtNetwork>

class RefreshApiBackend : public ApiBackend {
private:
    QNetworkAccessManager* networkManager;
    
public:
    ~RefreshApiBackend() override = default;
    
    QString GetPrettyName() override;
    QUrl* GetApiBaseUrl(QString endpoint) override {
        return new QUrl(QStringLiteral("https://lbp.littlebigrefresh.com/api/v3/").append(endpoint));
    }
    
    QUrl* GetApiBaseUrl() override {
        return new QUrl(QStringLiteral("https://lbp.littlebigrefresh.com/api/v3/"));
    }

    ApiLevel* GetLevelById(const std::string& levelId) {
        QUrl* url = this->GetApiBaseUrl("levels/id/1");
        QNetworkRequest request(*url);
        QNetworkReply* reply = this->networkManager->get(request);

        while (!reply->isFinished())
        {
            qApp->processEvents();
        }

        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObject = jsonDocument.object();
        reply->deleteLater();
        
        return new ApiLevel {
            .levelId = "1",
            .title = jsonObject["data"].toObject()["title"].toString().toStdString(),
            .description = "asdf",
            .publishDate = 0,
        };
    }
};

QString RefreshApiBackend::GetPrettyName() {
    return "Refresh";
}
