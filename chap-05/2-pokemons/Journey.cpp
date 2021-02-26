#include "PC.h"
#include "PokeCenter.h"
#include "Pokedex.h"
#include "Pokemon.h"
#include "ProfessorOak.h"
#include "Trainer.h"

#include <cstdlib>
#include <ctime>

Pokemon* random_encounter()
{
    switch (rand() % 4)
    {
    case 0:
        return new Pokemon { "Magikarp", rand() % 4 };
    case 1:
        return new Pokemon { "Caterpie", 1 + rand() % 2 };
    case 2:
        return new Pokemon { "Psyduck", 6 + rand() % 12 };
    case 3:
        return new Pokemon { "Jigglypuff", 4 + rand() % 7 };
    default:
        return nullptr;
    }
}

bool try_capture(const Trainer& trainer, const Pokemon* encounter)
{
    return (rand() % 3) * trainer.get_level() > encounter->get_level();
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    PokeCenter pokecenter;

    PC pc1;
    PC pc2;
    PC pc3;

    Trainer red { "Ash" };
    Trainer blue { "Blue" };
    Trainer some_guy { "Whatever" };
    Trainer some_girl { "Nevermind" };

    ProfessorOak oak;
    some_guy.collect(oak.get_starter());
    blue.collect(oak.get_starter());
    some_girl.collect(oak.get_starter());
    red.collect(oak.get_starter());

    Pokedex red_pokedex;
    Pokedex blue_pokedex;

    for (auto i = 0; i < 32; ++i)
    {
        auto* encounter = random_encounter();

        if (!red_pokedex.has_duplicate(encounter) && try_capture(red, encounter))
        {
            red_pokedex.add(encounter);
            if (!red.collect(encounter))
            {
                pc1.transfer(encounter);
            }
        }
        else if (try_capture(blue, encounter))
        {
            blue_pokedex.add(encounter);
            if (!blue.collect(encounter))
            {
                pc2.transfer(encounter);
            }
        }
        else
        {
            red.remove(encounter);
            blue.remove(encounter);
            delete encounter;
        }
    }

    pokecenter.heal(red.get_pokemons());

    const auto traumatized = pokecenter.get_traumatized();
    for (auto* pokemon : traumatized)
    {
        red_pokedex.remove(pokemon);
        blue_pokedex.remove(pokemon);
        red.remove(pokemon);
        blue.remove(pokemon);
        pc1.remove(pokemon);
        pc2.remove(pokemon);
    }

    for (auto* pokemon : blue.give_pokemons())
    {
        pc2.transfer(pokemon);
    }

    auto duplicated = blue_pokedex.get_duplicated();
    for (auto* pokemon : duplicated)
    {
        red.remove(pokemon);
        blue.remove(pokemon);
        pc2.remove(pokemon);
    }

    for (auto* pokemon : some_girl.give_pokemons())
    {
        if (!red.collect(pokemon))
        {
            pc1.transfer(pokemon);
        }
    }

    for (auto* pokemon : some_guy.give_pokemons())
    {
        pc3.release(pokemon);
        delete pokemon;
    }

    return 0;
}
