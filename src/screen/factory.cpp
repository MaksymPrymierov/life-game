#include <screen/factory.h>
#include <screen_cli.h>
#include <screen_ncurses.h>
#include <screen_sdl.h>

namespace game_life {

screen_factory::screen_factory() {
  screens["cli"] = new screen_creator<screen_cli>;
  screens["ncurses"] = new screen_creator<screen_ncurses>;
  screens["sdl"] = new screen_creator<screen_sdl>;
}

screen_factory::~screen_factory() {
  for (const auto& i : screens) {
    delete std::get<abstract_screen_creator*>(i);
  }
}

screen* screen_factory::get(std::string key) { return screens[key]->create(); }

}  // namespace game_life
