#include "../BooleanLeaf.hpp"
#include "custom_assert.hpp"

int main()
{
    BooleanLeaf p { true };
    ASSERT_EQUAL(p.kind(), NodeKind::BOOLEAN);
    ASSERT_EQUAL(p.print(), "true");

    Node& r = p;
    ASSERT_EQUAL(r.kind(), NodeKind::BOOLEAN);
    ASSERT_EQUAL(r.print(), "true");

    BooleanLeaf p2 { false };
    ASSERT_EQUAL(p2.print(), "false");
}
