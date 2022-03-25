/* This files exists to check that the basic files compile. */
#include "../Node.hpp"
#include "assert.cpp"

int main()
{
    Node* node1 = nullptr;
    Node* node2 = nullptr;
    ASSERT_EQUAL(node1, node2);
}
