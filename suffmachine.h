#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <set>
#include <map>

using std::vector;
using std::map;
using std::set;

class SuffAutomat {
private:
    vector<vector<long long>> edges;
    vector<long long> link;
    vector<long long> len;
    vector<long long> index;
    long long extra = 0;
    long long last = 0;

    long long new_state(long long i) {
        link.push_back(-10);
        len.push_back(len[last] + 1);
        edges.emplace_back(vector<long long>(26 + extra, -1));
        index.push_back(i);
        return (long long)(edges.size() - 1);
    }

    long long clone(long long state, long long num) {
        link.push_back(-10);
        len.push_back(len[state]);
        edges.emplace_back(vector<long long>(26 + extra, -1));
        index.push_back(-1);
        long long clone = num;
        index[clone] = index[state];
        edges[clone] = edges[state];
        link[clone] = link[state];
        return clone;
    }

    static long long to_index(char c) {
        if (c == ' ') return 53;
        if (c == '.') return 54;
        if (c < 'a') {
            return 26 + c - 'A';
        }
        if ( c >= 'a' && c <= 'z') return c - 'a';
        return 55;
    }

public:
    explicit SuffAutomat(long long extra) {
        link.push_back(-1);
        len.push_back(0);
        this->extra = extra;
        edges.emplace_back(vector<long long>(26 + extra, -1));
        index.push_back(-1);
    }

    void addchar(char c, long long i) {
        long long current = new_state(i);
        long long previous = last;
        while (previous >= 0 && edges[previous][to_index(c)] == -1) {
            edges[previous][to_index(c)] = current;
            if (previous == 0) {
                link[current] = 0;
            }
            previous = link[previous];
        }
        if (previous != -1) {
            long long state_with_c = edges[previous][to_index(c)];
            if (len[previous] + 1 == len[state_with_c]) {
                link[current] = state_with_c;
            } else {
                long long clone_state = clone(state_with_c, current + 1);
                len[clone_state] = len[previous] + 1;
                link[current] = clone_state;
                link[state_with_c] = clone_state;
                while (previous >= 0 && edges[previous][to_index(c)] == state_with_c) {
                    edges[previous][to_index(c)] = clone_state;
                    previous = link[previous];
                }
            }
        }
        index[current] = i;
        last = current;
    }

    long long has_substring(std::string s) {
        long long current = 0;
        for (long long i = 0; i < s.length(); ++i) {
            if (edges[current][to_index(s[i])] == -1) {
                return -1;
            }
            current = edges[current][to_index(s[i])];
        }
        return index[current];
    }
};
