#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Screen
#include <boost/test/unit_test.hpp>

#include <screen_cli.h>

BOOST_AUTO_TEST_SUITE(ScreenCliTests)

BOOST_AUTO_TEST_CASE(DefaultConstructorTest)
{
        game_life::screen_cli s;

        BOOST_CHECK_EQUAL(s.get_width(), 0);
        BOOST_CHECK_EQUAL(s.get_height(), 0);

        BOOST_CHECK_EQUAL(s.get_pixel(0, 0), false);
}

BOOST_AUTO_TEST_SUITE_END()
