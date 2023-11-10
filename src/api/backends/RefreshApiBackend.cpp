#include "ApiBackend.h"
#include <QtNetwork>

class RefreshApiBackend : public ApiBackend {
    ~RefreshApiBackend() override = default;
private:
//    QNetworkAccessManager* networkAccessManager = new QNetworkAccessManager;

public:
    QString GetPrettyName() override;
    QUrl* GetApiBaseUrl(QString endpoint) override {
        return new QUrl(QStringLiteral("https://lbp.littlebigrefresh.com/api/v3/").append(endpoint));
    }
    
    QUrl* GetApiBaseUrl() override {
        return new QUrl(QStringLiteral("https://lbp.littlebigrefresh.com/api/v3/"));
    }

    ApiLevel* GetLevelById(const std::string& levelId) {
        QUrl* url = this->GetApiBaseUrl("levels/id/1");
        std::cout << "URL: " << url->toString().toStdString() << std::endl;
        QNetworkRequest request(*url);
        QNetworkAccessManager manager;
        QNetworkReply* reply = manager.get(request);

        while (!reply->isFinished())
        {
            qApp->processEvents();
        }

        QByteArray response_data = reply->readAll();
        QJsonDocument json = QJsonDocument::fromJson(response_data);
        reply->deleteLater();
        
        return new ApiLevel {
            .levelId = "1",
            .title = std::to_string(json.object().count()),
            .description = "description",
            .publishDate = 0,
        };
    }
};

QString RefreshApiBackend::GetPrettyName() {
    return "Refresh";
}
