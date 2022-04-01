#include "../JsonParser.hpp"
#include "custom_assert.hpp"

int main()
{
    std::string json_dir = "json/";

    {
        std::string filename = json_dir + "boolean_true.json";
        std::cerr << "Starting test with: " << filename << std::endl;
        Node_ptr node = JsonParser::parse_from_file(filename);
        ASSERT_EQUAL(*node, *BooleanLeaf::make_ptr(true));
    }
    {
        std::string filename = json_dir + "number_42.json";
        std::cerr << "Starting test with: " << filename << std::endl;
        Node_ptr node = JsonParser::parse_from_file(filename);
        ASSERT_EQUAL(*node, *NumberLeaf::make_ptr(42));
    }
    {
        std::string filename = json_dir + "string_hello.json";
        std::cerr << "Starting test with: " << filename << std::endl;
        Node_ptr node = JsonParser::parse_from_file(filename);
        ASSERT_EQUAL(*node, *StringLeaf::make_ptr("Hello"));
    }
    {
        std::string filename = json_dir + "object_alphabet.json";
        std::cerr << "Starting test with: " << filename << std::endl;
        Node_ptr node   = JsonParser::parse_from_file(filename);
        auto     target = ObjectNode::make_ptr();
        for (char c = 'a'; c <= 'z'; c++)
            target->add(std::string(1, c), NumberLeaf::make_ptr(c));
        ASSERT_EQUAL(*node, *target);
    }
    {
        std::string filename = json_dir + "array_range10.json";
        std::cerr << "Starting test with: " << filename << std::endl;
        Node_ptr node   = JsonParser::parse_from_file(filename);
        auto     target = ArrayNode::make_ptr();
        for (unsigned i = 0; i < 10; i++)
            target->add(NumberLeaf::make_ptr(i));
        ASSERT_EQUAL(*node, *target);
    }
    {
        std::string filename = json_dir + "pokedex.json";
        std::cerr << "Starting test with: " << filename << std::endl;
        Node_ptr node = JsonParser::parse_from_file(filename);
        ASSERT_EQUAL(*node, *node);
    }
}