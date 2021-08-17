cmake_minimum_required(VERSION 3.10)

project(GameLife VERSION 0.2)

find_package(Curses REQUIRED)
configure_file(include/config.h.in config.h)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")


add_executable(GameLife 
        src/main.cpp
        src/screen_cli.cpp
        src/game.cpp
        src/screen.cpp
        src/screen_ncurses.cpp
        )

target_include_directories(GameLife PUBLIC ./include ./build)
target_link_libraries(GameLife ${CURSES_LIBRARIES})
