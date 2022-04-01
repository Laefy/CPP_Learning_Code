#include "../JsonParser.hpp"
#include "custom_assert.hpp"

int main()
{
    std::string json_dir = "json/";

    std::string filename     = json_dir + "pokedex.json";
    auto        node         = JsonParser::parse_from_file(filename);
    auto        pokemon_node = node->at("pokemon")->as_ArrayNode();

    auto chikorita = ObjectNode::make_ptr();
    chikorita->add("id", NumberLeaf::make_ptr(152));
    chikorita->add("name", StringLeaf::make_ptr("Chikorita"));
    chikorita->add("num", StringLeaf::make_ptr("152"));
    chikorita->add("type", ArrayNode::make_ptr());
    chikorita->at("type")->as_ArrayNode()->add(StringLeaf::make_ptr("Grass"));

    pokemon_node->add(std::move(chikorita));

    ASSERT_EQUAL(pokemon_node->child_count(), 152u);
    ASSERT_EQUAL(node->height(), 5u);
    ASSERT_EQUAL(node->node_count(), 3779u + 6u);
}