#pragma once

#include <vector>

// Pokemon are automatically stored there if the trainer doesn't have enough space on them.
class PC
{
public:
    std::vector<int> pokemons() const { return _pokemons; }

private:
    std::vector<int> _pokemons;
};
