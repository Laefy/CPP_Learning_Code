#include "../JsonParser.hpp"
#include "custom_assert.hpp"

int main()
{
    std::string json_dir = "json/";

    std::string filename   = json_dir + "pokedex.json";
    auto        node       = JsonParser::parse_from_file(filename);
    const auto& const_node = node->as_ObjectNode();

    ASSERT_TRUE(const_node->has_child("pokemon"));
    ASSERT_FALSE(const_node->has_child("digimon"));

    auto pokemon_node = const_node->at("pokemon");
    ASSERT_UNEQUAL(pokemon_node, nullptr);
    ASSERT_EQUAL(const_node->at("digimon"), nullptr);
}