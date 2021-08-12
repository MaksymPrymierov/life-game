#include <iostream>

#include <game.h>
#include <config.h>
#include <screen_cli.h>

int main()
{
        int w;
        int h;
        int l = -1;

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

        game_life::screen_cli screen(w, h, l);
        game_life::game game(&screen);

        screen.show();
        game.start();

        return 0;
}
