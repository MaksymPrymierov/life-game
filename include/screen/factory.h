#pragma once

#include <screen/creator.h>

#include <map>
#include <string>

namespace game_life {

class screen_factory {
 public:
  screen_factory();
  ~screen_factory();

  screen* get(std::string key);

 private:
  std::map<std::string, abstract_screen_creator*> screens;
};

}  // namespace game_life
