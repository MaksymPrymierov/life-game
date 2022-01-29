#pragma once

#include <SDL2/SDL.h>
#include <screen.h>

#include <memory>

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

  static constexpr const unsigned int m_screen_width = 1280;
  static constexpr const unsigned int m_screen_height = 720;
  static constexpr const unsigned int m_cell_width = 20;
  static constexpr const unsigned int m_cell_height = 20;
  static constexpr const unsigned int m_game_screen_width = 64;
  static constexpr const unsigned int m_game_screen_height = 36;
  static constexpr const unsigned int m_game_life_probability = 25;

  const color m_dead_color = {0, 153, 153};
  const color m_life_color = {255, 135, 0};

  SDL_Event m_event;
  SDL_Surface* m_background_surface_ptr;
  SDL_Window* m_window_ptr;
  std::unique_ptr<SDL_Rect> m_cell_ptr;

  void set_background();
  void update();
  void set_cell(unsigned int x, unsigned int y, color c);
  void handle_events();
};

}  // namespace game_life
