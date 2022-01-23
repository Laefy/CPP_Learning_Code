#pragma once

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

private:
    std::string _name;
};
