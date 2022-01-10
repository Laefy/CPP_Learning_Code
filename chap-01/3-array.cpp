#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv) {
    /* int array[] = { 0, 1, 2, 3 };

    for (int i = 0; i < 4; ++i) {
        std::cout << array[i] << std::endl;
    }*/

    if (argc == 1) {
        std::cerr << "Missing argument" << std::endl;

        return -1;
    }

    /*int length        = std::stoi(argv[1]);
    int array[length] = {};

    std::cout << length << std::endl;

    for (int i = 0; i != length; i++) {
        array[i] = i + 1;
    }

    for (int value : array) {
        std::cout << value << std::endl;
    }*/

    int              length = std::stoi(argv[1]);
    std::vector<int> array;

    for (int i = 0; i != length; i++) {
        array.emplace_back(i + 1);
    }

    for (int value : array) {
        std::cout << value << std::endl;
    }

    return 0;
}