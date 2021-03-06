#include <iostream>
#include <vector>

using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c);

int main() {
    size_t an;
    std::cin >> an;
    vector<int> a(an);
    for (size_t i = 0; i < an; i++) {
        std::cin >> a[i];
    }
    size_t bn;
    std::cin >> bn;
    vector<int> b(bn);
    for (size_t i = 0; i < bn; i++) {
        std::cin >> b[i];
    }
    size_t cn;
    std::cin >> cn;
    vector<int> c(cn);
    for (size_t i = 0; i < cn; i++) {
        std::cin >> c[i];
    }
    std::cout << lcs3(a, b, c) << std::endl;
}

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c)
{
    vector<vector<vector<long long>>> arr(a.size() + 1, vector<vector<long long>>(b.size() + 1, 
        vector<long long>(c.size() + 1, 0)));
    for (size_t i = 1; i <= a.size(); i++)
    {
        for (size_t j = 1; j <= b.size(); j++)
        {
            for (size_t k = 1; k <= c.size(); k++)
            {

                if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
                    arr[i][j][k] = arr[i - 1][j - 1][k - 1] + 1;
                else
                    arr[i][j][k] = std::max(std::max(arr[i - 1][j][k], 
                        arr[i][j - 1][k]), arr[i][j][k - 1]);
            }
        }
    }
    return arr[a.size()][b.size()][c.size()];
}