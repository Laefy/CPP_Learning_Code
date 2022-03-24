#include "assert.cpp"
#include "json.hpp"

int main()
{
    auto   array_node_ptr = ArrayNode::make_ptr();
    size_t size           = array_node_ptr->children_count();
    ASSERT_EQUAL(size, 0u);

    array_node_ptr->add(StringNode::make_ptr("H"));
    array_node_ptr->add(NumberNode::make_ptr(3110));
    array_node_ptr->add(StringNode::make_ptr("!"));

    ASSERT_EQUAL(array_node_ptr->children_count(), 3u);

    // This is a raw literal, go check it out https://en.cppreference.com/w/cpp/language/string_literal */
    std::string target = R"---(["H",3110,"!"])---";
    //                   ^^^^^^              ^^^^^
    // The parts marked with ^ above are not part of the string;

    ASSERT_EQUAL(array_node_ptr->print(), target);
}
