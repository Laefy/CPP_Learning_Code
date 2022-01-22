#pragma once

#include <iostream>
#include <string>

class Cat
{
    friend std::ostream& operator<<(std::ostream& stream, const Cat& cat)
    {
        return stream << "I have a cat named " << cat._name << ".";
    }

public:
    bool operator==(const Cat& other) const { return _name == other._name; }

private:
    std::string _name = "Felix";
};