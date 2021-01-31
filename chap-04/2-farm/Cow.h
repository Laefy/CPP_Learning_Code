#pragma once

#include <iostream>

class Cow : public Animal
{
public:
    void sing(char next_char) const override { std::cout << "Mewwwwwh" << next_char; }
};
