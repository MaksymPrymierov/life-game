#include <screen/factory.h>
#include <screen_cli.h>
#include <screen_ncurses.h>
#include <screen_sdl.h>

namespace game_life {

screen_factory::screen_factory() {
  screens["cli"] = std::make_unique<screen_creator<screen_cli>>();
  screens["ncurses"] = std::make_unique<screen_creator<screen_ncurses>>();
  screens["sdl"] = std::make_unique<screen_creator<screen_sdl>>();
}

screen_factory::~screen_factory() {}

std::unique_ptr<screen> screen_factory::get(std::string key) {
  return screens[key]->create();
}

}  // namespace game_life
