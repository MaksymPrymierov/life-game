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

        for (int i = 0; i < m_height; ++i)
        {
                print_vboards();
                for (int j = 0; j < m_width; ++j) {
                        if (m_screen_map.at(i).at(j)) {
                                std::cout << m_life;
                        } else {
                                std::cout << m_dead;
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
        std::cout << m_vboard;
}

void screen_cli::print_hboards()
{
        print_vboards();
        for (int i = 0; i < m_width; ++i) {
                std::cout << m_hboard;
        }
        print_vboards();
        std::cout << '\n';
}

} // game_m_life
