#include "../JsonParser.hpp"
#include "custom_assert.hpp"

#include <iostream>

int main()
{
    std::string json_dir = "json/";

    {
        std::string filename = json_dir + "boolean_true.json";
        std::cerr << "Starting test with: " << filename << std::endl;
        Node_ptr node = JsonParser::parse_from_file(filename);
        ASSERT_EQUAL(node->height(), 0u);
        ASSERT_EQUAL(node->node_count(), 1u);
        ASSERT_EQUAL(node->kind(), NodeKind::BOOLEAN);
    }

    {
        std::string filename = json_dir + "number_42.json";
        std::cerr << "Starting test with: " << filename << std::endl;
        Node_ptr node = JsonParser::parse_from_file(filename);
        ASSERT_EQUAL(node->height(), 0u);
        ASSERT_EQUAL(node->node_count(), 1u);
        ASSERT_EQUAL(node->kind(), NodeKind::NUMBER);
    }

    {
        std::string filename = json_dir + "string_hello.json";
        std::cerr << "Starting test with: " << filename << std::endl;
        Node_ptr node = JsonParser::parse_from_file(filename);
        ASSERT_EQUAL(node->height(), 0u);
        ASSERT_EQUAL(node->node_count(), 1u);
        ASSERT_EQUAL(node->kind(), NodeKind::STRING);
    }

    {
        std::string filename = json_dir + "array_empty.json";
        std::cerr << "Starting test with: " << filename << std::endl;
        Node_ptr node = JsonParser::parse_from_file(filename);
        ASSERT_EQUAL(node->height(), 0u);
        ASSERT_EQUAL(node->node_count(), 1u);
        ASSERT_EQUAL(node->kind(), NodeKind::ARRAY);
    }

    {
        std::string filename = json_dir + "object_empty.json";
        std::cerr << "Starting test with: " << filename << std::endl;
        Node_ptr node = JsonParser::parse_from_file(filename);
        ASSERT_EQUAL(node->height(), 0u);
        ASSERT_EQUAL(node->node_count(), 1u);
        ASSERT_EQUAL(node->kind(), NodeKind::OBJECT);
    }
}