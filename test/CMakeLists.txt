project(GameLife_TEST)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

set(screen_cli_source screen_cli_test.cpp)

add_executable(screen_cli_test ${screen_cli_source})

target_include_directories(GameLife PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(screen_cli_test PUBLIC ${Boost_LIBRARIES} GameLife_lib)

add_test(NAME ScreenCliTest COMMAND screen_cli_test)
