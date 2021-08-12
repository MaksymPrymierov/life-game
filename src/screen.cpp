#include <screen.h>

#include <stdexcept>

namespace game_life
{

screen::screen(int w, int h, int life_prob) :
        height(h),
        width(w),
        life_probability(life_prob)
{  
        screen_map.resize(height);
        for (auto &i : screen_map) {
                i.resize(static_cast<std::size_t>(width));
        }
        random_map_set();
}

screen::~screen()
{  
        for (auto &i : screen_map) {
                i.clear();
        }
        screen_map.clear();
}

void screen::show()
{  
        /* Abstract Method */
}

void screen::set_pixel(int x, int y)
{  
        try {
                screen_map.at(y).at(x) = true;
        } catch (const std::out_of_range &d) {
                return;
        }
}

void screen::unset_pixel(int x, int y)
{  
        try {
                screen_map.at(y).at(x) = false;
        } catch (const std::out_of_range &d) {
                return;
        }
}

bool screen::get_pixel(int x, int y)
{  
        try {
                return screen_map.at(y).at(x);
        } catch (const std::out_of_range &d) {
                return false;
        }
}

int screen::get_height()
{
        return height;
}

int screen::get_width()
{
        return width;
}

void screen::random_map_set()
{
        srand(time(NULL));
        for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width; ++j) {
                        if (rand() % 100 > life_probability) {
                                screen_map.at(i).at(j) = false;
                        } else {
                                screen_map.at(i).at(j) = true;
                        }
                }
        }
}

};
