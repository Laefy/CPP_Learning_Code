#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv)
{
    // Parsing program parameters.
    if (argc < 2)
    {
        std::cerr << "Expected operator as first argument." << std::endl;
        return -1;
    }

    std::string op = argv[1];

    if (op != "+" && op != "*" && op != "-")
    {
        std::cerr << "Expected operator to be '+', '*' or '-'." << std::endl;
        return -1;
    }

    std::vector<int> values;
    for (auto arg_i = 2; arg_i < argc; ++arg_i)
    {
        auto value = std::stoi(argv[arg_i]);
        values.emplace_back(value); 
    }

    // Process operation, depending on the operator.
    auto result = 0;

    if (op == "+")
    {
        for (auto v : values)
        {
            result += v;
        }
    }
    else if (op == "*")
    {
        result = 1;
        for (auto v : values)
        {
            result *= v;
        }
    }
    else if (op == "-")
    {
        if (values.empty())
        {
            std::cerr << "Operator '-' expects at least one operand to substract from." << std::endl;
            return -1;
        }

        result = values[0];
        for (auto i = 1; i < values.size(); ++i)
        {
            result -= values[i];
        }
    }

    // Output result.
    std::cout << "Result is " << result << std::endl;

    return 0;
}
