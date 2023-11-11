qt_add_executable(UgcBrowser main.cpp
        windows/MainWindow.cpp
        windows/MainWindow.h
        windows/MainWindow.ui
        api/backends/ApiBackend.h
        api/backends/RefreshApiBackend.cpp
        api/backends/RefreshApiBackend.h
        api/backends/RefreshApiBackend.h
        api/types/ApiLevel.h
        api/backends/RefreshApiBackend.h
        api/ApiClient.cpp
        api/ApiClient.h
        api/backends/SoundShapesApiBackend.cpp
        api/backends/SoundShapesApiBackend.h)

set_target_properties(UgcBrowser PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)