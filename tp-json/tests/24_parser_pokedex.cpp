#include "../JsonParser.hpp"
#include "custom_assert.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "First command-line argument needs to be the path to the json resources.";
        exit(EXIT_FAILURE);
    }

    std::string dir = std::string(argv[1]);
    std::string filename;
    Node_ptr    node;

    filename = dir + "pokedex.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    node = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(node->height(), 5u);
    ASSERT_EQUAL(node->node_count(), 3779u);
    ASSERT_EQUAL(node->kind(), NodeKind::OBJECT);
}