#include <iostream>
#include <string>

int main() {
    using namespace std;

    // int number = 0;

    /*while (true) {
        if (number == -1) {
            break;
        }
        std::cin >> number;
        std::cout << "Craow " << number << " !" << std::endl;
    }*/

    /*do {
        std::cin >> number;
        std::cout << "Craow " << number << " !" << std::endl;
    }
    while (number != -1);*/

    /*for (int i = 0; i != 10; i++) {
        std::cin >> number;
        std::cout << "Craow " << number << " !" << std::endl;
    }*/

    string word;

    for (int i = 0; i != 10; i++) {
        cin >> word;
        cout << "Craow " << word << " !" << endl;
    }

    return 0;
}