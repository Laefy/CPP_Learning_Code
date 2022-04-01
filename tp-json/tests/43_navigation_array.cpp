#include "../JsonParser.hpp"
#include "custom_assert.hpp"

int main()
{
    std::string json_dir = "json/";

    std::string filename     = json_dir + "pokedex.json";
    auto        node         = JsonParser::parse_from_file(filename);
    auto        pokemon_node = node->at("pokemon");
    ASSERT_EQUAL(pokemon_node->kind(), NodeKind::ARRAY);
    ASSERT_EQUAL(pokemon_node->child_count(), 151u);

    /* Pikachu pokedex number is 25 */
    ASSERT_EQUAL(pokemon_node->at(24)->at("name")->as_StringLeaf()->data(), "Pikachu");
}