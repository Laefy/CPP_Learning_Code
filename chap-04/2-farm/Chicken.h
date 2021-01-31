#pragma once

#include <iostream>

class Chicken : public Animal
{
public:
    ~Chicken() { std::cout << "CotCooooooooot!" << std::endl; }

    void sing(char next_char) const override { std::cout << "Cotcotcotcodet" << next_char; }
};
