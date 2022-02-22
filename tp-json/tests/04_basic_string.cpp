#include "../StringNode.hpp"
#include "assert.cpp"

int main()
{
    StringNode p { "Hello world!" };
    ASSERT_EQUAL(p.kind(), NodeKind::STRING);
    ASSERT_EQUAL(p.print(), "\"Hello world!\"");

    Node& r = p;
    ASSERT_EQUAL(r.kind(), NodeKind::STRING);
    ASSERT_EQUAL(r.print(), "\"Hello world!\"");
}
