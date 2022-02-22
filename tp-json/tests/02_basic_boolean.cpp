#include "../BooleanNode.hpp"
#include "assert.cpp"

int main()
{
    BooleanNode p { true };
    ASSERT_EQUAL(p.kind(), NodeKind::BOOLEAN);
    ASSERT_EQUAL(p.print(), "true");

    Node& r = p;
    ASSERT_EQUAL(r.kind(), NodeKind::BOOLEAN);
    ASSERT_EQUAL(r.print(), "true");

    BooleanNode p2 { false };
    ASSERT_EQUAL(p2.print(), "false");
}
