#include "../JsonParser.cpp"
#include "assert.cpp"

#include <iostream>

int main(int argc, char** argv)
{
    if (argc < 1)
    {
        std::cout << "First command-line argument needs to be where are the json resources.";
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
}