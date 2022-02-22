#include "../json.hpp"
#include "assert.cpp"

int main()
{
    auto   object_node_ptr = ObjectNode::make_ptr();
    size_t size            = object_node_ptr->children_count();
    ASSERT_EQUAL(size, 0u);

    object_node_ptr->add("H", NumberNode::make_ptr(3110));
    ASSERT_EQUAL(object_node_ptr->children_count(), ++size);

    object_node_ptr->add(" ", NullNode::make_ptr());
    ASSERT_EQUAL(object_node_ptr->children_count(), ++size);

    auto array_node_ptr = ArrayNode::make_ptr();
    array_node_ptr->add(NumberNode::make_ptr(0));
    array_node_ptr->add(StringNode::make_ptr("rld!"));
    array_node_ptr->add(ArrayNode::make_ptr());
    array_node_ptr->add(ObjectNode::make_ptr());
    object_node_ptr->add("W", std::move(array_node_ptr));
    ASSERT_EQUAL(object_node_ptr->children_count(), ++size);

    // This is a raw literal, go check it out https://en.cppreference.com/w/cpp/language/string_literal */
    std::string target = R"---({" ":null, "H":3110, "W":[0, "rld!", [], {}]})---";

    ASSERT_EQUAL(object_node_ptr->print(), target);
}