#pragma once

#include <iostream>

class Cat : public Animal
{
public:
    void sing(char next_char) const override { std::cout << "Meow" << next_char; }
};
