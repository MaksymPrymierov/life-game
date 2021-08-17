#include <game.h>

#include <unistd.h>

#include <chrono>
#include <thread>

namespace game_life
{

game::game(screen *s) :
        m_screen(s)
{  }

game::~game()
{  }

void game::start()
{
        while (1) {
                std::this_thread::sleep_for(std::chrono::milliseconds(m_game_cycle_delay));
                scan_map();
                process_actions();
                m_screen->show();
        }
}

void game::scan_map()
{
        int life_count = 0;
        for (int i = 0; i < m_screen->get_height(); ++i) {
                for (int j = 0; j < m_screen->get_width(); ++j) {
                        life_count = 0;
                        if (m_screen->get_pixel(j - 1, i - 1)) {
                                ++life_count;
                        }
                        if (m_screen->get_pixel(j - 1, i)) {
                                ++life_count;
                        }
                        if (m_screen->get_pixel(j - 1, i + 1)) {
                                ++life_count;
                        }
                        if (m_screen->get_pixel(j, i - 1)) {
                                ++life_count;
                        }
                        if (m_screen->get_pixel(j, i + 1)) {
                                ++life_count;
                        }
                        if (m_screen->get_pixel(j + 1, i - 1)) {
                                ++life_count;
                        }
                        if (m_screen->get_pixel(j + 1, i)) {
                                ++life_count;
                        }
                        if (m_screen->get_pixel(j + 1, i + 1)) {
                                ++life_count;
                        }

                        if (!m_screen->get_pixel(j, i) && life_count == 3) {
                                m_actions_stack.push({actions::life, j, i});
                        } else if (m_screen->get_pixel(j, i) && (life_count > 3 || life_count < 2)) {
                                m_actions_stack.push({actions::dead, j, i});
                        }
                }
        }
}

void game::process_actions()
{
        while (!m_actions_stack.empty()) {
                if (m_actions_stack.top().action == actions::life) {
                        m_screen->set_pixel(m_actions_stack.top().x, m_actions_stack.top().y);
                } else {
                        m_screen->unset_pixel(m_actions_stack.top().x, m_actions_stack.top().y);
                }
                m_actions_stack.pop();
        }
}

} // game_life
