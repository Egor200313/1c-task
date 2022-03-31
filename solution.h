#include <fstream>
#include "suffmachine.h"

class solution {
public:
    explicit solution(const std::string&);
    long long containsStr(const std::string& s);

    ~solution();
private:
    void loadMachine();
    std::fstream inputFile;
    SuffAutomat machine;
};

