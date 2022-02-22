#include "../Parser.cpp"
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

    filename = dir + "null.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    Node_ptr node1 = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(*node1, *NullNode::make_ptr());

    filename = dir + "boolean_true.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    Node_ptr node2 = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(*node2, *BooleanNode::make_ptr(true));

    filename = dir + "number_42.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    Node_ptr node3 = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(*node3, *NumberNode::make_ptr(42));

    filename = dir + "string_hello.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    Node_ptr node4 = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(*node4, *StringNode::make_ptr("Hello"));
}