#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <unordered_set>
using namespace std;


string cleanText(const string& input) {
    string result;
    bool space_flag = false, punctuation_flag = false;

    for (size_t i = 0; i < input.size(); ++i) {
        char c = input[i];

    
        if (isspace(c)) {
            if (!space_flag && !result.empty()) {
                result += ' ';
                space_flag = true;
            }
            continue;
        }

        
        if (ispunct(c)) {
            if (c == '.' && i + 1 < input.size() && input[i + 1] == '.') {
                result += c;
                punctuation_flag = true;
                continue;
            }
            if (!punctuation_flag) {
                result += c;
                punctuation_flag = true;
            }
            continue;
        }

        
        result += tolower(c);
        space_flag = false;
        punctuation_flag = false;
    }


    if (!result.empty() && result.back() == '.') {
        result.pop_back();
    }

    return result;
}


vector<string> splitWords(const string& text) {
    stringstream ss(text);
    string word;
    vector<string> words;

    while (ss >> word) {
        words.push_back(word);
    }

    return words;
}

// 3 задание 
void task3(const vector<string>& words) {
    cout << "\nСлова, не содержащие цифр:\n";
    for (const string& word : words) {
        if (all_of(word.begin(), word.end(), [](char c) { return !isdigit(c); })) {
            cout << word << " ";
        }
    }
    cout << endl;
}

// 4 задание 
void task4(vector<string>& words, const unordered_set<char>& toRemove) {
    cout << "\nСлова после удаления заданных символов:\n";
    for (string& word : words) {
        word.erase(remove_if(word.begin(), word.end(), [&](char c) { return toRemove.count(c); }), word.end());
        cout << word << " ";
    }
    cout << endl;
}

int main() {
    // 1 задание 
    cout << "Введите текстовую последовательность (заканчивающуюся точкой):\n";
    string input;
    getline(cin, input);

    
    string cleanedText = cleanText(input);
    cout << "\nОтредактированный текст:\n" << cleanedText << endl;

    
    vector<string> words = splitWords(cleanedText);

    // 3 задание 
    task3(words);

    // 4 задание 
    unordered_set<char> toRemove = {'a', 'e', 'i', 'o', 'u', '1', '2', '3'};
    task4(words, toRemove);

    return 0;
}
