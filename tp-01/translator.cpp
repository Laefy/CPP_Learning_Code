#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool parse_params(int argc, char** argv, string& dict_path, string& word, string& translation,
                  vector<string>& sentence);
vector<pair<string, string>> open_dictionary(char* path);
void                         save_dictionary(char* path, vector<pair<string, string>> dict);
void                         translate(vector<string>& sentence, vector<pair<string, string>> dict);

int main(int argc, char** argv)
{
    const char *dict_path, word, translation, sentence;

    if (!parse_params(argc, argv, dict_path, translation, sentence))
    {
        return -1;
    }

    vector<pair<string, string>> dict;

    if (dict_path)
    {
        dict = open_dictionary(dict_path);
    }

    if (word && translation)
    {
        dict.emplace_back(word, translation);

        if (dict_path)
        {
            save_dictionary(dict_path, dict);
        }
    }

    if (sentence)
    {
        translate(sentence, dict);
    }

    return 0;
}

bool parse_params(int argc, char** argv, string& dict_path, string& word, string& translation,
                  vector<string> sentence)
{
    for (auto i = 1; i < argc; ++i)
    {
        std::string option = argv[i];

        if (option == "-d" && (i + 1) < argc)
        {
            dict_path = argv[++i];
        }
        else if (option == "-a" && (i + 2) < argc)
        {
            word        = argv[++i];
            translation = argv[++i];
        }
        else
        {
            sentence.emplace_back(argv[i]);
        }
    }

    if (dict_path.empty())
    {
        cerr << "No dictionary path was provided." << endl;
        return false;
    }

    return true;
}

vector<pair<string, string>> open_dictionary(char* path)
{
    vector<pair<string, string>> dict;

    fstream file { path, ios_base::in };

    int i = 0;
    while (file.eof())
    {
        string word;
        file >> word;

        string translation;
        file >> translation;

        dict[++i] = pair { word, translation };
    }

    return dict;
}

void save_dictionary(char* path, vector<pair<string, string>> dict)
{
    fstream file { path, ios_base::out };

    for (auto word_translation : dict)
    {
        file << word_translation.first << " " << word_translation.second << std::endl;
    }
}

void translate(vector<string>& sentence, vector<pair<string, string>> dict)
{
    for (auto word : sentence)
    {
        for (auto word_translation : dict)
        {
            if (word == word_translation.first)
            {
                cout << word_translation.second << " ";
            }
            else
            {
                cout << "???"
                     << " ";
            }
        }
    }
}
