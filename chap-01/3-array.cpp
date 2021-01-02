#include <iostream>
#include <string>
#include <vector>

// #define STATIC_VALUES
// #define FOREACH
// #define STATIC_SIZE
// #define DYNAMIC
#define VECTOR

#ifdef STATIC_VALUES
int main()
{
    int array[] = { 0, 1, 2, 3 };

    for (int i = 0; i < 4; ++i)
    {
        std::cout << array[i] << std::endl;
    }

    return 0;
}
#endif

#ifdef FOREACH
int main()
{
    int array[] = { 0, 1, 2, 3 };

    for (int value : array)
    {
        std::cout << value << std::endl;
    }

    return 0;
}
#endif

#ifdef STATIC_SIZE
int main()
{
    int array[50] = {};

    for (int i = 0; i < 50; ++i)
    {
        // Array indices start at 0, so we need to use (i+1) if we want the series to start at 1.
        array[i] = i+1;
    }

    for (int value : array)
    {
        std::cout << value << std::endl;
    }

    return 0;
}
#endif

#ifdef DYNAMIC
int main(int argc, char** argv)
{
    // First argument is always the command name used to launch the program.
    if (argc < 2)
    {
        std::cerr << "Expected argument for array size." << std::endl;
        return -1;
    }

    int length = std::stoi(argv[1]);
    if (length <= 0)
    {
        std::cerr << "Expected strictly positive value for array size." << std::endl;
        return -1;
    }

    int* array = new int[length] {};

    for (int i = 0; i < length; ++i)
    {
        array[i] = i+1;
    }

    for (int i = 0; i < length; ++i)
    {
        std::cout << array[i] << std::endl;
    }

    delete[] array;

    return 0;
}
#endif

#ifdef VECTOR
int main(int argc, char** argv)
{
    // First argument is always the command name used to launch the program.
    if (argc < 2)
    {
        std::cerr << "Expected argument for array size." << std::endl;
        return -1;
    }

    int length = std::stoi(argv[1]);
    if (length <= 0)
    {
        std::cerr << "Expected strictly positive value for array size." << std::endl;
        return -1;
    }

    std::vector<int> array;

    for (int i = 0; i < length; ++i)
    {
        array.emplace_back(i+1);
    }

    for (int value : array)
    {
        std::cout << value << std::endl;
    }

    return 0;
}
#endif
