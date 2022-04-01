#include "../JsonParser.hpp"
#include "custom_assert.hpp"

#include <iostream>

int main()
{
    std::string json_dir = "json/";

    {
        std::string filename = json_dir + "object_empty.json";
        std::cerr << "Starting test with: " << filename << std::endl;
        Node_ptr node = JsonParser::parse_from_file(filename);
        ASSERT_EQUAL(node->height(), 0u);
        ASSERT_EQUAL(node->node_count(), 1u);
        ASSERT_EQUAL(node->kind(), NodeKind::OBJECT);
    }

    {
        std::string filename = json_dir + "object_alphabet.json";
        std::cerr << "Starting test with: " << filename << std::endl;
        Node_ptr node = JsonParser::parse_from_file(filename);
        ASSERT_EQUAL(node->height(), 1u);
        ASSERT_EQUAL(node->node_count(), 27u);
        ASSERT_EQUAL(node->kind(), NodeKind::OBJECT);
    }
}