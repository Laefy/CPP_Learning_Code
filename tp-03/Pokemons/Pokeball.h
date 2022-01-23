#pragma once

#include "Pokemon.h"

#include <memory>
#include <utility>

// A ball where Pokemon sleep.
class Pokeball
{
public:
    bool     empty() const { return _pokemon == nullptr; }
    Pokemon& pokemon() const { return *_pokemon; }

    void store(std::unique_ptr<Pokemon> pokemon) { _pokemon = std::move(pokemon); }

private:
    std::unique_ptr<Pokemon> _pokemon;
};