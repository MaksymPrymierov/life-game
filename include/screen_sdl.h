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
  struct color {
    int r;
    int g;
    int b;
  };

  const unsigned int SCREEN_WIDTH = 1280;
  const unsigned int SCREEN_HEIGHT = 720;
  const unsigned int CELL_WIDTH = 20;
  const unsigned int CELL_HEIGHT = 20;
  const unsigned int GAME_SCREEN_WIDTH = 64;
  const unsigned int GAME_SCREEN_HEIGHT = 36;
  const unsigned int GAME_LIFE_PROBABILITY = 25;

  const color dead_color = {0, 153, 153};
  const color life_color = {255, 135, 0};

  SDL_Surface* background_surface;
  SDL_Window* window;
  SDL_Rect* cell;

  void set_background();
  void update();
  void set_cell(unsigned int x, unsigned int y, color c);
};

}  // namespace game_life
