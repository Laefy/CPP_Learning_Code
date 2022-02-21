#pragma once

#include "PC.h"
#include "Pokeball.h"

// A person that capture Pokemons and make them fight.
class Trainer
{
private:
    std::string           _name;
    PC&                   _pc;
    std::vector<Pokeball> _pokeballs = std::vector<Pokeball>(6);

public:
    Trainer(std::string name, PC& pc)
        : _name(std::move(name))
        , _pc(pc)
    {}

    std::string const&           name() const { return _name; }
    std::vector<Pokeball> const& pokeballs() const { return _pokeballs; }
    void                         capture(std::unique_ptr<Pokemon>&& pokemon);
    void                         store_in_pc(int i) { _pc.receive(_pokeballs[i].release()); }
};
