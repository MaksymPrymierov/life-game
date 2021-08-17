#include <iostream>

#include <game.h>
#include <config.h>
#include <screen_cli.h>
#include <screen_ncurses.h>

int main()
{
        int w;
        int h;
        int l = -1;
        int s;
        game_life::screen *screen;
        game_life::game   *game;

        std::cout << "Game Life Version: " <<
                GameLife_VERSION_MAJOR << "." <<
                GameLife_VERSION_MINOR << std::endl;

        std::cout << "Enter the height of the map: ";
        std::cin >> h;

        std::cout << "Enter the width of the map: ";
        std::cin >> w;

        while (l < 0 || l > 100) {
                std::cout << "Enter the life probability [0-100]: ";
                std::cin >> l;
        }

        std::cout << "Enter the screen mod\n1) native terminal\n2) ncurses\n> ";
        std::cin >> s;
        switch (s) {
        case 1:
                screen = new game_life::screen_cli(w, h, l);
                break;
        case 2:
                screen = new game_life::screen_ncurses(w, h, l);
                break;
        default:
                std::cout << "Error: Unknown screen" << std::endl;
                return -1;
        }

        game = new game_life::game(screen);
        game->start();

        return 0;
}
