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

    filename = dir + "array_range10.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    node = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(node->height(), 1u);
    ASSERT_EQUAL(node->node_count(), 11u);
    ASSERT_EQUAL(node->kind(), NodeKind::ARRAY);

    filename = dir + "array_hexadecimal.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    node = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(node->height(), 4u);
    ASSERT_EQUAL(node->node_count(), 31u);
    ASSERT_EQUAL(node->kind(), NodeKind::ARRAY);
}