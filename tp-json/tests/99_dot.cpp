#include "../JsonParser.cpp"
#include "assert.cpp"

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
int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "First command-line argument needs to be the path to the json resources.";
        exit(EXIT_FAILURE);
    }
    std::string dir = std::string(argv[1]);
    std::string filename;

    {
        Node_ptr node;

        filename = dir + "cpp2022.json";
        std::cerr << "Starting test with: " << filename << std::endl;
        node = JsonParser::parse_from_file(filename);

        std::ofstream out("/tmp/test.gv");
        dot(out, node);
    }
}