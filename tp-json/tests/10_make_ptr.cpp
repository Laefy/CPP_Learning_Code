#include "../json.hpp"
#include "assert.cpp"

#include <utility>

int main()
{
    Node_ptr null_node_ptr    = NullNode::make_ptr();
    Node_ptr boolean_node_ptr = BooleanNode::make_ptr(true);
    Node_ptr int_node_ptr     = NumberNode::make_ptr(1);
    Node_ptr string_node_ptr  = StringNode::make_ptr("Hello world");
    Node_ptr array_node_ptr   = ArrayNode::make_ptr();
    Node_ptr object_node_ptr  = ObjectNode::make_ptr();
}
