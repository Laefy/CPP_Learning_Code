#include "../JsonParser.hpp"
#include "custom_assert.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

void dot(std::ostream& o, Node_ptr const& node)
{
    o << "digraph G {" << std::endl;
    o << "rankdir=LR;" << std::endl;
    node->dot(o);
    o << "}" << std::endl;
}

int main()
{
    std::string dir = "json/";

    std::string filename = dir + "cpp2022.json";
    std::cerr << "Starting test with: " << filename << std::endl;
    Node_ptr node = JsonParser::parse_from_file(filename);

    std::ofstream out("/tmp/test.gv");
    dot(out, node);
}