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

    {
        Node_ptr node = BooleanLeaf::make_ptr(true);
        ASSERT_UNEQUAL(node->as_BooleanLeaf(), nullptr);
        ASSERT_EQUAL(node->as_NumberLeaf(), nullptr);
        ASSERT_EQUAL(node->as_StringLeaf(), nullptr);
        ASSERT_EQUAL(node->as_ArrayNode(), nullptr);
        ASSERT_EQUAL(node->as_ObjectNode(), nullptr);
    }
    {
        Node_ptr node = NumberLeaf::make_ptr(1);
        ASSERT_UNEQUAL(node->as_NumberLeaf(), nullptr);
        ASSERT_EQUAL(node->as_BooleanLeaf(), nullptr);
        ASSERT_EQUAL(node->as_StringLeaf(), nullptr);
        ASSERT_EQUAL(node->as_ArrayNode(), nullptr);
        ASSERT_EQUAL(node->as_ObjectNode(), nullptr);
    }
    {
        Node_ptr node = StringLeaf::make_ptr("Hello world");
        ASSERT_UNEQUAL(node->as_StringLeaf(), nullptr);
    }
    {
        Node_ptr node = ArrayNode::make_ptr();
        ASSERT_UNEQUAL(node->as_ArrayNode(), nullptr);
    }
    {
        Node_ptr node = ObjectNode::make_ptr();
        ASSERT_UNEQUAL(node->as_ObjectNode(), nullptr);
    }
}