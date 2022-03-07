#include "../JsonParser.cpp"
#include "assert.cpp"

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "First command-line argument needs to be the path to the json resources.";
        exit(EXIT_FAILURE);
    }
    std::string dir = std::string(argv[1]);
    std::string filename;

    {
        Node_ptr node;

        filename = dir + "pokedex.json";
        std::cerr << "Starting test with: " << filename << std::endl;
        node = JsonParser::parse_from_file(filename);

        ASSERT_UNEQUAL(node->as_ObjectNode(), nullptr)
        ASSERT_UNEQUAL(node->as_ObjectNode()->at("pokemon"), nullptr)
        ASSERT_UNEQUAL(node->as_ObjectNode()->at("pokemon")->as_ArrayNode(), nullptr)

        std::unordered_map<std::string, unsigned> pokemon_id_by_name;
        for (const auto& pokemon_node : *(node->as_ObjectNode()->at("pokemon")->as_ArrayNode()))
        {
            ASSERT_UNEQUAL(pokemon_node->as_ObjectNode(), nullptr)
            auto pokemon_obj = x->as_ObjectNode();

            ASSERT_UNEQUAL(pokemon_obj->at("name"), nullptr)
            ASSERT_UNEQUAL(pokemon_obj->at("name")->as_StringNode(), nullptr)
            const std::string& name = pokemon_obj->at("name")->as_StringNode()->data();

            ASSERT_UNEQUAL(pokemon_obj->at("id"), nullptr)
            ASSERT_UNEQUAL(pokemon_obj->at("id")->as_NumberNode(), nullptr)
            unsigned id = pokemon_obj->at("id")->as_NumberNode()->data();

            pokemon_id_by_name[name] = id;
        }

        std::unordered_map<std::string, std::vector<unsigned>> pokemon_id_by_type;
        for (const auto& pokemon_node : *(node->as_ObjectNode()->at("pokemon")->as_ArrayNode()))
        {
            ASSERT_UNEQUAL(pokemon_node->as_ObjectNode(), nullptr)
            ASSERT_UNEQUAL(pokemon_node->as_ObjectNode()->at("type"), nullptr)
            ASSERT_UNEQUAL(pokemon_node->as_ObjectNode()->at("type")->as_ObjectNode(), nullptr)
            for (const auto& type_node : *(pokemon_node->as_ObjectNode()->at("type")->as_ArrayNode()))
            {
                ASSERT_UNEQUAL(type_node->as_StringNode(), nullptr)
                std::string const& type = type_node->as_StringNode()->data();
                auto               it   = pokemon_id_by_type.find(type);
                if (it == pokemon_id_by_type.end())
                    it = pokemon_id_by_type.emplace(type, std::vector<unsigned>()).first;
                it->second.emplace_back(pokemon_node->as_ObjectNode()->at("id")->as_NumberNode()->data());
            }
        }

        for (const auto& pair : pokemon_id_by_type)
        {
            std::cerr << pair.first << ": [";
            bool b = false;
            for (auto i : pair.second)
            {
                if (b)
                    std::cerr << ", ";
                else
                    b = true;
                std::cerr << i;
            }
            std::cerr << "]" << std::endl;
        }

        std::vector<std::tuple<std::string, std::string>> const tests = { { "Bulbasaur", "Grass" },
                                                                          { "Bulbasaur", "Poison" },
                                                                          { "Wartortle", "Water" },
                                                                          { "Pikachu", "Electric" } };
        for (auto const& [name, type] : tests)
        {
            std::cerr << "Checking that \"" << name << "\" is of type \"" << type << "\"." << std::endl;

            auto const& list_it = pokemon_id_by_type.find(type);
            auto const& elt_it  = pokemon_id_by_name.find(name);

            assert(list_it != pokemon_id_by_type.end());
            assert(elt_it != pokemon_id_by_name.end());

            const std::vector<unsigned>& poke_list = list_it->second;
            unsigned                     poke_elt  = elt_it->second;

            assert(std::find(poke_list.begin(), poke_list.end(), poke_elt) != poke_list.end());
        }
    }
}