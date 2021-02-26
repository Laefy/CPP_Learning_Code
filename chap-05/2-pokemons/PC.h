#pragma once

#include "Pokemon.h"

#include <algorithm>
#include <vector>

class PC
{
public:
    void transfer(Pokemon* pokemon) { _stored_pokemons.emplace_back(pokemon); }

    void remove(const Pokemon* pokemon)
    {
        release(pokemon);
        delete pokemon;
    }

    void release(const Pokemon* pokemon)
    {
        auto it = std::find(_stored_pokemons.begin(), _stored_pokemons.end(), pokemon);
        if (it != _stored_pokemons.end())
        {
            _stored_pokemons.erase(it);
        }
    }

private:
    std::vector<Pokemon*> _stored_pokemons;
};
