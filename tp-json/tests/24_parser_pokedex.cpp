#include "../JsonParser.hpp"
#include "custom_assert.hpp"

#include <iostream>

int main()
{
    std::string json_dir = "json/";

    {
        std::string filename = json_dir + "pokedex.json";
        std::cerr << "Starting test with: " << filename << std::endl;
        Node_ptr node = JsonParser::parse_from_file(filename);
        ASSERT_EQUAL(node->child_count(), 1u);
        ASSERT_EQUAL(node->height(), 5u);
        ASSERT_EQUAL(node->node_count(), 3779u);
        ASSERT_EQUAL(node->kind(), NodeKind::OBJECT);
    }
}