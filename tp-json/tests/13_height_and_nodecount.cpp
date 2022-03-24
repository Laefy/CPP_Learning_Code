#include "assert.cpp"
#include "json.hpp"

#include <iostream>

int main()
{
    Node_ptr null_node_ptr = NullNode::make_ptr();
    ASSERT_EQUAL(null_node_ptr->height(), 0u);
    ASSERT_EQUAL(null_node_ptr->node_count(), 1u);

    Node_ptr boolean_node_ptr = BooleanNode::make_ptr(true);
    auto     array_node_ptr   = ArrayNode::make_ptr();
    array_node_ptr->add(std::move(null_node_ptr));
    array_node_ptr->add(std::move(boolean_node_ptr));
    ASSERT_EQUAL(array_node_ptr->height(), 1u);
    ASSERT_EQUAL(array_node_ptr->node_count(), 3u);

    auto     object_node_ptr = ObjectNode::make_ptr();
    Node_ptr string_node_ptr = StringNode::make_ptr("Hello world");
    Node_ptr int_node_ptr    = NumberNode::make_ptr(1);
    object_node_ptr->add("array", std::move(array_node_ptr));
    object_node_ptr->add("string", std::move(string_node_ptr));
    object_node_ptr->add("int", std::move(int_node_ptr));
    ASSERT_EQUAL(object_node_ptr->height(), 2u);
    ASSERT_EQUAL(object_node_ptr->node_count(), 6u);
}