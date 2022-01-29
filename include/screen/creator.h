#pragma once

#include <screen.h>

#include <memory>

namespace game_life {

class abstract_screen_creator {
 public:
  abstract_screen_creator() {}
  virtual ~abstract_screen_creator() {}
  virtual std::unique_ptr<screen> create() const = 0;
};

template <class Specific_Scr>
class screen_creator : public abstract_screen_creator {
 public:
  virtual std::unique_ptr<screen> create() const {
    return std::make_unique<Specific_Scr>();
  }
};

}  // namespace game_life
