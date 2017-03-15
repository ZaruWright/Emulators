#include <emulators/chip8/chip8.hpp>
#include <string>
#include <iostream>

void help()
{
    std::cout << "Usage: " << std::endl
              << "./chip8UrlExecutable UrlOfGame" << std::endl;
}

int main(int argc, char **argv)
{
    bool error = false;
    std::string gameUrl;

    if (argc == 2)
    {
        if (argv[1] == std::string("-h") || argv[1] == std::string("--help"))
        {
            help();
            error = true;
        }
        else
        {
            gameUrl = argv[1];
        }
    }
    else
    {
        help();
        error = true;
    }

    if (!error)
    {
        emulators::chip8::Chip8 c8;
        c8.play(std::string(gameUrl));
    }

    return 0;
}