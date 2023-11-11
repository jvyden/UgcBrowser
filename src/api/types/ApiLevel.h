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
};

#endif //UGCBROWSER_APILEVEL_H
