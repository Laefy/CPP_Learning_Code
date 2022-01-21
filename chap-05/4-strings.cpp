#include <iostream>

void print_in_console(const std::string& str)
{
    std::cout << str << std::endl;
}

int main()
{
    print_in_console("print me");
    return 0;
}
