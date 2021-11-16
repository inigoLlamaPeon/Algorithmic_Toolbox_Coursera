#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <string>
#include <utility>
#include <vector>
#include <bits/c++config.h>
#include <cstdint>

using namespace std;

long long eval(long long a, long long b, char oper);
long long get_maximum_val(const string &exp);

int main() {
    string s;
    std::cin >> s;
    std::cout << get_maximum_val(s) << '\n';
}

long long eval(long long a, long long b, char oper) {
    if (oper == '*') {
        return a * b;
    } else if (oper == '+') {
        return a + b;
    } else if (oper == '-') {
        return a - b;
    } else {
        assert(0);
    }
}

long long get_maximum_val(const string &exp) {
    int64_t tMin, tMax;
    int64_t a, b, c, d;
    size_t n = (exp.size() + 1) >> 1;
    vector<pair<int64_t, int64_t>> soltn(n * n);
    auto getSol = [&soltn, &exp, n](int64_t i, int64_t j) {
        return soltn.at(i * n + j);
    };
    auto setSol = [&soltn, &exp, n](int64_t i, int64_t j, pair<int64_t, int64_t> val) {
        return soltn[i * n + j] = val;
    };
    auto dig = [&exp](int64_t i) {
        return exp.at(2 * i) - '0';
    };
    auto oper = [&exp](int64_t i) {
        return exp.at(2 * i + 1);
    };

    for (size_t i = 0; i < n; i++)
        setSol(i, i, make_pair(dig(i), dig(i)));

    for (size_t i = 1; i < n; i++) {
        for (size_t j = i; j < n; j++) {
            tMin = numeric_limits<int64_t>::max();
            tMax = numeric_limits<int64_t>::min();
            for (size_t k = j - i; k < j; k++) {
                a = eval(getSol(j - i, k).first, getSol(k + 1, j).first, oper(k));
                b = eval(getSol(j - i, k).second, getSol(k + 1, j).second, oper(k));
                c = eval(getSol(j - i, k).first, getSol(k + 1, j).second, oper(k));
                d = eval(getSol(j - i, k).second, getSol(k + 1, j).first, oper(k));
                tMin = min(tMin, min(min(a, b), min(c, d)));
                tMax = max(tMax, max(max(a, b), max(c, d)));
                setSol(j - i, j, make_pair(tMin, tMax));
            }
        }
    }
    return getSol(0, exp.size() >> 1).second;
}