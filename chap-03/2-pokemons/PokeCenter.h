#pragma once

#include "Pokemon.h"

#include <vector>

class PokeCenter
{
public:
    void heal(const std::vector<Pokemon*>& pokemons)
    {
        for (auto* pokemon : pokemons)
        {
            if (pokemon->get_level() == 0)
            {
                _traumatized_pokemons.emplace_back(pokemon);
            }
        }
    }

    std::vector<Pokemon*> get_traumatized()
    {
        auto tmp = _traumatized_pokemons;
        _traumatized_pokemons.clear();
        return tmp;
    }

private:
    std::vector<Pokemon*> _traumatized_pokemons;
};
