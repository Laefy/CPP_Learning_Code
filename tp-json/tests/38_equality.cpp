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

    filename = dir + "boolean_true.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    node = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(*node, *BooleanLeaf::make_ptr(true));

    filename = dir + "number_42.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    node = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(*node, *NumberLeaf::make_ptr(42));

    filename = dir + "string_hello.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    node = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(*node, *StringLeaf::make_ptr("Hello"));

    filename = dir + "object_alphabet.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    auto target1 = ObjectNode::make_ptr();
    for (char c = 'a'; c <= 'z'; c++)
        target1->add(std::string(1, c), NumberLeaf::make_ptr(c));
    node = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(*node, *target1);

    filename = dir + "array_range10.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    auto target2 = ArrayNode::make_ptr();
    for (unsigned i = 0; i < 10; i++)
        target2->add(NumberLeaf::make_ptr(i));
    node = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(*node, *target2);

    filename = dir + "pokedex.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    node = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(*node, *node);
}