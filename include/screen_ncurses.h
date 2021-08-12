#pragma once

#include <screen.h>
#include <ncurses.h>

namespace game_life
{

class screen_ncurses : public screen
{
public:
        screen_ncurses(int w, int h, int life_prob);
        ~screen_ncurses();

        void show();

private:
        static constexpr inline char life = 'X';
        static constexpr inline char dead = ' ';
        static constexpr inline char vboard = '|';
        static constexpr inline char hboard = '-';
        static constexpr inline char corner = '+';

        WINDOW *game_win;

        void create_window();
};

};
