#include <screen_cli.h>

#include <iostream>

namespace game_life
{

screen_cli::screen_cli(int w, int h, int life_prob) :
        screen(w, h, life_prob)
{  }

screen_cli::~screen_cli()
{  }

void screen_cli::show()
{
        clear();
        print_hboards();

        for (int i = 0; i < this->height; ++i)
        {
                print_vboards();
                for (int j = 0; j < this->width; ++j) {
                        if (this->screen_map.at(i).at(j)) {
                                std::cout << life;
                        } else {
                                std::cout << dead;
                        }
                }
                print_vboards();
                std::cout << '\n';
        }
        print_hboards();
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
        for (int i = 0; i < this->width; ++i) {
                std::cout << hboard;
        }
        print_vboards();
        std::cout << '\n';
}

} // game_life
