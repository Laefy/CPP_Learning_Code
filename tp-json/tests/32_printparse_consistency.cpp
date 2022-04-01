#include "../JsonParser.hpp"
#include "custom_assert.hpp"

int main()
{
    std::string json_dir = "json/";

    std::vector<std::string> names = { "cpp2022.json", "pokedex.json", "string_nasty.json" };

    for (const std::string& name : names)
    {
        std::string filename = json_dir + name;
        std::cerr << "Starting test with: \"" << filename << '"' << std::endl;
        Node_ptr    node1           = JsonParser::parse_from_file(filename);
        std::string node1_as_string = node1->print();
        Node_ptr    node2           = JsonParser::parse_from_string(node1_as_string);
        ASSERT_EQUAL(*node1, *node2);
    }
}