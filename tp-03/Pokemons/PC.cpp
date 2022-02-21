#include "PC.h"

#include "Trainer.h"

#include <memory>

void PC::give_back(Trainer& trainer, std::string const& name)
{
    for (auto i = _pokemons.begin(); i != _pokemons.end(); ++i)
    {
        if ((*i)->name() == name && (*i)->trainer() == &trainer)
        {
            std::unique_ptr<Pokemon> pokemon = std::move(*i);
            _pokemons.erase(i);
            trainer.capture(std::move(pokemon));
            break;
        }
    }
}