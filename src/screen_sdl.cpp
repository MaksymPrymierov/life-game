#include <fmt/color.h>
#include <fmt/core.h>
#include <screen_sdl.h>

#include <iostream>

namespace game_life {

screen_sdl::screen_sdl(int w, int h, int life_prob) : screen(w, h, life_prob) {}

screen_sdl::~screen_sdl() {}

void screen_sdl::start() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    return;
  }

  window = SDL_CreateWindow("Life Game", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                            SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
}

void screen_sdl::show() {}

}  // namespace game_life
