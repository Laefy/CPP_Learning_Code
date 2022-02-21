
#include "../json.hpp"
#include "assert.cpp"

int main()
{
    Node_ptr null_node_ptr   = NullNode::make_ptr();
    Node_ptr int_node_ptr    = NumberNode::make_ptr(1);
    Node_ptr string_node_ptr = StringNode::make_ptr("Hello world");
    Node_ptr array_node_ptr  = ArrayNode::make_ptr({ std::move(null_node_ptr), std::move(int_node_ptr) });
    Node_ptr object_node_ptr = ObjectNode::make_ptr({ "child", std::move(string_node_ptr) });
}
