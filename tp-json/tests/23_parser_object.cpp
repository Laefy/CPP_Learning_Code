#include "../JsonParser.cpp"
#include "assert.cpp"

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

    filename = dir + "object_empty.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    node = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(node->height(), 0u);
    ASSERT_EQUAL(node->node_count(), 1u);
    ASSERT_EQUAL(node->kind(), NodeKind::OBJECT);

    filename = dir + "object_alphabet.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    node = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(node->height(), 1u);
    ASSERT_EQUAL(node->node_count(), 27u);
    ASSERT_EQUAL(node->kind(), NodeKind::OBJECT);
}