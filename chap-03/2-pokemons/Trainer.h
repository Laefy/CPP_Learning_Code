#pragma once

#include "PC.h"
#include "Pokedex.h"
#include "Pokemon.h"

#include <algorithm>
#include <array>
#include <functional>
#include <string>
#include <string_view>

class Trainer
{
public:
    Trainer(std::string_view name)
        : _name { name }
    {}

    int get_level() const
    {
        const auto* pokemon = get_first_pokemon();
        return pokemon ? pokemon->get_level() : 0;
    }

    const Pokedex& get_pokedex() const { return _pokedex; }

    std::vector<std::reference_wrapper<Pokemon>> get_pokemons() const
    {
        std::vector<std::reference_wrapper<Pokemon>> pokemons;

        for (auto& t : _team)
        {
            if (t != nullptr)
            {
                pokemons.emplace_back(*t);
            }
        }

        return pokemons;
    }

    [[nodiscard]] std::vector<std::unique_ptr<Pokemon>> give_pokemons()
    {
        std::vector<std::unique_ptr<Pokemon>> pokemons;

        for (auto& t : _team)
        {
            if (t != nullptr)
            {
                auto& ptr = pokemons.emplace_back();
                std::swap(t, ptr);
            }
        }

        return pokemons;
    }

    void collect(std::unique_ptr<Pokemon> pokemon)
    {
        if (auto* fighter = get_first_pokemon())
        {
            fighter->level_up();
        }

        _pokedex.add(*pokemon);

        if (!add_to_team(pokemon))
        {
            _pc.transfer(std::move(pokemon));
        }
    }

    void remove(const Pokemon& pokemon)
    {
        _pokedex.remove(pokemon);

        if (!remove_from_team(pokemon))
        {
            // We can now clearly see that we only need to check the PC if the pokemon is not already in the
            // team.
            _pc.remove(pokemon);
        }
    }

    void transfer_team_to_pc()
    {
        for (auto& pokemon : give_pokemons())
        {
            _pc.transfer(std::move(pokemon));
        }
    }

    void release_duplicates()
    {
        auto duplicated = _pokedex.get_duplicated();
        for (auto& pokemon : duplicated)
        {
            // Remove already delegates to all the right components (team / pc / pokedex).
            remove(pokemon);
        }
    }

private:
    Pokemon* get_first_pokemon() const
    {
        for (auto& t : _team)
        {
            if (t != nullptr)
            {
                return t.get();
            }
        }

        return nullptr;
    }

    bool add_to_team(std::unique_ptr<Pokemon>& pokemon)
    {
        for (auto& t : _team)
        {
            if (t == nullptr)
            {
                std::swap(t, pokemon);
                return true;
            }
        }

        return false;
    }

    bool remove_from_team(const Pokemon& pokemon)
    {
        auto it = std::find_if(_team.begin(), _team.end(),
                               [&pokemon](const auto& p) { return p.get() == &pokemon; });
        if (it != _team.end())
        {
            it->reset();
            return true;
        }

        return false;
    }

    const std::string _name;

    PC                                      _pc;
    Pokedex                                 _pokedex;
    std::array<std::unique_ptr<Pokemon>, 6> _team { nullptr };
};
