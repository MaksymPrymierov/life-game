#include <game.h>

namespace game_life
{

game::game(screen_cli *s) :
        screen(s)
{  }

game::~game()
{  }

void game::start()
{
        while (1) {
                int life_count = 0;
                for (int i = 0; i < screen->get_height(); ++i) {
                        for (int j = 0; j < screen->get_weight(); ++j) {
                                if (screen->get_pixel(--i, --j)) {
                                        ++life_count;
                                }
                                if (screen->get_pixel(--i, j)) {
                                        ++life_count;
                                }
                                if (screen->get_pixel(--i, ++j)) {
                                        ++life_count;
                                }
                                if (screen->get_pixel(i, ++j)) {
                                        ++life_count;
                                }
                                if (screen->get_pixel(++i, ++j)) {
                                        ++life_count;
                                }
                                if (screen->get_pixel(++i, j)) {
                                        ++life_count;
                                }
                                if (screen->get_pixel(++i, --j)) {
                                        ++life_count;
                                }
                                if (screen->get_pixel(i, --j)) {
                                        ++life_count;
                                }

                                if (!screen->get_pixel(j, i) && life_count == 3) {
                                        screen->set_pixel(j, i);
                                } else if (screen->get_pixel(j, i) && life_count < 2 && life_count > 3) {
                                        screen->unset_pixel(j, i);
                                }
                        }
                }
        }
}

} // game_life
