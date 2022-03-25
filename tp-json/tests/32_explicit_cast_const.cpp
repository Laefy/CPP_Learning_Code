#include "../ArrayNode.hpp"
#include "../BooleanLeaf.hpp"
#include "../Node.hpp"
#include "../NodeKind.hpp"
#include "../NumberLeaf.hpp"
#include "../ObjectNode.hpp"
#include "../StringLeaf.hpp"
#include "assert.cpp"

int main()
{
    Node_ptr node;
    {
        node                       = BooleanLeaf::make_ptr(true);
        auto const& node_const_ref = *node;
        ASSERT_UNEQUAL(node_const_ref.as_BooleanLeaf(), nullptr);
        ASSERT_EQUAL(node_const_ref.as_NumberLeaf(), nullptr);
        ASSERT_EQUAL(node_const_ref.as_StringLeaf(), nullptr);
        ASSERT_EQUAL(node_const_ref.as_ArrayNode(), nullptr);
        ASSERT_EQUAL(node_const_ref.as_ObjectNode(), nullptr);
    }

    {
        node                       = NumberLeaf::make_ptr(1);
        auto const& node_const_ref = *node;
        ASSERT_UNEQUAL(node_const_ref.as_NumberLeaf(), nullptr);
    }

    {
        node                       = StringLeaf::make_ptr("Hello world");
        auto const& node_const_ref = *node;
        ASSERT_UNEQUAL(node_const_ref.as_StringLeaf(), nullptr);
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