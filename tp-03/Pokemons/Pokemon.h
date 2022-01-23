#pragma once

#include <string>

// A creature that is cute and can fight other ones.
class Pokemon
{
public:
    Pokemon(const std::string& name)
        : _name { name }
    {}

    const std::string& name() const { return _name; }

private:
    std::string _name;
};
