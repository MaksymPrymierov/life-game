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
        while (1) {
                usleep(60000);
                scan_map();
                process_actions();
                screen->show();
        }
}

void game::scan_map()
{
        int life_count = 0;
        for (int i = 0; i < screen->get_height(); ++i) {
                for (int j = 0; j < screen->get_width(); ++j) {
                        life_count = 0;
                        if (screen->get_pixel(j - 1, i - 1)) {
                                ++life_count;
                        }
                        if (screen->get_pixel(j - 1, i)) {
                                ++life_count;
                        }
                        if (screen->get_pixel(j - 1, i + 1)) {
                                ++life_count;
                        }
                        if (screen->get_pixel(j, i - 1)) {
                                ++life_count;
                        }
                        if (screen->get_pixel(j, i + 1)) {
                                ++life_count;
                        }
                        if (screen->get_pixel(j + 1, i - 1)) {
                                ++life_count;
                        }
                        if (screen->get_pixel(j + 1, i)) {
                                ++life_count;
                        }
                        if (screen->get_pixel(j + 1, i + 1)) {
                                ++life_count;
                        }

                        if (!screen->get_pixel(j, i) && life_count == 3) {
                                actions_stack.push({actions::life, j, i});
                        } else if (screen->get_pixel(j, i) && (life_count > 3 || life_count < 2)) {
                                actions_stack.push({actions::dead, j, i});
                        }
                }
        }
}

void game::process_actions()
{
        while (!actions_stack.empty()) {
                if (actions_stack.top().action == actions::life) {
                        screen->set_pixel(actions_stack.top().x, actions_stack.top().y);
                } else {
                        screen->unset_pixel(actions_stack.top().x, actions_stack.top().y);
                }
                actions_stack.pop();
        }
}

} // game_life
