#pragma once

#include "Pokemon.h"

#include <memory>
#include <vector>

// Pokemon are automatically stored there if the trainer doesn't have enough space on them.
class PC
{
public:
    const std::vector<std::unique_ptr<Pokemon>>& pokemons() const { return _pokemons; }

    void receive(std::unique_ptr<Pokemon> pokemon) { _pokemons.emplace_back(std::move(pokemon)); }

private:
    std::vector<std::unique_ptr<Pokemon>> _pokemons;
};
