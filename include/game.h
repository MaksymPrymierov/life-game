#pragma once

#include <screen_cli.h>

namespace game_life
{

class game
{
public:
        game(screen_cli *s);
        ~game();

        void start();

private:
        screen_cli *screen;
};

} // game_life
