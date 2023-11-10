qt_add_executable(UgcBrowser main.cpp
        windows/MainWindow.cpp
        windows/MainWindow.h
        windows/MainWindow.ui)
target_link_libraries(UgcBrowser PRIVATE Qt6::Core Qt6::Widgets)

set_target_properties(UgcBrowser PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)