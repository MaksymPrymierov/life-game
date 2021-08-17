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

        void show() override;

private:
        static constexpr inline char m_life = 'X';
        static constexpr inline char m_dead = ' ';
        static constexpr inline char m_vboard = '|';
        static constexpr inline char m_hboard = '-';
        static constexpr inline char m_corner = '+';

        WINDOW *m_game_win;

        void create_window();
};

};
