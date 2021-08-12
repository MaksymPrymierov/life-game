#include <screen_cli.h>

#include <iostream>

namespace game_life
{

screen_cli::screen_cli(int w, int h) :
        height(h),
        width(w)
{
        screen.resize(height);
        for (auto &i : screen) {
                i.resize(static_cast<std::size_t>(width));
        }
        random_map_set();
}

screen_cli::~screen_cli()
{
        for (auto &i : screen) {
                i.clear();
        }
        screen.clear();
}

void screen_cli::show()
{
        clear();
        print_hboards();

        for (auto &i : screen) {
                print_vboards();
                for (auto &j : i) {
                        std::cout << j;
                }
                print_vboards();
                std::cout << '\n';
        }
        print_hboards();
}

void screen_cli::unset_pixel(int x, int y)
{
        try {
                screen.at(y).at(x) = dead;
        } catch (const std::out_of_range &d) {
                return;
        }
}

void screen_cli::set_pixel(int x, int y)
{
        try {
                screen.at(y).at(x) = life;
        } catch (const std::out_of_range &d) {
                return;
        }
}

bool screen_cli::get_pixel(int x, int y)
{
        try {
                if (screen.at(y).at(x) == life) {
                        return true;
                }
        } catch (const std::out_of_range &d) {
                return false;
        }

        return false;
}

int screen_cli::get_width()
{
        return width;
}

int screen_cli::get_height()
{
        return height;
}

void screen_cli::clear()
{
        /* Clear screem. This workis for Linux and Windows */
        std::cout << "\033[2J\033[1;1H";
}

void screen_cli::print_vboards()
{
        std::cout << vboard;
}

void screen_cli::print_hboards()
{
        print_vboards();
        for (unsigned i = 0; i < width; ++i) {
                std::cout << hboard;
        }
        print_vboards();
        std::cout << '\n';
}

void screen_cli::random_map_set()
{
        srand(time(NULL));
        for (auto &i : screen) {
                for (auto &j : i) {
                        if (rand() % 100 > 10) {
                                j = dead;
                        } else {
                                j = life;
                        }
                }
        }
}

} // game_life
