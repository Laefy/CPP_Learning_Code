#pragma once

#include "Pokemon.h"

#include <algorithm>
#include <memory>
#include <utility>
#include <vector>

class PC
{
public:
    void transfer(std::unique_ptr<Pokemon> pokemon) { _stored_pokemons.emplace_back(std::move(pokemon)); }

    void remove(const Pokemon& pokemon) { auto to_destroy = release(pokemon); }

    [[nodiscard]] std::unique_ptr<Pokemon> release(const Pokemon& pokemon)
    {
        std::unique_ptr<Pokemon> result;

        auto it = std::find_if(_stored_pokemons.begin(), _stored_pokemons.end(),
                               [&pokemon](const auto& p) { return p.get() == &pokemon; });
        if (it != _stored_pokemons.end())
        {
            std::swap(result, *it);
            _stored_pokemons.erase(it);
        }

        return result;
    }

private:
    std::vector<std::unique_ptr<Pokemon>> _stored_pokemons;
};
