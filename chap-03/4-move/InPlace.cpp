#include <iostream>

struct Test
{
    Test(int v)
        : value { v }
    {
        std::cout << "Constructor was called with " << v << "." << std::endl;
    }

    Test(const Test& other)
        : value { other.value }
    {
        std::cout << "Copy constructor was called." << std::endl;
    }

    int value = 0;
};

Test create_test(int value)
{
    Test result { value };
    return result;
}

int main()
{
    Test test = create_test(3);
    std::cout << test.value << std::endl;

    return 0;
}