#pragma once

#include <screen.h>

#include <memory>
#include <stack>

namespace game_life {

class game {
 public:
  game(std::unique_ptr<screen>& s);
  ~game();

  int start();
  bool is_valid();

 private:
  enum class actions { life = 0, dead };

  struct action_data {
    actions action;
    int x;
    int y;
  };

  static constexpr inline unsigned int m_game_cycle_delay =
      100;  // milliseconds
  std::stack<action_data> m_actions_stack;
  std::unique_ptr<screen> m_screen;
  size_t m_life_size;
  size_t m_dead_size;

  void scan_map();
  void process_actions();
};

}  // namespace game_life
