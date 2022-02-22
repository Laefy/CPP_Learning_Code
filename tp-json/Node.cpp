#include "ArrayNode.hpp"
#include "NullNode.hpp"
#include "NumberNode.hpp"
#include "ObjectNode.hpp"
#include "StringNode.hpp"

std::ostream& operator<<(std::ostream& o, const Node& node)
{
    return o << node.print();
}