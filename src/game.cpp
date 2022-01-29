#include <fmt/color.h>
#include <fmt/core.h>
#include <fmt/format.h>
#include <game.h>
#include <unistd.h>

#include <chrono>
#include <thread>

namespace game_life {

game::game(std::unique_ptr<screen>& s) { m_screen = std::move(s); }

game::~game() {}

int game::start() {
  if (!is_valid()) {
    fmt::print(fg(fmt::color::red), "Error: Game loaded incorrectly!\n");
    return -1;
  }
  fmt::print("Loading game...\n");

  while (m_screen->exit()) {
    std::this_thread::sleep_for(std::chrono::milliseconds(m_game_cycle_delay));
    scan_map();
    process_actions();
    m_screen->show();
  }

  return 0;
}

void game::scan_map() {
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
      } else if (m_screen->get_pixel(j, i) &&
                 (life_count > 3 || life_count < 2)) {
        m_actions_stack.push({actions::dead, j, i});
      }
    }
  }
}

void game::process_actions() {
  while (!m_actions_stack.empty()) {
    if (m_actions_stack.top().action == actions::life) {
      m_screen->set_pixel(m_actions_stack.top().x, m_actions_stack.top().y);
    } else {
      m_screen->unset_pixel(m_actions_stack.top().x, m_actions_stack.top().y);
    }
    m_actions_stack.pop();
  }
}

bool game::is_valid() {
  if (m_screen.get() == nullptr) {
    return false;
  }

  return true;
}

}  // namespace game_life
