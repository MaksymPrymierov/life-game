#pragma once

#include <vector>
#include <random>

namespace game_life
{

class screen
{
public:
        screen() = default;
        screen(int w, int h, int life_prob);
        virtual ~screen() = default;

        virtual void start();
        virtual void show() = 0;

        void set_pixel(int x, int y);
        void unset_pixel(int x, int y);

        bool get_pixel(int x, int y);
        int get_height();
        int get_width();

protected:
        int m_height;
        int m_width;
        int m_life_probability;
        std::random_device m_rd;
        std::uniform_int_distribution<int> m_rd_values{0, 100};
        std::vector<std::vector<bool>> m_screen_map;

        void random_map_set();
};

} // game_life
