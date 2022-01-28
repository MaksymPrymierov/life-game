#pragma once

#include <screen.h>

namespace game_life {

class screen_sdl : public screen {
 public:
  screen_sdl() = default;
  screen_sdl(int x, int y, int life_prob);
  ~screen_sdl();

  void start() override;
  void show() override;
};

}  // namespace game_life
