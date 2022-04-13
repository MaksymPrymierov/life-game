cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER "g++-10")
set(CMAKE_C_COMPILER "gcc-10")
set(CMAKE_BUILD_TYPE Release)
set(Boost_NOE_WARN_NEW_VERSIONS 1)
set(CMAKE_TOOLCHAIN_FILE build/cmake-build-release/conan_toolchain.cmake)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")

project(GameLife VERSION 0.6)

find_package(ncurses REQUIRED)
find_package(fmt REQUIRED)
find_package(SDL2 REQUIRED)
find_package(Boost COMPONENTS program_options REQUIRED)
configure_file(include/config.h.in config.h)

set(GameLife_src
        src/screen_cli.cpp
        src/game.cpp
        src/screen.cpp
        src/screen_ncurses.cpp
        src/screen_sdl.cpp
        src/screen/factory.cpp
        )

add_executable(GameLife
        src/main.cpp
        ${GameLife_src}
        )

add_library(GameLife_lib STATIC ${GameLife_src})

target_include_directories(GameLife PUBLIC
        ./include
        ./build
        )

target_include_directories(GameLife_lib PUBLIC
        ./include
        )

target_link_libraries(GameLife_lib PUBLIC
        ncurses::ncurses
        sdl::sdl
        fmt::fmt
        Boost::boost
        Boost::program_options
        )

target_link_libraries(GameLife PUBLIC
        ncurses::ncurses
        sdl::sdl
        fmt::fmt
        Boost::boost
        Boost::program_options
        )

enable_testing()

add_subdirectory(test build/test)
