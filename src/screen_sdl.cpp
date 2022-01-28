#include <fmt/color.h>
#include <fmt/core.h>
#include <screen_sdl.h>

#include <iostream>

namespace game_life {

screen_sdl::screen_sdl(int w, int h, int life_prob) : screen(w, h, life_prob) {}

screen_sdl::~screen_sdl() {}

void screen_sdl::start() {}

void screen_sdl::show() {}

}  // namespace game_life
