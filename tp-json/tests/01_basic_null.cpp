#include "../NullNode.hpp"
#include "assert.cpp"

int main()
{
    NullNode p {};
    Node&    r = p;
    ASSERT_EQUAL(r.print(), "null");
    ASSERT_TRUE(r.kind() == NodeKind::NONE);
}
