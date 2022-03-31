#include <gtest/gtest.h>
#include "../solution.cpp"
#include <filesystem>

TEST(SimpleTests, JustWorks) {
    std::string filename = std::string(std::filesystem::current_path()) + "/testfiles/simple.txt";
    std::cout << filename;
    solution sol(filename);
    ASSERT_EQ(sol.containsStr("hello"), 0);

    ASSERT_EQ(sol.containsStr("world"), 6);

    ASSERT_EQ(sol.containsStr("man"), -1);
};

TEST(SimpleTests, Multilines) {
    std::string filename = std::string(std::filesystem::current_path()) + "/testfiles/bigger.txt";
    std::cout << filename;
    solution sol(filename);
    ASSERT_EQ(sol.containsStr("tristique"), 1491);

    ASSERT_EQ(sol.containsStr("suspendisse"), 261);

    ASSERT_EQ(sol.containsStr("aliquet"), 1537);
};
