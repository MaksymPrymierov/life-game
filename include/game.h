#pragma once

#include <screen_cli.h>

#include <stack>

namespace game_life
{

class game
{
public:
        game(screen_cli *s);
        ~game();

        void start();

private:
        enum class actions
        {
                life = 0,
                dead
        };

        struct action_data
        {
                actions action;
                int x;
                int y;
        };

        static constexpr const unsigned int game_cycle_delay = 100; // milliseconds
        std::stack<action_data> actions_stack;
        screen_cli *screen;

        void scan_map();
        void process_actions();
};

} // game_life
