project(GameLife_TEST)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

target_include_directories(GameLife PUBLIC ${PROJECT_SOURCE_DIR}/include)

set(game_source game_test.cpp)
set(screen_source screen_test.cpp)

add_executable(game_test ${game_source})
add_executable(screen_test ${screen_source})

target_link_libraries(game_test PUBLIC ${Boost_LIBRARIES} GameLife_lib)
target_link_libraries(screen_test PUBLIC ${Boost_LIBRARIES} GameLife_lib)

add_test(NAME GameTest COMMAND game_test)
add_test(NAME ScreenTest COMMAND screen_test)
