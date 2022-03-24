#include "assert.cpp"
#include "json.hpp"

int main()
{
    auto   object_node_ptr = ObjectNode::make_ptr();
    size_t size            = object_node_ptr->children_count();
    ASSERT_EQUAL(size, 0u);

    object_node_ptr->add("key1", NumberNode::make_ptr(42));
    object_node_ptr->add("key1", NullNode::make_ptr());
    object_node_ptr->add("key2", StringNode::make_ptr("Hello World!"));
    object_node_ptr->add("key2", ArrayNode::make_ptr());
    object_node_ptr->add("key2", NullNode::make_ptr());

    ASSERT_EQUAL(object_node_ptr->height(), 1u);
    ASSERT_EQUAL(object_node_ptr->node_count(), 3u);
}