#pragma once

#include <string>
#include <string_view>

class Pokemon
{
public:
    Pokemon(std::string_view name, int level = 0)
        : _name { name }
        , _level { level }
    {
    }

    const std::string& get_name() const { return _name; }
    int get_level() const { return _level; }

    void level_up() { ++_level; }

    friend bool operator==(const Pokemon* pokemon, std::string_view name)
    {
        return pokemon->_name == name;
    }

private:
    const std::string _name;
    int _level = 0;
};