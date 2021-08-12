#include <screen.h>

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
        if (y < height && y >= 0 && x < width && x >= 0) {
                screen_map[y][x] = true;
        }
}

void screen::unset_pixel(int x, int y)
{  
        if (y < height && y >= 0 && x < width && x >= 0) {
                screen_map[y][x] = false;
        }
}

bool screen::get_pixel(int x, int y)
{  
        if (y < height && y >= 0 && x < width && x >= 0) {
                return screen_map[y][x];
        }

        return false;
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
        for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width; ++j) {
                        if (rd_values(rd) > life_probability) {
                                screen_map[i][j] = false;
                        } else {
                                screen_map[i][j] = true;
                        }
                }
        }
}

};
