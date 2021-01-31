#pragma once

#include <iostream>

class Dog : public Animal
{
public:
    void sing(char next_char) const override { std::cout << "Waf" << next_char; }
};
