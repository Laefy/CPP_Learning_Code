#pragma once

#include "Pokemon.h"

#include <deque>

class ProfessorOak
{
public:
    Pokemon* get_starter()
    {
        if (_starters.empty())
        {
            return new Pokemon { "Pikachu", 2 };
        }

        auto* pokemon = _starters.front();
        _starters.pop_front();
        return pokemon;
    }

private:
    std::deque<Pokemon*> _starters { new Pokemon { "Bulbasaur", 2 }, new Pokemon { "Charmander", 2 }, new Pokemon { "Squirtle", 2 } };
};
