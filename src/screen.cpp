#include <fmt/core.h>
#include <screen.h>

#include <iostream>

namespace game_life {

screen::screen(int w, int h, int life_prob) {
  if (w >= 0 && h >= 0 && life_prob >= 0 && life_prob <= 100) {
    m_height = h;
    m_width = w;
    m_life_probability = life_prob;
  } else {
    m_height = 0;
    m_width = 0;
    m_life_probability = 0;
  }

  m_screen_map.resize(m_height);
  for (auto &i : m_screen_map) {
    i.resize(static_cast<std::size_t>(m_width));
  }
  random_map_set();
}

void screen::start() {
  int w;
  int h;
  int l = -1;

  fmt::print("Enter the width of the map: ");
  std::cin >> w;

  fmt::print("Enter the height of the map: ");
  std::cin >> h;

  while (l < 0 || l > 100) {
    fmt::print("Enter the life probability [0-100] ");
    std::cin >> l;
  }

  m_height = h;
  m_width = w;
  m_life_probability = l;

  m_screen_map.resize(m_height);
  for (auto &i : m_screen_map) {
    i.resize(static_cast<std::size_t>(m_width));
  }
  random_map_set();
}

void screen::set_pixel(int x, int y) {
  if (y < m_height && y >= 0 && x < m_width && x >= 0) {
    m_screen_map[y][x] = true;
  }
}

void screen::unset_pixel(int x, int y) {
  if (y < m_height && y >= 0 && x < m_width && x >= 0) {
    m_screen_map[y][x] = false;
  }
}

bool screen::get_pixel(int x, int y) {
  if (y < m_height && y >= 0 && x < m_width && x >= 0) {
    return m_screen_map[y][x];
  }

  return false;
}

int screen::get_height() { return m_height; }

int screen::get_width() { return m_width; }

void screen::random_map_set() {
  for (int i = 0; i < m_height; ++i) {
    for (int j = 0; j < m_width; ++j) {
      if (m_rd_values(m_rd) > m_life_probability || m_life_probability == 0) {
        m_screen_map[i][j] = false;
      } else {
        m_screen_map[i][j] = true;
      }
    }
  }
}

bool screen::exit() { return !need_exit; }

};  // namespace game_life
