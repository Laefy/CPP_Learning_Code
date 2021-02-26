#pragma once

#include "Pokemon.h"

#include <deque>
#include <memory>
#include <utility>

class ProfessorOak
{
public:
    ProfessorOak()
    {
        _starters.emplace_back(std::make_unique<Pokemon>("Bulbasaur", 2));
        _starters.emplace_back(std::make_unique<Pokemon>("Charmander", 2));
        _starters.emplace_back(std::make_unique<Pokemon>("Squirtle", 2));
    }

    [[nodiscard]] std::unique_ptr<Pokemon> get_starter()
    {
        if (_starters.empty())
        {
            return std::make_unique<Pokemon>("Pikachu", 2);
        }

        std::unique_ptr<Pokemon> pokemon;
        std::swap(pokemon, _starters.front());
        _starters.pop_front();
        return pokemon;
    }

private:
    std::deque<std::unique_ptr<Pokemon>> _starters;
};
