#include "Node.hpp"

std::ostream& operator<<(std::ostream& o, const Node& node)
{
    return o << node.print();
}