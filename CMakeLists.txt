cmake_minimum_required(VERSION 3.10)

project(GameLife VERSION 0.1)

configure_file(include/config.h.in config.h)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD True)

add_executable(GameLife 
        src/main.cpp
        src/screen_cli.cpp
        )

target_include_directories(GameLife PUBLIC "${PROJECT_BINARY_DIR}" ./include)
