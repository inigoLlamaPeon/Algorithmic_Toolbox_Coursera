#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<long long> &a, vector<long long> &b);

int main()
{
    size_t n;
    std::cin >> n;
    vector<long long> a(n);
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    size_t m;
    std::cin >> m;
    vector<long long> b(m);
    for (size_t i = 0; i < m; i++)
    {
        std::cin >> b[i];
    }

    std::cout << lcs2(a, b) << std::endl;
}


int lcs2(vector<long long> &a, vector<long long> &b)
{
    vector<vector<long long>> arr(a.size() + 1, vector<long long>(b.size() + 1, 0));
    for (size_t i = 1; i <= a.size(); i++)
    {
        for (size_t j = 1; j <= b.size(); j++)
        {
            if (a[i - 1] == b[j - 1])
                arr[i][j] = arr[i - 1][j - 1] + 1;
            else
                arr[i][j] = std::max(arr[i - 1][j], arr[i][j - 1]);
        }
    }
    return arr[a.size()][b.size()];
}

