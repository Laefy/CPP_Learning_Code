#include "../ArrayNode.hpp"
#include "../BooleanLeaf.hpp"
#include "../Node.hpp"
#include "../NodeKind.hpp"
#include "../NumberLeaf.hpp"
#include "../ObjectNode.hpp"
#include "../StringLeaf.hpp"
#include "custom_assert.hpp"

int main()
{
    auto   object_node_ptr = ObjectNode::make_ptr();
    size_t size            = object_node_ptr->child_count();
    ASSERT_EQUAL(size, 0u);

    object_node_ptr->add("key1", NumberLeaf::make_ptr(42));
    object_node_ptr->add("key1", BooleanLeaf::make_ptr(true));
    object_node_ptr->add("key2", StringLeaf::make_ptr("Hello World!"));
    object_node_ptr->add("key2", ArrayNode::make_ptr());
    object_node_ptr->add("key2", StringLeaf::make_ptr("World, hello!"));

    ASSERT_EQUAL(object_node_ptr->height(), 1u);
    ASSERT_EQUAL(object_node_ptr->node_count(), 3u);
}