#include "solution.cpp"
#include <iostream>
#include <filesystem>

int main() {
    std::string filename = std::string(std::filesystem::current_path()) + "/../testfiles/simple.txt";
    std::cout << filename;
    solution sol(filename);
    std::cout << sol.containsStr("hello") << std::endl;
    return 0;
}

