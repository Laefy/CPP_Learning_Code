#include "../JsonParser.hpp"
#include "assert.cpp"

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

    filename               = dir + "array_large_numbers.json";
    node                   = JsonParser::parse_from_file(filename);
    auto const& array_node = node->as_ArrayNode();
    for (unsigned i = 0; i < node->children_count())
}