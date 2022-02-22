#include "../NullNode.hpp"
#include "assert.cpp"

int main()
{
    NullNode p {};
    ASSERT_EQUAL(p.kind(), NodeKind::NONE);
    ASSERT_EQUAL(p.print(), "null");

    Node& r = p;
    ASSERT_EQUAL(r.print(), "null");
    ASSERT_EQUAL(r.kind(), NodeKind::NONE);
}
