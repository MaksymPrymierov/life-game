#pragma once

#include <screen/creator.h>

#include <map>
#include <memory>
#include <string>

namespace game_life {

class screen_factory {
 public:
  screen_factory();
  ~screen_factory();

  std::unique_ptr<screen> get(const std::string& key);

 private:
  std::map<std::string, std::unique_ptr<abstract_screen_creator>>
      m_screen_creators;
};

}  // namespace game_life
