#include "4-add.hpp"
#include "4-debug.hpp"

int add(int a, int b)
{
    debug("add", a, b);
    return a + b;
}
