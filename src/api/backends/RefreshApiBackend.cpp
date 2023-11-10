#include "ApiBackend.h"
#include "../types/ApiLevel.h"

class RefreshApiBackend : public ApiBackend {
    ~RefreshApiBackend() override = default;

public:
    QString GetPrettyName() override;
    QUrl* GetApiBaseUrl() override {
        return new QUrl("https://lbp.littlebigrefresh.com/api/v3/");
    }

    ApiLevel* GetLevelById(const std::string& levelId) {
        return new ApiLevel {
            .levelId = levelId,
            .title = "test",
            .description = "description",
            .publishDate = 0,
        };
    }
};

QString RefreshApiBackend::GetPrettyName() {
    return "Refresh";
}
