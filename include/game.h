#pragma once

#include <screen.h>

#include <stack>

namespace game_life
{

class game
{
public:
        game(screen *s);
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

        static constexpr inline unsigned int game_cycle_delay = 100; // milliseconds
        std::stack<action_data> actions_stack;
        screen *screen_;

        void scan_map();
        void process_actions();
};

} // game_life
