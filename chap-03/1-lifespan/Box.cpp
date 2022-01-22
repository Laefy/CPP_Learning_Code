#include "Box.h"

#include <iostream>

int main()
{
    std::cout << "box1 block begin" << std::endl;
    {
        Box box1 { "c1" };
    }
    std::cout << "box1 block end" << std::endl;

    std::cout << "----------------" << std::endl;

    std::cout << "box2 block begin" << std::endl;
    {
        Box box2 { "c2" };
    }
    std::cout << "box2 block end" << std::endl;

    return 0;
}
