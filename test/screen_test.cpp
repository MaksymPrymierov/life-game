#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Screen
#include <boost/test/included/unit_test.hpp>
#include <screen_cli.h>
#include <screen_ncurses.h>
#include <screen_sdl.h>

BOOST_AUTO_TEST_SUITE(ScreenTest)

BOOST_AUTO_TEST_CASE(ScreenConstructor) {
  int incorrect_size[3] = {-1000, -1, 0};
  int correct_size[3] = {1, 10, 100};
  int incorrect_lifep[4] = {-1, 0, 100, 1000};
  int correct_lifep[3] = {1, 50, 99};

  game_life::screen_cli c;  // Null Constructor
  game_life::screen_ncurses n;
  game_life::screen_sdl s;
  BOOST_ASSERT(!c.is_valid());
  BOOST_ASSERT(!n.is_valid());
  BOOST_ASSERT(!s.is_valid());

  for (int i = 0; i < 3; ++i) {
    game_life::screen_cli c(incorrect_size[i], incorrect_size[i], 10);
    game_life::screen_ncurses n(incorrect_size[i], incorrect_size[i], 10);
    game_life::screen_sdl s(incorrect_size[i], incorrect_size[i], 10);

    BOOST_ASSERT(!c.is_valid());
    BOOST_ASSERT(!n.is_valid());
    BOOST_ASSERT(!s.is_valid());
  }

  for (int i = 0; i < 3; ++i) {
    game_life::screen_cli c(correct_size[i], correct_size[i], 10);
    game_life::screen_ncurses n(correct_size[i], correct_size[i], 10);
    game_life::screen_sdl s(correct_size[i], correct_size[i], 10);

    BOOST_ASSERT(c.is_valid());
    BOOST_ASSERT(n.is_valid());
    BOOST_ASSERT(s.is_valid());
  }

  for (int i = 0; i < 4; ++i) {
    game_life::screen_cli c(10, 10, incorrect_lifep[i]);
    game_life::screen_ncurses n(10, 10, incorrect_lifep[i]);
    game_life::screen_sdl s(10, 10, incorrect_lifep[i]);

    BOOST_ASSERT(!c.is_valid());
    BOOST_ASSERT(!n.is_valid());
    BOOST_ASSERT(!s.is_valid());
  }

  for (int i = 0; i < 3; ++i) {
    game_life::screen_cli c(10, 10, correct_lifep[i]);
    game_life::screen_ncurses n(10, 10, correct_lifep[i]);
    game_life::screen_sdl s(10, 10, correct_lifep[i]);

    BOOST_ASSERT(c.is_valid());
    BOOST_ASSERT(n.is_valid());
    BOOST_ASSERT(s.is_valid());
  }
}

BOOST_AUTO_TEST_CASE(ScreenShow) {
  game_life::screen_cli c(-1, -1, -1);
  BOOST_ASSERT(c.show());
}

BOOST_AUTO_TEST_CASE(ScreenPixel) {
  int incorrect_cord[4] = {-1000, -1, 20, 1000};

  for (int i = 0; i < 4; ++i) {
    game_life::screen_cli s(20, 20, 20);
    s.set_pixel(incorrect_cord[i], incorrect_cord[i]);
    s.unset_pixel(incorrect_cord[i], incorrect_cord[i]);
    BOOST_ASSERT(!s.get_pixel(incorrect_cord[i], incorrect_cord[i]));
  }
}

BOOST_AUTO_TEST_SUITE_END()
