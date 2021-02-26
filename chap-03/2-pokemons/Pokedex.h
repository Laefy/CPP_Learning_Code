#pragma once

#include "Pokemon.h"

#include <algorithm>
#include <vector>

class Pokedex
{
public:
    void add(const Pokemon& pokemon) { _pokemons.emplace_back(pokemon); }

    void remove(const Pokemon& pokemon)
    {
        auto it = std::find_if(_pokemons.begin(), _pokemons.end(),
                               [&pokemon](const Pokemon& p) { return &pokemon == &p; });
        if (it != _pokemons.end())
        {
            _pokemons.erase(it);
        }
    }

    bool has_duplicate(const Pokemon& pokemon) const
    {
        auto it = std::find(_pokemons.begin(), _pokemons.end(), pokemon.get_name());
        return (it != _pokemons.end());
    }

    std::vector<std::reference_wrapper<const Pokemon>> get_duplicated() const
    {
        std::vector<std::reference_wrapper<const Pokemon>> result;

        for (auto it = _pokemons.begin(); it != _pokemons.end(); ++it)
        {
            auto duplicated = std::find(it + 1, _pokemons.end(), it->get().get_name());
            if (duplicated != _pokemons.end())
            {
                result.emplace_back(*duplicated);
            }
        }

        return result;
    }

private:
    std::vector<std::reference_wrapper<const Pokemon>> _pokemons;
};