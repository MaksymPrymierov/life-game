#pragma once

#include <screen.h>

namespace game_life {

class abstract_screen_creator {
 public:
  abstract_screen_creator() {}
  virtual ~abstract_screen_creator() {}
  virtual screen* create() const = 0;
};

template <class Specific_Scr>
class screen_creator : public abstract_screen_creator {
 public:
  virtual screen* create() const { return new Specific_Scr(); }
};

}  // namespace game_life
