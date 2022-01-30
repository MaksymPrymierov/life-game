#include <screen/factory.h>
#include <screen_cli.h>
#include <screen_ncurses.h>
#include <screen_sdl.h>

namespace game_life {

screen_factory::screen_factory() {
  m_screen_creators["cli"] = std::make_unique<screen_creator<screen_cli>>();
  m_screen_creators["ncurses"] =
      std::make_unique<screen_creator<screen_ncurses>>();
  m_screen_creators["sdl"] = std::make_unique<screen_creator<screen_sdl>>();
}

screen_factory::~screen_factory() {}

std::unique_ptr<screen> screen_factory::get(const std::string& key) {
  return m_screen_creators[key]->create();
}

}  // namespace game_life
