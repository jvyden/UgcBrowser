#ifndef UGCBROWSER_APILEVEL_H
#define UGCBROWSER_APILEVEL_H

#include <string>

struct ApiLevel {
public:
    std::string levelId;
    std::string title;
    std::string description;
    long publishDate;
};

#endif //UGCBROWSER_APILEVEL_H
