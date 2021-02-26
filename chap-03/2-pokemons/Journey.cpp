#include "PC.h"
#include "PokeCenter.h"
#include "Pokedex.h"
#include "Pokemon.h"
#include "ProfessorOak.h"
#include "Trainer.h"

#include <cstdlib>
#include <ctime>
#include <memory>
#include <utility>

[[nodiscard]] std::unique_ptr<Pokemon> random_encounter()
{
    switch (rand() % 4)
    {
    case 0:
        return std::make_unique<Pokemon>("Magikarp", rand() % 4);
    case 1:
        return std::make_unique<Pokemon>("Caterpie", 1 + rand() % 2);
    case 2:
        return std::make_unique<Pokemon>("Psyduck", 6 + rand() % 12);
    case 3:
        return std::make_unique<Pokemon>("Jigglypuff", 4 + rand() % 7);
    default:
        return nullptr;
    }
}

bool try_capture(const Trainer& trainer, const Pokemon& encounter)
{
    return (rand() % 3) * trainer.get_level() > encounter.get_level();
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    PokeCenter pokecenter;

    Trainer red { "Ash" };
    Trainer blue { "Blue" };
    Trainer some_guy { "Whatever" };
    Trainer some_girl { "Nevermind" };

    ProfessorOak oak;
    some_guy.collect(oak.get_starter());
    blue.collect(oak.get_starter());
    some_girl.collect(oak.get_starter());
    red.collect(oak.get_starter());

    for (auto i = 0; i < 32; ++i)
    {
        auto encounter = random_encounter();

        if (!red.get_pokedex().has_duplicate(*encounter) && try_capture(red, *encounter))
        {
            red.collect(std::move(encounter));
        }
        else if (try_capture(blue, *encounter))
        {
            blue.collect(std::move(encounter));
        }
    }

    // TODO: make the removal of the traumatized pokemon and the healing strongly coupled.
    pokecenter.heal(red.get_pokemons());

    const auto traumatized = pokecenter.get_traumatized();
    for (auto& pokemon : traumatized)
    {
        red.remove(pokemon);
    }

    blue.transfer_team_to_pc();
    blue.release_duplicates();

    for (auto& pokemon : some_girl.give_pokemons())
    {
        red.collect(std::move(pokemon));
    }

    auto to_destroy = some_guy.give_pokemons();

    return 0;
}
