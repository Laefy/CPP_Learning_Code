#include "../NullNode.hpp"
#include "assert.cpp"

int main()
{
    NullNode p {};
    ASSERT_EQUAL(p.print(), "null");
    ASSERT_TRUE(p.kind() == NodeKind::NONE);

    Node& r = p;
    ASSERT_EQUAL(r.print(), "null");
    ASSERT_TRUE(r.kind() == NodeKind::NONE);
}
