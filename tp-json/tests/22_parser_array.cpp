#include "../JsonParser.hpp"
#include "custom_assert.hpp"

#include <iostream>

int main()
{
    std::string json_dir = "json/";

    {
        std::string filename = json_dir + "array_range10.json";
        std::cerr << "Starting test with: " << filename << std::endl;
        Node_ptr node = JsonParser::parse_from_file(filename);
        ASSERT_EQUAL(node->height(), 1u);
        ASSERT_EQUAL(node->node_count(), 11u);
        ASSERT_EQUAL(node->kind(), NodeKind::ARRAY);
    }

    {
        std::string filename = json_dir + "array_hexadecimal.json";
        std::cerr << "Starting test with: " << filename << std::endl;
        Node_ptr node = JsonParser::parse_from_file(filename);
        ASSERT_EQUAL(node->height(), 4u);
        ASSERT_EQUAL(node->node_count(), 31u);
        ASSERT_EQUAL(node->kind(), NodeKind::ARRAY);
    }
}