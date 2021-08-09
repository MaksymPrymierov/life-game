#include <game.h>

#include <unistd.h>

#include <iostream>

namespace game_life
{

game::game(screen_cli *s) :
        screen(s)
{  }

game::~game()
{  }

void game::start()
{
        int life_count = 0;
        while (1) {
                sleep(1);
                for (int i = 0; i < screen->get_height(); ++i) {
                        for (int j = 0; j < screen->get_weight(); ++j) {
                                life_count = 0;
                                if (screen->get_pixel(i - 1, j - 1)) {
                                        ++life_count;
                                }
                                if (screen->get_pixel(i - 1, j)) {
                                        ++life_count;
                                }
                                if (screen->get_pixel(i - 1, j + 1)) {
                                        ++life_count;
                                }
                                if (screen->get_pixel(i, j - 1)) {
                                        ++life_count;
                                }
                                if (screen->get_pixel(i, j + 1)) {
                                        ++life_count;
                                }
                                if (screen->get_pixel(i + 1, j - 1)) {
                                        ++life_count;
                                }
                                if (screen->get_pixel(i + 1, j)) {
                                        ++life_count;
                                }
                                if (screen->get_pixel(i + 1, j + 1)) {
                                        ++life_count;
                                }

                                if (!screen->get_pixel(j, i) && life_count == 3) {
                                        screen->set_pixel(j, i);
                                } else if (screen->get_pixel(j, i) && life_count != 3 && life_count != 2) {
                                        screen->unset_pixel(j, i);
                                }
                        }
                        screen->show();
                }
        }
}

} // game_life
