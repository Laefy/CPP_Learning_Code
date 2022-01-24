#include "PC.h"
#include "Pokeball.h"
#include "Pokemon.h"
#include "Trainer.h"

#include <catch2/catch.hpp>
#include <memory>
#include <string>
#include <utility>

// TEST_CASE("Pokemons can be constructed with their name")
// {
//     Pokemon pikachu { "Pikachu" };
//     Pokemon bulbizarre { "Bulbizarre" };

//     REQUIRE(pikachu.name() == "Pikachu");
//     REQUIRE(bulbizarre.name() == "Bulbizarre");
// }

// TEST_CASE("Pokeballs are empty by default")
// {
//     Pokeball pokeball;
//     REQUIRE(pokeball.empty() == true);
// }

// TEST_CASE("Pokemons can be stored in Pokeballs")
// {
//     auto pikachu = std::make_unique<Pokemon>("Pikachu");

//     Pokeball pokeball;
//     REQUIRE(pokeball.empty() == true);

//     pokeball.store(std::move(pikachu));
//     REQUIRE(pokeball.empty() == false);

//     auto& pokemon = pokeball.pokemon();
//     REQUIRE(pokemon.name() == "Pikachu");
// }

// TEST_CASE("PCs are constructed with 0 pokemon inside")
// {
//     PC pc;

//     const auto& pokemons = pc.pokemons();
//     REQUIRE(pokemons.empty() == true);
// }

// TEST_CASE("A Pokemon can be put inside the PC")
// {
//     PC pc;

//     auto pikachu = std::make_unique<Pokemon>("Pikachu");
//     pc.receive(std::move(pikachu));

//     const auto& pokemons = pc.pokemons();
//     REQUIRE(pokemons.empty() == false);
//     REQUIRE(pokemons[0]->name() == "Pikachu");
// }

// TEST_CASE("Trainers are constructed with their name and they know the PC where their Pokemons get sent")
// {
//     PC      pc;
//     Trainer sacha { "Sacha", pc };
//     Trainer ondine { "Ondine", pc };

//     REQUIRE(sacha.name() == "Sacha");
//     REQUIRE(ondine.name() == "Ondine");
// }

// TEST_CASE("Trainers start with 6 empty pokeballs")
// {
//     PC      pc;
//     Trainer sacha { "Sacha", pc };

//     const auto& pokeballs = sacha.pokeballs();
//     REQUIRE(pokeballs.size() == 6u);

//     for (const auto& pokeball : pokeballs)
//     {
//         REQUIRE(pokeball.empty() == true);
//     }
// }

// TEST_CASE("A trainer can catch a pokemon")
// {
//     PC      pc;
//     Trainer sacha { "Sacha", pc };

//     SECTION("It goes in its next non-empty pokeball if any")
//     {
//         auto pikachu    = std::make_unique<Pokemon>("Pikachu");
//         auto bulbizarre = std::make_unique<Pokemon>("Bulbizarre");

//         const auto& pokeballs = sacha.pokeballs();

//         REQUIRE(pokeballs[0].empty() == true);
//         sacha.capture(std::move(pikachu));
//         REQUIRE(pokeballs[0].empty() == false);
//         REQUIRE(pokeballs[0].pokemon().name() == "Pikachu");

//         REQUIRE(pokeballs[1].empty() == true);
//         sacha.capture(std::move(bulbizarre));
//         REQUIRE(pokeballs[1].empty() == false);
//         REQUIRE(pokeballs[1].pokemon().name() == "Bulbizarre");
//     }

//     SECTION("If no more empty pokeballs, it goes to the PC")
//     {
//         for (auto i = 0; i < 6; ++i)
//         {
//             auto pokemon = std::make_unique<Pokemon>("Pokemon_" + std::to_string(i));
//             sacha.capture(std::move(pokemon));
//         }

//         REQUIRE(sacha.pokeballs()[5].empty() == false);
//         REQUIRE(pc.pokemons().empty() == true);

//         auto dracaufeu = std::make_unique<Pokemon>("Dracaufeu");
//         sacha.capture(std::move(dracaufeu));

//         REQUIRE(pc.pokemons().empty() == false);
//         REQUIRE(pc.pokemons()[0]->name() == "Dracaufeu");
//     }
// }

// TEST_CASE("A Pokemon knows its trainer")
// {
//     auto bulbizarre = std::make_unique<Pokemon>("Bulbizarre");
//     REQUIRE(bulbizarre->trainer() == nullptr);

//     PC      pc;
//     Trainer sacha { "Sacha", pc };

//     sacha.capture(std::move(bulbizarre));
//     REQUIRE(sacha.pokeballs()[0].pokemon().trainer() == &sacha);
// }

// TEST_CASE("A trainer can store Pokemons in the PC")
// {
//     PC      pc;
//     Trainer sacha { "Sacha", pc };

//     auto bulbizarre = std::make_unique<Pokemon>("Bulbizarre");
//     sacha.capture(std::move(bulbizarre));

//     REQUIRE(pc.pokemons().empty() == true);
//     sacha.store_in_pc(0);
//     REQUIRE(pc.pokemons().empty() == false);
//     REQUIRE(pc.pokemons()[0]->name() == "Bulbizarre");
// }

// TEST_CASE("A trainer can retrieve their Pokemons from the PC")
// {
//     PC      pc;
//     Trainer sacha { "Sacha", pc };

//     const auto& sacha_pokeballs = sacha.pokeballs();

//     auto bulbizarre = std::make_unique<Pokemon>("Bulbizarre");
//     sacha.capture(std::move(bulbizarre));
//     sacha.store_in_pc(0);

//     SECTION("A trainer can retrieve their Pokemons by name")
//     {
//         REQUIRE(pc.pokemons().empty() == false);
//         REQUIRE(sacha_pokeballs[0].empty() == true);

//         pc.give_back(sacha, "Bulbizarre");

//         REQUIRE(pc.pokemons().empty() == true);
//         REQUIRE(sacha_pokeballs[0].empty() == false);
//         REQUIRE(sacha_pokeballs[0].pokemon().name() == "Bulbizarre");
//     }

//     SECTION("When a trainer retrieves its Pokemon, it goes in the next empty Pokeball")
//     {
//         auto carapuce = std::make_unique<Pokemon>("Carapuce");
//         sacha.capture(std::move(carapuce));
//         REQUIRE(sacha_pokeballs[0].empty() == false);
//         REQUIRE(sacha_pokeballs[1].empty() == true);

//         pc.give_back(sacha, "Bulbizarre");
//         REQUIRE(sacha_pokeballs[0].empty() == false);
//         REQUIRE(sacha_pokeballs[0].pokemon().name() == "Carapuce");
//         REQUIRE(sacha_pokeballs[1].empty() == false);
//         REQUIRE(sacha_pokeballs[1].pokemon().name() == "Bulbizarre");
//     }

//     SECTION("A trainer cannot steal the Pokemon of someone else")
//     {
//         Trainer pierre { "Pierre", pc };
//         auto    carapuce = std::make_unique<Pokemon>("Carapuce");
//         pierre.capture(std::move(carapuce));
//         pierre.store_in_pc(0);

//         REQUIRE(pc.pokemons().size() == 2);
//         REQUIRE(sacha_pokeballs[0].empty() == true);

//         pc.give_back(sacha, "Carapuce");

//         REQUIRE(pc.pokemons().size() == 2);
//         REQUIRE(sacha_pokeballs[0].empty() == true);
//     }
// }
