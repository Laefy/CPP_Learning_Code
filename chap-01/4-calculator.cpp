#include <iostream>
#include <string>
#include <vector>

bool parse_params(char& op, std::vector<int>& values, int arg, char** argv) {
    if (arg < 2) {
        std::cerr << "Expected operator as first argument." << std::endl;
        return false;
    }

    op = argv[1][0];

    if (op != '+' && op != '*' && op != '-') {
        std::cerr << "Expected operator to be '+', '*' or '-'." << std::endl;
        return false;
    }

    for (auto arg_i = 2; arg_i < arg; ++arg_i) {
        auto value = std::stoi(argv[arg_i]);
        values.emplace_back(value);
    }

    if (values.empty() && op == '-') {
        std::cerr << "Operator '-' expects at least one operand to substract from." << std::endl;
        return false;
    }

    return true;
}

int add(const std::vector<int>& values) {
    auto result = 0;

    for (auto v : values) {
        result += v;
    }

    return result;
}

int sub(const std::vector<int>& values) {
    auto result = values[0];

    for (auto i = 1u; i < values.size(); ++i) {
        result -= values[i];
    }

    return result;
}

int multiply(const std::vector<int>& values) {
    auto result = 1;

    for (auto v : values) {
        result *= v;
    }

    return result;
}

int compute_result(char op, const std::vector<int>& values) {
    auto result = 0;

    switch (op) {
    case '+':
        return add(values);
    case '-':
        return sub(values);
    case '*':
        return multiply(values);
    default:
        return 0;
    }
}

void display_result(int result) {
    std::cout << "Result is " << result << std::endl;
}

int main(int argc, char** argv) {
    /*// Parsing program parameters.
    if (argc < 2) {
        std::cerr << "Expected operator as first argument." << std::endl;
        return -1;
    }

    std::string op = argv[1];

    if (op != "+" && op != "*" && op != "-") {
        std::cerr << "Expected operator to be '+', '*' or '-'." << std::endl;
        return -1;
    }

    std::vector<int> values;
    for (auto arg_i = 2; arg_i < argc; ++arg_i) {
        auto value = std::stoi(argv[arg_i]);
        values.emplace_back(value);
    }

    if (values.empty() && op == "-") {
        std::cerr << "Operator '-' expects at least one operand to substract from." << std::endl;
        return -1;
    }

    // Process operation, depending on the operator.
    auto result = 0;

    if (op == "+") {
        for (auto v : values) {
            result += v;
        }
    }
    else if (op == "*") {
        result = 1;
        for (auto v : values) {
            result *= v;
        }
    }
    else if (op == "-") {
        if (values.empty()) {
            std::cerr << "Operator '-' expects at least one operand to substract from." << std::endl;
            return -1;
        }

        result = values[0];
        for (auto i = 1u; i < values.size(); ++i) {
            result -= values[i];
        }
    }

    // Output result.
    std::cout << "Result is " << result << std::endl;*/

    std::vector<int> values;
    char             op;

    if (!parse_params(op, values, argc, argv)) {
        return -1;
    }

    auto result = compute_result(op, values);
    display_result(result);

    return 0;
}
