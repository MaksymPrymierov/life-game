#pragma once

#include <screen.h>

namespace game_life
{

class screen_cli : public screen
{
public:
        screen_cli(int x, int y, int life_prob);
        ~screen_cli();

        void show();

private:
        static constexpr inline char life = 'X';
        static constexpr inline char dead = ' ';
        static constexpr inline char vboard = '|';
        static constexpr inline char hboard = '-';

        void clear();
        void print_vboards();
        void print_hboards();
};

} // game_life
