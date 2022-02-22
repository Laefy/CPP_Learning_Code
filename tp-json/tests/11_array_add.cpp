#include "../json.hpp"
#include "assert.cpp"

int main()
{
    auto   array_node_ptr = ArrayNode::make_ptr();
    size_t size           = array_node_ptr->children_count();
    ASSERT_EQUAL(size, 0u);
    array_node_ptr->add(StringNode::make_ptr("H"));
    ASSERT_EQUAL(array_node_ptr->children_count(), ++size);
    array_node_ptr->add(NumberNode::make_ptr(3110));
    ASSERT_EQUAL(array_node_ptr->children_count(), ++size);
    array_node_ptr->add(NullNode::make_ptr());
    ASSERT_EQUAL(array_node_ptr->children_count(), ++size);
    array_node_ptr->add(StringNode::make_ptr("W"));
    ASSERT_EQUAL(array_node_ptr->children_count(), ++size);
    array_node_ptr->add(NumberNode::make_ptr(0));
    ASSERT_EQUAL(array_node_ptr->children_count(), ++size);
    array_node_ptr->add(StringNode::make_ptr("rld!"));
    ASSERT_EQUAL(array_node_ptr->children_count(), ++size);

    // This is a raw literal, go check it out https://en.cppreference.com/w/cpp/language/string_literal */
    std::string target = R"---(["H", 3110, null, "W", 0, "rld!"])---";
    //                   ^^^^^^                                ^^^^
    // The parts marked with ^ above are not part of the string;

    ASSERT_EQUAL(array_node_ptr->print(), target);
}
