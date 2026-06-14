cmake_minimum_required(VERSION 3.16)
project(QtProtocolViewer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(QtProtocolViewer
    src/main.cpp
    src/MainWindow.cpp
)

target_link_libraries(QtProtocolViewer Qt6::Widgets)