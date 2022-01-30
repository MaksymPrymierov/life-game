#pragma once

#include <random>
#include <vector>

namespace game_life {

class screen {
 public:
  screen() = default;
  screen(int w, int h, int life_prob);
  virtual ~screen() = default;

  virtual void start();
  virtual void show() = 0;
  virtual void print_life_status(size_t life_status, size_t dead_status);

  void set_pixel(int x, int y);
  void unset_pixel(int x, int y);

  bool get_pixel(int x, int y);
  int get_height();
  int get_width();

  bool exit();

 protected:
  int m_height = 0;
  int m_width = 0;
  int m_life_probability = 0;
  std::random_device m_rd;
  std::uniform_int_distribution<int> m_rd_values{0, 100};
  std::vector<std::vector<bool>> m_screen_map;
  bool need_exit = false;

  void random_map_set();
};

}  // namespace game_life
