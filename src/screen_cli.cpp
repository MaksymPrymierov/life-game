#include <fmt/color.h>
#include <fmt/core.h>
#include <screen_cli.h>

#include <spdlog/spdlog.h>

#include <iostream>

namespace game_life {

screen_cli::screen_cli(int w, int h, int life_prob) : screen(w, h, life_prob) {}

screen_cli::~screen_cli() {}

int screen_cli::show() {
  if (!is_valid()) {
    spdlog::error("CLI Screen is invalid.");
    return -1;
  }

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

  return 0;
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

void screen_cli::print_life_status(size_t life_status, size_t dead_status) {
  fmt::print("Life cell: [{}], Dead cell: [{}]\n", life_status, dead_status);

  if (m_old_life == life_status && m_old_dead == dead_status) {
    ++m_old_time;
    if (m_old_time == 10) {
      fmt::print("End!\n");
      need_exit = true;
    }
  } else {
    m_old_time = 0;
    m_old_life = life_status;
    m_old_dead = dead_status;
  }
}

}  // namespace game_life
