#include <cassert>
#include <iostream>

template <typename T1, typename T2>
void assert_equal(T1 left, T2 right, unsigned line)
{
    if (!(left == right))
    {
        std::cerr << "On line " << line << ", assert_equal failed: (" << left << " == " << right
                  << ") returns false." << std::endl;
        exit(EXIT_FAILURE);
    }
}

#define ASSERT_EQUAL(x, y) assert_equal(x, y, __LINE__);

void assert_true(bool b, unsigned line)
{
    if (b)
        return;
    std::cerr << "On line " << line << ", assert_true failed" << std::endl;
    exit(EXIT_FAILURE);
}

#define ASSERT_TRUE(b) assert_true(b, __LINE__);

void assert_false(bool b, unsigned line)
{
    if (!b)
        return;
    std::cerr << "On line " << line << ", assert_false failed" << std::endl;
    exit(EXIT_FAILURE);
}
#define ASSERT_FALSE(b) assert_false(b, __LINE__);
