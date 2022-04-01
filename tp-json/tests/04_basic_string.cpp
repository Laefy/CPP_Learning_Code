#include "../StringLeaf.hpp"
#include "custom_assert.hpp"

int main()
{
    StringLeaf p { "Hello world!" };
    ASSERT_EQUAL(p.kind(), NodeKind::STRING);
    ASSERT_EQUAL(p.print(), "\"Hello world!\"");

    Node& r = p;
    ASSERT_EQUAL(r.kind(), NodeKind::STRING);
    ASSERT_EQUAL(r.print(), "\"Hello world!\"");
}
