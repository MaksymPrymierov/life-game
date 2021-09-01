#include <iostream>
#include <fmt/core.h>
#include <fmt/format.h>

#include <game.h>
#include <config.h>
#include <screen_cli.h>
#include <screen_ncurses.h>

int main()
{
        int s;
        game_life::screen *screen;
        game_life::game   *game;

        fmt::print("Game Life Version: {}.{}\n", GameLife_VERSION_MAJOR, GameLife_VERSION_MINOR);

        fmt::print("Enter the screen mod\n1) native terminal\n2) ncurses\n> ");
        std::cin >> s;
        switch (s) {
        case 1:
                screen = new game_life::screen_cli;
                break;
        case 2:
                screen = new game_life::screen_ncurses;
                break;
        default:
                fmt::system_error(EINVAL, "Error: Unknown screen");
                return -1;
        }

        screen->start();
        game = new game_life::game(screen);
        game->start();

        return 0;
}
