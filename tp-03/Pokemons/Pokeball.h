#pragma once

#include "Pokemon.h"

// A ball where Pokemon sleep.
class Pokeball
{
    std::unique_ptr<Pokemon> _pokemon;

public:
    Pokeball() {}

    void store(std::unique_ptr<Pokemon>&& pokemon) { _pokemon = std::move(pokemon); }

    bool empty() const { return !(bool)_pokemon; }

    Pokemon const& pokemon() const { return *_pokemon; }

    std::unique_ptr<Pokemon> release()
    {
        std::unique_ptr<Pokemon> old_pokemon = std::move(_pokemon);
        _pokemon.reset();
        return old_pokemon;
    }
};