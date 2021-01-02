#include <iostream>
#include <string>

// #define READ
// #define WHILE
// #define DO_WHILE
// #define FOR
// #define STRING
#define USING_NS

#ifdef READ
int main()
{
    int number = 0;
    std::cin >> number;
    std::cout << "Craow " << number << "!" << std::endl;
    return 0;
}
#endif

#ifdef WHILE
int main()
{
    while (true)
    {
        int number = 0;
        std::cin >> number;
        std::cout << "Craow " << number << "!" << std::endl;

        if (number == -1)
        {
            break;
        }
    }

    return 0;
}
#endif

#ifdef DO_WHILE
int main()
{
    int number = 0;

    do
    {
        std::cin >> number;
        std::cout << "Craow " << number << "!" << std::endl;
    }
    while (number != -1);

    return 0;
}
#endif

#ifdef FOR
int main()
{
    for (int i = 0; i < 10; ++i)
    {
        int number = 0;
        std::cin >> number;
        std::cout << "Craow " << number << "!" << std::endl;
    }

    return 0;
}
#endif

#ifdef STRING
int main()
{
    for (int i = 0; i < 10; ++i)
    {
        std::string word;
        std::cin >> word;
        std::cout << "Craow " << word << "!" << std::endl;
    }

    return 0;
}
#endif

#ifdef USING_NS
int main()
{
    using namespace std;

    for (int i = 0; i < 10; ++i)
    {
        string word;
        cin >> word;
        cout << "Craow " << word << "!" << endl;
    }

    return 0;
}
#endif
