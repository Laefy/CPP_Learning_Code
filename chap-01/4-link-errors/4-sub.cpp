#include "4-sub.hpp"
#include "4-debug.hpp"

int sub(int a, int b)
{
    debug("sub", a, b);
    return a - b;
}
