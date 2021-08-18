#include <screen_cli.h>

#include <fmt/core.h>

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
                                fmt::print("{}", m_life);
                        } else {
                                fmt::print("{}", m_dead);
                        }
                }
                print_vboards();
                fmt::print("\n");
        }
        print_hboards();
}

void screen_cli::clear()
{
        /* Clear screem. This workis for Linux and Windows */
        fmt::print("\033[2J\033[1;1H");
}

void screen_cli::print_vboards()
{
        fmt::print("{}", m_vboard);
}

void screen_cli::print_hboards()
{
        print_vboards();
        for (int i = 0; i < m_width; ++i) {
                fmt::print("{}", m_hboard);
        }
        print_vboards();
        fmt::print("\n");
}

} // game_m_life
