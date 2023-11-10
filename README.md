# UgcBrowser
Client written in Qt that lets you traverse custom servers

Using this project to learn C++ and Qt, expect bad code :)

## Goals

I say goals but this is just me brainstorming, you're here too early in other words

Ability to traverse multiple gameserver APIs
- Refresh
- SoundShapes
- K.O.R
- Lighthouse

Maybe a list of instances, like this
```json
[
    {
        "instanceName": "LittleBigRefresh",
        "apiUrl": "https://lbp.littlebigrefresh.com/api/v3/",
        "apiType": "refresh"
    },
    {
        "instanceName": "sound.ture.fish",
        "apiUrl": "https://sound.ture.fish/api/v1/",
        "apiType": "soundShapes"
    },
    {
        "instanceName": "K.O.R Production",
        "apiUrl": "https://kor.ture.fish/api/v1/",
        "apiType": "knyckOchRych"
    },
    {
        "instanceName": "Infinite",
        "apiUrl": "https://lnfinite.site/api/v1/",
        "apiType": "lighthouse"
    },
]
```

Ideally there's have one UI for all apiTypes

Also you'd probably wanna verify if the api type is correct
