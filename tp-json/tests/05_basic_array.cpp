#include "../ArrayNode.hpp"
#include "custom_assert.hpp"

int main()
{
    ArrayNode p {};
    ASSERT_EQUAL(p.kind(), NodeKind::ARRAY);
    ASSERT_EQUAL(p.print(), "[]");

    Node& r = p;
    ASSERT_EQUAL(r.kind(), NodeKind::ARRAY);
    ASSERT_EQUAL(r.print(), "[]");
}
