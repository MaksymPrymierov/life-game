project(GameLife_TEST)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

target_include_directories(GameLife PUBLIC ${PROJECT_SOURCE_DIR}/include)

set(screen_cli_source screen_cli_test.cpp)
set(screen_ncurses_source screen_ncurses_test.cpp)

add_executable(screen_cli_test ${screen_cli_source})
add_executable(screen_ncurses_test ${screen_ncurses_source})

target_link_libraries(screen_cli_test PUBLIC ${Boost_LIBRARIES} GameLife_lib)
target_link_libraries(screen_ncurses_test PUBLIC ${Boost_LIBRARIES} GameLife_lib)

add_test(NAME ScreenCliTest COMMAND screen_cli_test)
add_test(NAME ScreenNCursesTest COMMAND screen_ncurses_test)
