#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool partition3(vector<int64_t>& A);
bool searchPart(const vector<int64_t>& A, int index, vector<int64_t>& parti, int64_t obj);

int main() {
    int n;
    std::cin >> n;
    vector<int64_t> A(n);
    for (size_t i = 0; i < A.size(); ++i) {
        std::cin >> A[i];
    }
    std::cout << partition3(A) << '\n';
}

bool partition3(vector<int64_t>& A)
{
    int64_t n = accumulate(A.begin(), A.end(), 0);
    if (n % 3 != 0 || A.size() < 3 || *max_element(A.begin(), A.end()) > n / 3)
        return false;
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    vector<int64_t> parti(3, 0);
    return searchPart(A, 0, parti, n / 3);
}

bool searchPart(const vector<int64_t>& A, int index, vector<int64_t>& parti, int64_t obj) 
{
    if (index >= A.size()) return true;
    for (size_t i = 0; i < parti.size(); i++) {
        if (parti[i] + A.at(index) <= obj) {
            parti[i] += A.at(index);
            if (searchPart(A, index + 1, parti, obj))
                return true;
            parti[i] -= A.at(index);
        }
    }
    return false;
}