#include "solution.cpp"
#include <iostream>
#include <filesystem>

int main() {
    std::string filename;
    int queries = 0;
    std::cout << "Enter file full path: ";
    std::cin >> filename;
    if (!std::filesystem::exists(filename)) {
        std::cout << "File doesn't exist!\n";
        return 0;
    }
    std::cout << "Enter number of queries: ";
    std::cin >> queries;
    solution sol(filename);
    std::string query;
    for (int i = 0; i < queries; ++i) {
        std::cout << "Enter string to search: ";
        std::cin >> query;

        auto position = sol.containsStr(query);
        if (position != -1) {
            std::cout << "String position: " << position << std::endl;
        } else {
            std::cout << "String is not found\n";
        }
    }
    return 0;
}

