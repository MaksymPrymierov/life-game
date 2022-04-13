#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Game
#include <game.h>
#include <memory.h>
#include <screen_cli.h>

#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(GameTest)

BOOST_AUTO_TEST_CASE(GameConstructor) {
  std::unique_ptr<game_life::screen> s1 =
      std::make_unique<game_life::screen_cli>();
  game_life::game g1(s1);
  BOOST_ASSERT(g1.is_valid());

  std::unique_ptr<game_life::screen> s2 =
      std::make_unique<game_life::screen_cli>(0, 0, 0);
  game_life::game g2(s2);
  BOOST_ASSERT(g2.is_valid());

  std::unique_ptr<game_life::screen> s3 = nullptr;
  game_life::game g3(s3);
  BOOST_ASSERT(!g3.is_valid());
}

BOOST_AUTO_TEST_CASE(GameStart) {
  std::unique_ptr<game_life::screen> s = nullptr;
  game_life::game g(s);
  BOOST_ASSERT(!g.is_valid());
  BOOST_ASSERT(g.start());
}

BOOST_AUTO_TEST_SUITE_END()
