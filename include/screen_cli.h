#pragma once

#include <screen.h>

namespace game_life
{

class screen_cli : public screen
{
public:
        screen_cli(int x, int y, int life_prob);
        ~screen_cli();

        void show() override;

private:
        static constexpr inline char m_life = 'X';
        static constexpr inline char m_dead = ' ';
        static constexpr inline char m_vboard = '|';
        static constexpr inline char m_hboard = '-';

        void clear();
        void print_vboards();
        void print_hboards();
};

} // game_life
