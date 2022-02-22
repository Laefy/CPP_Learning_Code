#include "../json.hpp"
#include "assert.cpp"

#include <iostream>

int main()
{
    // This only tests for the existance of the operator<<
    // We do not impose the format: cf optional questions.
    Node_ptr node = NullNode::make_ptr();
    std::cout << (*node) << std::endl;
}
