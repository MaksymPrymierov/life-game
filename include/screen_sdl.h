#pragma once

#include <SDL2/SDL.h>
#include <screen.h>

namespace game_life {

class screen_sdl : public screen {
 public:
  screen_sdl() = default;
  screen_sdl(int x, int y, int life_prob);
  ~screen_sdl();

  void start() override;
  void show() override;

 private:
  const int SCREEN_WIDTH = 1280;
  const int SCREEN_HEIGHT = 720;

  SDL_Surface* screen_surface;
  SDL_Window* window;
};

}  // namespace game_life
