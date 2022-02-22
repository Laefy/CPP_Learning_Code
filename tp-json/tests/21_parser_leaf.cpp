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

    filename = dir + "null.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    node = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(node->height(), 0u);
    ASSERT_EQUAL(node->node_count(), 1u);
    ASSERT_EQUAL(node->kind(), NodeKind::NONE);

    filename = dir + "boolean_true.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    node = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(node->height(), 0u);
    ASSERT_EQUAL(node->node_count(), 1u);
    ASSERT_EQUAL(node->kind(), NodeKind::BOOLEAN);

    filename = dir + "number_42.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    node = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(node->height(), 0u);
    ASSERT_EQUAL(node->node_count(), 1u);
    ASSERT_EQUAL(node->kind(), NodeKind::NUMBER);

    filename = dir + "string_hello.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    node = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(node->height(), 0u);
    ASSERT_EQUAL(node->node_count(), 1u);
    ASSERT_EQUAL(node->kind(), NodeKind::STRING);

    filename = dir + "array_empty.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    node = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(node->height(), 0u);
    ASSERT_EQUAL(node->node_count(), 1u);
    ASSERT_EQUAL(node->kind(), NodeKind::ARRAY);

    filename = dir + "object_empty.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    node = JsonParser::parse_from_file(filename);
    ASSERT_EQUAL(node->height(), 0u);
    ASSERT_EQUAL(node->node_count(), 1u);
    ASSERT_EQUAL(node->kind(), NodeKind::OBJECT);
}