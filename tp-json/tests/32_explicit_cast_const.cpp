#include "assert.cpp"
#include "json.hpp"

int main()
{
    Node_ptr node = NullNode::make_ptr();

    {
        auto const& node_const_ref = *node;

        ASSERT_UNEQUAL(node_const_ref.as_NullNode(), nullptr);

        ASSERT_EQUAL(node_const_ref.as_BooleanNode(), nullptr);
        ASSERT_EQUAL(node_const_ref.as_NumberNode(), nullptr);
        ASSERT_EQUAL(node_const_ref.as_StringNode(), nullptr);
        ASSERT_EQUAL(node_const_ref.as_ArrayNode(), nullptr);
        ASSERT_EQUAL(node_const_ref.as_ObjectNode(), nullptr);
    }

    {
        node                       = BooleanNode::make_ptr(true);
        auto const& node_const_ref = *node;
        ASSERT_UNEQUAL(node_const_ref.as_BooleanNode(), nullptr);
    }

    {
        node                       = NumberNode::make_ptr(1);
        auto const& node_const_ref = *node;
        ASSERT_UNEQUAL(node_const_ref.as_NumberNode(), nullptr);
    }

    {
        node                       = StringNode::make_ptr("Hello world");
        auto const& node_const_ref = *node;
        ASSERT_UNEQUAL(node_const_ref.as_StringNode(), nullptr);
    }

    {
        node                       = ArrayNode::make_ptr();
        auto const& node_const_ref = *node;
        ASSERT_UNEQUAL(node_const_ref.as_ArrayNode(), nullptr);
    }

    {
        node                       = ObjectNode::make_ptr();
        auto const& node_const_ref = *node;
        ASSERT_UNEQUAL(node_const_ref.as_ObjectNode(), nullptr);
    }
}