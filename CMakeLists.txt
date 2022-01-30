cmake_minimum_required(VERSION 3.10)

project(GameLife VERSION 0.6)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
        message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
        file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake"
                "${CMAKE_BINARY_DIR}/conan.cmake"
                EXPECTED_HASH SHA256=396e16d0f5eabdc6a14afddbcfff62a54a7ee75c6da23f32f7a31bc85db23484
                TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_configure(
        REQUIRES fmt/8.1.1 ncurses/6.3 boost/1.78.0 sdl/2.0.20
        GENERATORS cmake_find_package)

conan_cmake_autodetect(settings)

conan_cmake_install(
        PATH_OR_REFERENCE .
        BUILD missing
        REMOTE conancenter
        SETTINGS ${settings})

find_package(Curses REQUIRED)
find_package(fmt REQUIRED)
find_package(SDL2 REQUIRED)
find_package(Boost COMPONENTS program_options REQUIRED)
configure_file(include/config.h.in config.h)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")

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
        ${SDL2_INCLUDE_DIRS}
        ./include
        ./build
        )

target_include_directories(GameLife_lib PUBLIC
        ${SDL2_INCLUDE_DIRS}
        ./include
        )

target_link_libraries(GameLife_lib PUBLIC
        ${CURSES_LIBRARIES}
        ${SDL2_LIBRARIES}
        ${Boost_LIBRARIES}
        fmt::fmt
        )

target_link_libraries(GameLife PUBLIC
        ${CURSES_LIBRARIES}
        ${SDL2_LIBRARIES}
        ${Boost_LIBRARIES}
        fmt::fmt
        )

enable_testing()

add_subdirectory(test build/test)
