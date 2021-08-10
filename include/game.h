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
        enum class action
        {
                life = 0,
                dead
        };

        struct action_data
        {
                action a;
                int x;
                int y;
        };

        screen_cli *screen;
};

} // game_life
