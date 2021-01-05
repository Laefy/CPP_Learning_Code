#include "Rectangle.h"

#include <iostream>

int main()
{
    Rectangle rect(2.f, 4.f);
    std::cout << rect << std::endl;

    rect.scale(3);
    std::cout << rect << std::endl;

    Rectangle square_1(2.5f);
    std::cout << square_1 << std::endl;

    Rectangle square_2;
    std::cout << square_2 << std::endl;

    Rectangle::set_default_size(7.f);

    Rectangle square_3;
    std::cout << square_3 << std::endl;

    return 0;
}
