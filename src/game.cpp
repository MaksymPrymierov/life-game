#include <game.h>

#include <unistd.h>

#include <chrono>
#include <thread>

namespace game_life
{

game::game(screen *s) :
        screen_(s)
{  }

game::~game()
{  }

void game::start()
{
        while (1) {
                std::this_thread::sleep_for(std::chrono::milliseconds(game_cycle_delay));
                scan_map();
                process_actions();
                screen_->show();
        }
}

void game::scan_map()
{
        int life_count = 0;
        for (int i = 0; i < screen_->get_height(); ++i) {
                for (int j = 0; j < screen_->get_width(); ++j) {
                        life_count = 0;
                        if (screen_->get_pixel(j - 1, i - 1)) {
                                ++life_count;
                        }
                        if (screen_->get_pixel(j - 1, i)) {
                                ++life_count;
                        }
                        if (screen_->get_pixel(j - 1, i + 1)) {
                                ++life_count;
                        }
                        if (screen_->get_pixel(j, i - 1)) {
                                ++life_count;
                        }
                        if (screen_->get_pixel(j, i + 1)) {
                                ++life_count;
                        }
                        if (screen_->get_pixel(j + 1, i - 1)) {
                                ++life_count;
                        }
                        if (screen_->get_pixel(j + 1, i)) {
                                ++life_count;
                        }
                        if (screen_->get_pixel(j + 1, i + 1)) {
                                ++life_count;
                        }

                        if (!screen_->get_pixel(j, i) && life_count == 3) {
                                actions_stack.push({actions::life, j, i});
                        } else if (screen_->get_pixel(j, i) && (life_count > 3 || life_count < 2)) {
                                actions_stack.push({actions::dead, j, i});
                        }
                }
        }
}

void game::process_actions()
{
        while (!actions_stack.empty()) {
                if (actions_stack.top().action == actions::life) {
                        screen_->set_pixel(actions_stack.top().x, actions_stack.top().y);
                } else {
                        screen_->unset_pixel(actions_stack.top().x, actions_stack.top().y);
                }
                actions_stack.pop();
        }
}

} // game_life
