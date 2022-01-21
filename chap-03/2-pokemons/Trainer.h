#pragma once

#include "Pokemon.h"

#include <algorithm>
#include <array>
#include <string>
#include <string_view>

class Trainer
{
public:
    Trainer(std::string_view name)
        : _name { name }
    {
    }

    int get_level() const
    {
        for (auto* t : _team)
        {
            if (t != nullptr)
            {
                return t->get_level();
            }
        }

        return 0;
    }

    std::vector<Pokemon*> get_pokemons() const
    {
        std::vector<Pokemon*> pokemons;

        for (auto* t : _team)
        {
            if (t != nullptr)
            {
                pokemons.emplace_back(t);
            }
        }

        return pokemons;
    }

    std::vector<Pokemon*> give_pokemons()
    {
        auto pokemons = get_pokemons();
        _team.fill(nullptr);
        return pokemons;
    }

    bool collect(Pokemon* pokemon)
    {
        for (auto* t : _team)
        {
            if (t != nullptr)
            {
                t->level_up();
                continue;
            }
        }

        for (auto& t : _team)
        {
            if (t == nullptr)
            {
                t = pokemon;
                return true;
            }
        }

        return false;
    }

    void remove(const Pokemon* pokemon)
    {
        auto it = std::find(_team.begin(), _team.end(), pokemon);
        if (it != _team.end())
        {
            *it = nullptr;
        }
    }

private:
    const std::string _name;
    std::array<Pokemon*, 6> _team;
};
