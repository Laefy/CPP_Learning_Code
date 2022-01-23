#include "PC.h"

#include "Trainer.h"

void PC::give_back(Trainer& trainer, const std::string& name)
{
    for (auto it = _pokemons.begin(); it != _pokemons.end(); ++it)
    {
        auto& pokemon = *it;

        if (pokemon->trainer() == &trainer && pokemon->name() == name)
        {
            trainer.capture(std::move(pokemon));
            _pokemons.erase(it);

            return;
        }
    }
}