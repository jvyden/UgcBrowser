cmake_minimum_required(VERSION 3.26)
project(UgcBrowser VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Network)
qt_standard_project_setup()

add_subdirectory(src)
target_link_libraries(UgcBrowser PRIVATE Qt6::Core Qt6::Widgets Qt6::Network)

