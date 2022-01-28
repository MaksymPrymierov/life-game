#include <fmt/color.h>
#include <fmt/core.h>
#include <screen_cli.h>

#include <iostream>

namespace game_life {

screen_cli::screen_cli(int w, int h, int life_prob) : screen(w, h, life_prob) {}

screen_cli::~screen_cli() {}

void screen_cli::show() {
  clear();

  print_corner_top_left();
  print_hboards();
  print_corner_top_right();

  for (int i = 0; i < m_height; ++i) {
    print_vboards();
    for (int j = 0; j < m_width; ++j) {
      if (m_screen_map[i][j]) {
        fmt::print(fmt::emphasis::bold | fg(fmt::color::yellow) |
                       bg(fmt::color::black),
                   "{}", m_life);
      } else {
        fmt::print(bg(fmt::color::black), "{}", m_dead);
      }
    }
    print_vboards();
    fmt::print("\n");
  }

  print_corner_bottom_left();
  print_hboards();
  print_corner_bottom_right();
}

void screen_cli::clear() {
  /* Clear screem. This workis for Linux and Windows */
  fmt::print("\033[2J\033[1;1H");
}

void screen_cli::print_vboards() {
  fmt::print(fg(fmt::color::red) | bg(fmt::color::black), "{}", m_vboard);
}

void screen_cli::print_hboards() {
  for (int i = 0; i < m_width; ++i) {
    fmt::print(fg(fmt::color::red) | bg(fmt::color::black), "{}", m_hboard);
  }
}

void screen_cli::print_corner_top_left() {
  fmt::print(fg(fmt::color::red) | bg(fmt::color::black), "{}",
             m_corner_top_left);
}

void screen_cli::print_corner_top_right() {
  fmt::print(fg(fmt::color::red) | bg(fmt::color::black), "{}\n",
             m_corner_top_right);
}

void screen_cli::print_corner_bottom_left() {
  fmt::print(fg(fmt::color::red) | bg(fmt::color::black), "{}",
             m_corner_bottom_left);
}

void screen_cli::print_corner_bottom_right() {
  fmt::print(fg(fmt::color::red) | bg(fmt::color::black), "{}\n",
             m_corner_bottom_right);
}

}  // namespace game_life
