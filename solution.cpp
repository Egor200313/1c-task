#include <iostream>
#include "solution.h"

solution::solution(const std::string& filename): inputFile(filename), machine(29) {
    loadMachine();
}

solution::~solution() {
    inputFile.close();
}

void solution::loadMachine() {
    std::string first_word;
    long long curPos = -1;
    while(std::getline(inputFile, first_word)) {
        for (auto c: first_word) {
            machine.addchar(c, ++curPos);
        }
    }
}

long long solution::containsStr(const std::string &s) {
    long long result = machine.has_substring(s);
    return (result < 0)? result : result - (long long)(s.size()) + 1;
}
