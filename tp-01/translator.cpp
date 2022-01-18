#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool parse_params(int argc, char* argv[], string& dict_path, string& word, string& translation,
                  vector<string>& sentence);
vector<pair<string, string>> open_dictionary(char* path);
void                         save_dictionary(char* path, vector<pair<string, string>> dict);
void                         translate(vector<string>& sentence, vector<pair<string, string>> dict);


        if (option == "-d" && (i + 1) < argc) {
            dict_path = argv[++i];
        }
        else if (option == "-a" && (i + 2) < argc) {
            word        = argv[++i];
            translation = argv[++i];
        }
        else {
            sentence.emplace_back(argv[i]);
        }
    }

    if (dict_path.empty()) {
        cerr << "No dictionary path was provided." << endl;
        return false;
    }

    return true;
}

vector<pair<string, string>> open_dictionary(const string path) {
    vector<pair<string, string>> dict;

    fstream file { path, ios_base::in };

    if (file) {
        while (!file.eof()) {
            string word;
            file >> word;

            string translation;
            file >> translation;

            dict.emplace_back(pair { word, translation });
        }
    }

    return dict;
}

void save_dictionary(const string path, const vector<pair<string, string>> dict) {
    fstream file { path, ios_base::out };

    for (auto word_translation : dict) {
        if (word_translation.first != "") {
            file << word_translation.first << " " << word_translation.second << endl;
        }
    }
}

void translate(const vector<string>& sentence, const vector<pair<string, string>>& dict) {
    for (auto word : sentence) {
        int flag = 1;
        for (auto word_translation : dict) {
            if (word == word_translation.first) {
                cout << word_translation.second << " ";
                flag = 0;
                break;
            }
            else
            {
                cout << "???" << " ";
            }
        }
        if (flag == 1) {
            cout << "???"
                 << " ";
        }
    }
}

int main(int argc, char** argv) {
    string                       dict_path;
    string                       word;
    string                       translation;
    vector<string>               sentence;
    vector<pair<string, string>> dict;

    if (!parse_params(argc, argv, dict_path, word, translation, sentence)) {
        return -1;
    }

    dict = open_dictionary(dict_path);

    if (word != "" && translation != "") {
        dict.emplace_back(word, translation);
        save_dictionary(dict_path, dict);
    }

    if (!sentence.empty()) {
        translate(sentence, dict);
    }

    return 0;
}