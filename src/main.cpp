#include <iostream>

#include <game.h>
#include <config.h>
#include <screen_cli.h>

int main()
{
        std::cout << "Game Life Version: " <<
                GameLife_VERSION_MAJOR << "." <<
                GameLife_VERSION_MINOR << std::endl;

        game_life::screen_cli screen;
        game_life::game game(&screen);

        screen.show();
        game.start();

        return 0;
}
