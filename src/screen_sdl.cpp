#include <fmt/color.h>
#include <fmt/core.h>
#include <screen_sdl.h>

#include <iostream>

namespace game_life {

screen_sdl::screen_sdl(int w, int h, int life_prob) : screen(w, h, life_prob) {}

screen_sdl::~screen_sdl() {
  SDL_DestroyWindow(m_window_ptr);
  SDL_Quit();
}

void screen_sdl::start() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    return;
  }

  m_window_ptr = SDL_CreateWindow("Life Game", SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED, m_screen_width,
                                  m_screen_height, SDL_WINDOW_SHOWN);

  if (!m_window_ptr) {
    fmt::print(fg(fmt::color::red), "Error: SDL Window can't create!");
  }

  m_background_surface_ptr = SDL_GetWindowSurface(m_window_ptr);

  m_width = m_game_screen_width;
  m_height = m_game_screen_height;
  m_life_probability = m_game_life_probability;

  alloc_screen_map();
  random_map_set();

  m_cell_ptr = std::make_unique<SDL_Rect>(0, 0, m_cell_width, m_cell_height);

  set_background();
}

int screen_sdl::show() {
  if (!is_valid()) {
    return -1;
  }

  for (int i = 0; i < m_height; ++i) {
    for (int j = 0; j < m_width; ++j) {
      if (m_screen_map.at(i).at(j)) {
        set_cell(j, i, m_life_color);
      } else {
        set_cell(j, i, m_dead_color);
      }
    }
  }

  update();

  return 0;
}

void screen_sdl::set_background() {
  SDL_FillRect(m_background_surface_ptr, NULL,
               SDL_MapRGB(m_background_surface_ptr->format, m_dead_color.r,
                          m_dead_color.g, m_dead_color.b));
}

void screen_sdl::update() {
  handle_events();
  SDL_UpdateWindowSurface(m_window_ptr);
}

void screen_sdl::set_cell(unsigned int x, unsigned int y, color c) {
  if (x >= m_game_screen_width || y >= m_game_screen_height) {
    return;
  }

  m_cell_ptr->x = x * m_cell_width;
  m_cell_ptr->y = y * m_cell_height;

  SDL_FillRect(m_background_surface_ptr, m_cell_ptr.get(),
               SDL_MapRGB(m_background_surface_ptr->format, c.r, c.g, c.b));
}

void screen_sdl::handle_events() {
  while (SDL_PollEvent(&m_event)) {
    if (m_event.type == SDL_QUIT) {
      need_exit = true;
    }

    if (m_event.type == SDL_KEYDOWN) {
      if (m_event.key.keysym.sym == SDLK_ESCAPE) {
        need_exit = true;
      }
    }
  }
}

}  // namespace game_life
