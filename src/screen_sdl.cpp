#include <fmt/color.h>
#include <fmt/core.h>
#include <screen_sdl.h>

#include <iostream>

namespace game_life {

screen_sdl::screen_sdl(int w, int h, int life_prob) : screen(w, h, life_prob) {}

screen_sdl::~screen_sdl() {
  SDL_DestroyWindow(window);
  SDL_Quit();

  delete cell;
}

void screen_sdl::start() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    return;
  }

  window = SDL_CreateWindow("Life Game", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                            SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  if (!window) {
    fmt::print(fg(fmt::color::red), "Error: SDL Window can't create!");
  }

  background_surface = SDL_GetWindowSurface(window);

  m_width = GAME_SCREEN_WIDTH;
  m_height = GAME_SCREEN_HEIGHT;
  m_life_probability = GAME_LIFE_PROBABILITY;

  m_screen_map.resize(m_height);
  for (auto &i : m_screen_map) {
    i.resize(static_cast<std::size_t>(m_width));
  }
  random_map_set();

  cell = new SDL_Rect(0, 0, CELL_WIDTH, CELL_HEIGHT);

  set_background();
}

void screen_sdl::show() {
  for (int i = 0; i < m_height; ++i) {
    for (int j = 0; j < m_width; ++j) {
      if (m_screen_map.at(i).at(j)) {
        set_cell(j, i, life_color);
      } else {
        set_cell(j, i, dead_color);
      }
    }
  }

  update();
}

void screen_sdl::set_background() {
  SDL_FillRect(background_surface, NULL,
               SDL_MapRGB(background_surface->format, dead_color.r,
                          dead_color.g, dead_color.b));
}

void screen_sdl::update() {
  handle_events();
  SDL_UpdateWindowSurface(window);
}

void screen_sdl::set_cell(unsigned int x, unsigned int y, color c) {
  if (x >= GAME_SCREEN_WIDTH || y >= GAME_SCREEN_HEIGHT) {
    return;
  }

  cell->x = x * CELL_WIDTH;
  cell->y = y * CELL_HEIGHT;

  SDL_FillRect(background_surface, cell,
               SDL_MapRGB(background_surface->format, c.r, c.g, c.b));
}

void screen_sdl::handle_events() {
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      need_exit = true;
    }

    if (e.type == SDL_KEYDOWN) {
      if (e.key.keysym.sym == SDLK_ESCAPE) {
        need_exit = true;
      }
    }
  }
}

}  // namespace game_life
