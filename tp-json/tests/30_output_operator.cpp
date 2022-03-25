#include "../ArrayNode.hpp"
#include "assert.cpp"

#include <iostream>

int main()
{
    // This only tests for the existence of the operator<<
    // in order to have ASSERT_EQUAL to compile
    // We do not impose the format: cf optional questions.
    Node_ptr node = ArrayNode::make_ptr();
    std::cout << (*node) << std::endl;
}
