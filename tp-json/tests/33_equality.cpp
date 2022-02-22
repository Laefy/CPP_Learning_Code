#include "../JsonParser.cpp"
#include "../json.hpp"
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

    filename = dir + "null.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    node = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(*node, *NullNode::make_ptr());

    filename = dir + "boolean_true.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    node = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(*node, *BooleanNode::make_ptr(true));

    filename = dir + "number_42.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    node = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(*node, *NumberNode::make_ptr(42));

    filename = dir + "string_hello.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    node = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(*node, *StringNode::make_ptr("Hello"));
}