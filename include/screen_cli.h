#pragma once

#include <vector>

namespace game_life
{

class screen_cli
{
public:
        screen_cli();
        ~screen_cli();

        void show();
        void set_pixel(int x, int y);
        void unset_pixel(int x, int y);
        
        bool get_pixel(int x, int y);
        int get_height();
        int get_width();

private:
        static constexpr const int height = 25;
        static constexpr const int width = 25;
        static constexpr const char life = 'X';
        static constexpr const char dead = ' ';
        static constexpr const char vboard = '|';
        static constexpr const char hboard = '-';

        std::vector<std::vector<char>> screen;

        void clear();
        void print_vboards();
        void print_hboards();
        
        void random_map_set();
};

} // game_life
