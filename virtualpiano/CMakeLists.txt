cmake_minimum_required(VERSION 3.20)
project(virtualpiano)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_PREFIX_PATH /usr/local/Cellar/qt@5/5.15.2)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Multimedia REQUIRED)

add_executable(virtualpiano main.cpp mainwindow.cpp mainwindow.h Pianokey.h VolumeControl.cpp VolumeControl.h whitefactory.h whitekey.cpp whitekey.h tunescontrol.cpp tunescontrol.h blackkey.cpp blackkey.h blackkeyfactory.h)
target_link_libraries(virtualpiano Qt5::Widgets)
target_link_libraries(virtualpiano Qt5::Multimedia)