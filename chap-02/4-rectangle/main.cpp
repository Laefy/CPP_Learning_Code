#include "Rectangle.h"

#include <iostream>

int main() {
    Rectangle rect(2.f, 4.f);
    std::cout << rect << std::endl;

    rect.scale(3);
    std::cout << rect << std::endl;

    Rectangle square(2.5f);

    Rectangle c1;
    Rectangle::set_default_size(2.f);
    Rectangle c2;

    return 0;
}
