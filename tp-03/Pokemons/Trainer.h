#pragma once

#include "PC.h"
#include "Pokeball.h"

#include <array>
#include <memory>
#include <string>
#include <utility>

// A person that capture Pokemons and make them fight.
class Trainer
{
public:
    Trainer(const std::string& name, PC& pc)
        : _name { name }
        , _pc { pc }
    {}

    const std::string& name() const { return _name; }

    const std::array<Pokeball, 6>& pokeballs() const { return _pokeballs; }

    void capture(std::unique_ptr<Pokemon> pokemon)
    {
        pokemon->captured_by(*this);

        for (auto& pokeball : _pokeballs)
        {
            if (pokeball.empty())
            {
                pokeball.store(std::move(pokemon));
                return;
            }
        }

        _pc.receive(std::move(pokemon));
    }

private:
    std::string _name;
    PC&         _pc;

    std::array<Pokeball, 6> _pokeballs;
};
