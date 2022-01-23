#pragma once

#include "Pokeball.h"

#include <array>
#include <string>

class PC;

// A person that capture Pokemons and make them fight.
class Trainer
{
public:
    Trainer(const std::string& name, PC&)
        : _name { name }
    {}

    const std::string& name() const { return _name; }

    const std::array<Pokeball, 6>& pokeballs() const { return _pokeballs; }

private:
    std::string             _name;
    std::array<Pokeball, 6> _pokeballs;
};
