#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Screen
#include <screen_cli.h>

#include <boost/test/unit_test.hpp>

struct screen_values {
  int x;
  int y;
  int l;
};

BOOST_AUTO_TEST_SUITE(ScreenCliTests)

BOOST_AUTO_TEST_CASE(DefaultConstructorTest) {
  game_life::screen_cli s;

  BOOST_CHECK_EQUAL(s.get_width(), 0);
  BOOST_CHECK_EQUAL(s.get_height(), 0);

  BOOST_CHECK_EQUAL(s.get_pixel(0, 0), false);
}

BOOST_AUTO_TEST_CASE(ConstructorNormalTrueValuesTest) {
  game_life::screen_cli* s;

  std::vector<screen_values> nornal_values_life = {
      {10, 10, 100}, {100, 100, 100}, {100, 500, 100}};

  for (const auto& i : nornal_values_life) {
    s = new game_life::screen_cli(i.x, i.y, i.l);

    BOOST_CHECK_EQUAL(s->get_width(), i.x);
    BOOST_CHECK_EQUAL(s->get_height(), i.y);

    for (int y = 0; y < i.y; ++y) {
      for (int x = 0; x < i.x; ++x) {
        BOOST_CHECK_EQUAL(s->get_pixel(x, y), true);
      }
    }

    delete s;
  }
}

BOOST_AUTO_TEST_CASE(ConstructorNormalFalseValuesTest) {
  game_life::screen_cli* s;

  std::vector<screen_values> nornal_values_null = {
      {10, 10, 0}, {100, 100, 0}, {100, 500, 0}};

  for (const auto& i : nornal_values_null) {
    s = new game_life::screen_cli(i.x, i.y, i.l);

    BOOST_CHECK_EQUAL(s->get_width(), i.x);
    BOOST_CHECK_EQUAL(s->get_height(), i.y);

    for (int y = 0; y < i.y; ++y) {
      for (int x = 0; x < i.x; ++x) {
        BOOST_CHECK_EQUAL(s->get_pixel(x, y), false);
      }
    }

    delete s;
  }
}

BOOST_AUTO_TEST_CASE(ConstructorZeroValuesTest) {
  game_life::screen_cli s(0, 0, 0);

  BOOST_CHECK_EQUAL(s.get_width(), 0);
  BOOST_CHECK_EQUAL(s.get_height(), 0);

  BOOST_CHECK_EQUAL(s.get_pixel(0, 0), false);
}

BOOST_AUTO_TEST_CASE(ConstructorNegativeValuesTest) {
  game_life::screen_cli s(-1, -1, -1);

  BOOST_CHECK_EQUAL(s.get_width(), 0);
  BOOST_CHECK_EQUAL(s.get_height(), 0);

  BOOST_CHECK_EQUAL(s.get_pixel(0, 0), false);
}

BOOST_AUTO_TEST_CASE(ConstructorOverflowValuesTest) {
  game_life::screen_cli s(5, 5, 101);

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      BOOST_CHECK_EQUAL(s.get_pixel(j, i), false);
    }
  }
}

BOOST_AUTO_TEST_SUITE_END()
