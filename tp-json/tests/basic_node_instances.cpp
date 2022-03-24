#pragma once

#include "../json.hpp"

namespace example {
/* This complicated declaration is to let the implementer choose the return type of ObjectNode::make_ptr() */
auto make_ArrayNode_example2() -> decltype(ArrayNode::make_ptr())
{
    auto node = ArrayNode::make_ptr();

    return node;
}

/* This complicated declaration is to let the implementer choose the return type of ObjectNode::make_ptr() */
auto make_ObjectNode_example2() -> decltype(ObjectNode::make_ptr())
{
    auto node = ObjectNode::make_ptr();
    node->add("premier", StringLeaf::make_ptr("Child 1"));
    auto child2 = ArrayNode::make_ptr();
    child2->add(NullNode::make_ptr());
    child2->add(StringLeaf::make_ptr("Grandchild with null siblings"));
    child2->add(NullNode::make_ptr());
    node->add("enfant fecond", std::move(child2));
    node->add("enfant vide", ArrayNode::make_ptr());
    node->add("le petit dernier", StringLeaf::make_ptr("Benjamin"));
    return node;
}
std::vector<Node_ptr> const instances { NullNode::make_ptr(),     NullNode::make_ptr(),
                                        NumberNode::make_ptr(0),  NumberNode::make_ptr(42),
                                        StringLeaf::make_ptr(""), StringLeaf::make_ptr("Hello world!"),
                                        ArrayNode::make_ptr(),    make_ArrayNode_example2(),
                                        ObjectNode::make_ptr(),   make_ObjectNode_example2() };

auto& null_node_ptr1   = instances[1];
auto& null_node_ptr2   = instances[2];
auto& int_node_ptr2    = instances[3];
auto& string_node_ptr2 = instances[4];
auto& array_node_ptr1  = instances[5];
auto& object_node_ptr1 = instances[6];

} // namespace example
