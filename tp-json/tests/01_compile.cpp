/* This files exists to check that the files compile. */
#include "../Node.hpp"
#include "custom_assert.hpp"

int main()
{
    Node* node1 = nullptr;
    Node* node2 = nullptr;
    ASSERT_EQUAL(node1, node2);
}
