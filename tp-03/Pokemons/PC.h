#pragma once

#include "Pokemon.h"
class Trainer;

// A PC is the place where Pokemons get automagically sent when the trainer's pockets are full.
// When a Pokemon is transferred to the PC, this one takes ownership.
class PC
{
    std::vector<std::unique_ptr<Pokemon>> _pokemons;

public:
    PC() {}

    std::vector<std::unique_ptr<Pokemon>> const& pokemons() const { return _pokemons; }

    void receive(std::unique_ptr<Pokemon>&& pokemon) { _pokemons.emplace_back(std::move(pokemon)); }

    void give_back(Trainer& trainer, std::string const& name);
};
