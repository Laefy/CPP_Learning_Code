#include "../NumberLeaf.hpp"
#include "custom_assert.hpp"

int main()
{
    NumberLeaf p { 1 };
    ASSERT_EQUAL(p.kind(), NodeKind::NUMBER);
    ASSERT_EQUAL(p.print(), "1");

    Node& r = p;
    ASSERT_EQUAL(r.kind(), NodeKind::NUMBER);
    ASSERT_EQUAL(r.print(), "1");
}
