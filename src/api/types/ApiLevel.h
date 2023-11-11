#ifndef UGCBROWSER_APILEVEL_H
#define UGCBROWSER_APILEVEL_H

#include <string>
#include <QJsonObject>

struct ApiLevel {
public:
    QString levelId;
    QString title;
    QString description;
    long publishDate;
    
    static ApiLevel fromJson(QJsonObject object) {
        return ApiLevel {
            .levelId = object["levelId"].toString(),
            .title = object["title"].toString(),
            .description = object["description"].toString(),
            .publishDate = 0,
        };
    }
};

#endif //UGCBROWSER_APILEVEL_H
