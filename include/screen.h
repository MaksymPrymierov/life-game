#pragma once

#include <vector>
#include <random>

namespace game_life
{

class screen
{
public:
        screen(int w, int h, int life_prob);
        ~screen();

        virtual void show();
        void set_pixel(int x, int y);
        void unset_pixel(int x, int y);

        bool get_pixel(int x, int y);
        int get_height();
        int get_width();

protected:
        int height;
        int width;
        int life_probability;
        std::random_device rd;
        std::uniform_int_distribution<int> rd_values{0, 100};
        std::vector<std::vector<bool>> screen_map;

        void random_map_set();
};

} // game_life
