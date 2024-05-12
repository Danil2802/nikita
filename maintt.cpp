#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

// ������� ��� �������������� ������� � ������ �����
std::string charToMorse(char c) {
    std::unordered_map<char, std::string> morseMap = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
        {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
        {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
        {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
        {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
        {'Z', "--.."}
    };

    c = toupper(c); // ��������� ������ � ������� �������
    if (morseMap.find(c) != morseMap.end()) {
        return morseMap[c];
    }
    else {
        return ""; // ���������� ������ ������ ��� ����������� ��������
    }
}

// ������� ��� �������������� ������������ � ������ �����
std::string permToMorse(const std::string& perm) {
    std::string morsePerm;
    for (char c : perm) {
        morsePerm += charToMorse(c);
    }
    return morsePerm;
}

// ������� ��� ��������� ���� ������������ �������� � ������
std::vector<std::string> getPermutations(const std::string& str) {
    std::vector<std::string> permutations;
    std::string sortedStr = str;
    std::sort(sortedStr.begin(), sortedStr.end());

    do {
        permutations.push_back(sortedStr);
    } while (std::next_permutation(sortedStr.begin(), sortedStr.end()));

    return permutations;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string input;
    std::cout << "������� ������: ";
    std::getline(std::cin, input); // ���� ������

    std::istringstream iss(input);
    std::string word;
    std::vector<std::string> words;
    std::vector<std::vector<std::string>> allPermutations;

    // ���������� ������ �� ����� � ��������� ������������ ��� ������� �����
    while (iss >> word) {
        if (word.length() > 11) {
            std::cout << "������� ������� �����: " << word << std::endl;
            return 0; // ��������� ������ ���� ��� ����������� ������� �������� �����
        }
        words.push_back(word);
        allPermutations.push_back(getPermutations(word));
    }

    // ������������ ���� � ����������� �������������� � ������ �����
    std::unordered_set<std::string> uniqueMorsePerms;
    std::vector<std::string> wordsWithUniquePerms;

    for (size_t i = 0; i < words.size(); ++i) {
        bool hasUniquePerm = true;
        for (const auto& perm : allPermutations[i]) {
            std::string morse = permToMorse(perm);
            if (uniqueMorsePerms.find(morse) != uniqueMorsePerms.end()) {
                hasUniquePerm = false;
                break;
            }
        }
        if (hasUniquePerm) {
            wordsWithUniquePerms.push_back(words[i]);
            for (const auto& perm : allPermutations[i]) {
                uniqueMorsePerms.insert(permToMorse(perm));
            }
        }
    }

    // ����� ���������� ���� � ����������� �������������� � ������ �� ����� ����
    std::cout << "���������� ���� � ����������� �������������� � ������ �����: " << wordsWithUniquePerms.size() << std::endl;
    return 0;
}
