#include <iostream>
#include <string>
#include <vector>

int letter_occurence(const char letter, const std::string word) {
    int count = 0;

    for (auto l : word) {
        if (l == letter) {
            count += 1;
        }
    }

    return count;
}

std::vector<unsigned int> count_lower(const std::string word) {
    std::vector<unsigned int> tab;

    for (auto l = 'a'; l <= 'z'; l++) {
        tab.emplace_back(letter_occurence(l, word));
    }

    return tab;
}

void display_lower_occ(const std::vector<unsigned int> tab) {
    for (auto i = 0; i != 26; i++) {
        char letter = 'a' + i;
        std::cout << letter << " : " << tab[i] << std::endl;
    }
}

int main() {
    std::vector<unsigned int> tab;
    std::string               word;
    std::string               final_word;

    while (true) {
        std::cin >> word;

        if (word == "QUIT") {
            break;
        }

        final_word.append(word + " ");
    }

    tab = count_lower(final_word);
    display_lower_occ(tab);
    std::cout << final_word << std::endl;

    return 0;
}