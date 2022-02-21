#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    std::vector<int> array = { 0, 1, 2, 3 };
    std::string      s     = "test";

    for (int i = 0; i < 4; ++i)
    {
        std::cout << array[i] << std::endl;
    }

    std::cout << argc << " " << (argc > 1 ? argv[2] : "Pas d'argument") << std::endl;

    return 0;
}
