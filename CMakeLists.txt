cmake_minimum_required(VERSION 3.5)

project(hacker_game LANGUAGES CXX)
#find_package(Curses REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
#include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cpp PlayerSave.cpp player.hpp Player.cpp mainwindow.ui mainwindow.cpp)
target_link_libraries(main Qt5::Widgets)

#target_link_libraries(main ${CURSES_LIBRARIES})
