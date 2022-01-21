#include "Model.h"
#include "Texture.h"

#include <iostream>
#include <string>

int main()
{
    Model::Container models;

    auto quit = false;
    while (!quit)
    {
        std::cout << "Enter a command (h for help): ";
        std::cout.flush();

        std::string command;
        std::cin >> command;

        if (command == "h")
        {
            std::cout << "- h: help\n"
                      << "- c: create a model\n"
                      << "- d: destroy a model\n"
                      << "- p: print the number of textures currently loaded\n"
                      << "- q: quit the program" << std::endl;
        }
        else if (command == "c")
        {
            Model::Create(models);
        }
        else if (command == "d")
        {
            Model::Destroy(models);
        }
        else if (command == "p")
        {
            std::cout << "There are " << Texture::Count() << " Texture(s) currently loaded." << std::endl;
        }
        else if (command == "q")
        {
            quit = true;
        }
        else
        {
            std::cerr << "Command '" << command << "' is unknown." << std::endl;
        }
    }

    return 0;
}