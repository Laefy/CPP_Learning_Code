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
    auto   object_node_ptr = ObjectNode::make_ptr();
    size_t size            = object_node_ptr->children_count();
    ASSERT_EQUAL(size, 0u);

    object_node_ptr->add("H", NumberLeaf::make_ptr(3110));
    object_node_ptr->add(" ", BooleanLeaf::make_ptr(true));

    auto array_node_ptr = ArrayNode::make_ptr();
    array_node_ptr->add(NumberLeaf::make_ptr(0));
    array_node_ptr->add(StringLeaf::make_ptr("rld!"));
    array_node_ptr->add(ArrayNode::make_ptr());
    array_node_ptr->add(ObjectNode::make_ptr());
    object_node_ptr->add("W", std::move(array_node_ptr));

    ASSERT_EQUAL(object_node_ptr->children_count(), 3u);

    // This is a raw literal, go check it out https://en.cppreference.com/w/cpp/language/string_literal */
    std::string target = R"---({" ":true,"H":3110,"W":[0,"rld!",[],{}]})---";
    //                   ^^^^^^                                        ^^^^^
    // The parts marked with ^ above are not part of the string;

    ASSERT_EQUAL(object_node_ptr->print(), target);
}