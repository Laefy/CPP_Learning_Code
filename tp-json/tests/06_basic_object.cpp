#include "../ObjectNode.hpp"
#include "assert.cpp"

int main()
{
    ObjectNode p {};
    ASSERT_TRUE(p.kind() == NodeKind::OBJECT);
    ASSERT_EQUAL(p.print(), "{}");

    Node& r = p;
    ASSERT_TRUE(r.kind() == NodeKind::OBJECT);
    ASSERT_EQUAL(r.print(), "{}");
}
