#pragma once

#include <ncurses.h>
#include <screen.h>

namespace game_life {

class screen_ncurses : public screen {
 public:
  screen_ncurses() = default;
  screen_ncurses(int w, int h, int life_prob);
  ~screen_ncurses();

  void start() override;
  int show() override;
  void print_life_status(size_t life_status, size_t dead_status) override;

 private:
  static constexpr inline char m_life = 'X';
  static constexpr inline char m_dead = ' ';
  static constexpr inline char m_vboard = '|';
  static constexpr inline char m_hboard = '-';
  static constexpr inline char m_corner = '+';

  WINDOW *m_game_win_ptr;

  void create_window();
  void setup_options();
};

};  // namespace game_life
