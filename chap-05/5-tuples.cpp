#include <iostream>
#include <string>

bool parse_params(int argc, const char* const* argv, int& numerator, int& denominator)
{
    if (argc != 3)
    {
        std::cerr << "Program expects 2 parameters!" << std::endl;
        return false;
    }

    std::string num_str = argv[1];
    std::string den_str = argv[2];

    try
    {
        numerator   = std::stoi(num_str);
        denominator = std::stoi(den_str);
    }
    catch (const std::exception&)
    {
        std::cerr << "Program expects 2 integer parameters!" << std::endl;
        return false;
    }

    if (denominator == 0)
    {
        std::cerr << "Denominator cannot be null!" << std::endl;
        return false;
    }

    return true;
}

int divide(int numerator, int denominator, int& reminder)
{
    reminder = numerator % denominator;
    return numerator / denominator;
}

int main(int argc, char** argv)
{
    int numerator   = 0;
    int denominator = 0;

    if (!parse_params(argc, argv, numerator, denominator))
    {
        return 1;
    }

    int       reminder = 0;
    const int quotient = divide(numerator, denominator, reminder);

    std::cout << numerator << " = " << denominator << " * " << quotient << " + " << reminder << std::endl;

    return 0;
}