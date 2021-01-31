#pragma once

#include <iostream>

class Animal
{
public:
    virtual ~Animal() {}

    virtual void sing(char next_char) const { std::cout << "..." << next_char; }
};
