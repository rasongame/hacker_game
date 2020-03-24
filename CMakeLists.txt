cmake_minimum_required(VERSION 3.5)

project(hacker_game LANGUAGES CXX)
#find_package(Curses REQUIRED)
set(CMAKE_AUTOMOC ON)
find_package(Qt5 COMPONENTS Widgets Qml Quick REQUIRED)
#include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# SET(CMAKE_CXX_FLAGS "-fpermissive")
add_executable(main main.cpp ledit.hpp main.qml appcore.hpp appcore.cpp ledit.cpp menubar.hpp menubar.cpp PlayerSave.cpp player.hpp Player.cpp)
target_link_libraries(main Qt5::Widgets Qt5::Qml Qt5::Quick)

#target_link_libraries(main ${CURSES_LIBRARIES})
