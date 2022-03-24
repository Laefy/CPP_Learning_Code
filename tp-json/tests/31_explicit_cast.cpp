#include "assert.cpp"
#include "json.hpp"

int main()
{
    // Node_ptr node = NullNode::make_ptr();

    // ASSERT_UNEQUAL(node->as_NullNode(), nullptr);

    /*ASSERT_EQUAL(node->as_BooleanNode(), nullptr);
    ASSERT_EQUAL(node->as_NumberNode(), nullptr);
    ASSERT_EQUAL(node->as_StringNode(), nullptr);
    ASSERT_EQUAL(node->as_ArrayNode(), nullptr);
    ASSERT_EQUAL(node->as_ObjectNode(), nullptr);*/

    Node_ptr node = BooleanLeaf::make_ptr(true);
    ASSERT_UNEQUAL(node->as_BooleanNode(), nullptr);
    ASSERT_EQUAL(node->as_NumberNode(), nullptr);
    ASSERT_EQUAL(node->as_StringNode(), nullptr);
    ASSERT_EQUAL(node->as_ArrayNode(), nullptr);
    ASSERT_EQUAL(node->as_ObjectNode(), nullptr);

    node = NumberLeaf::make_ptr(1);
    ASSERT_UNEQUAL(node->as_NumberNode(), nullptr);
    ASSERT_EQUAL(node->as_BooleanNode(), nullptr);
    ASSERT_EQUAL(node->as_StringNode(), nullptr);
    ASSERT_EQUAL(node->as_ArrayNode(), nullptr);
    ASSERT_EQUAL(node->as_ObjectNode(), nullptr);

    node = StringLeaf::make_ptr("Hello world");
    ASSERT_UNEQUAL(node->as_StringNode(), nullptr);

    node = ArrayNode::make_ptr();
    ASSERT_UNEQUAL(node->as_ArrayNode(), nullptr);

    node = ObjectNode::make_ptr();
    ASSERT_UNEQUAL(node->as_ObjectNode(), nullptr);
}