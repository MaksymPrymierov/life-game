#include <iostream>
#include <config.h>

int main(int argc, char **argv)
{
        if (argc < 2) {
                std::cout << "Game Life Version: " <<
                        GameLife_VERSION_MAJOR << "." <<
                        GameLife_VERSION_MINOR << std::endl;
        }

        return 0;
}
