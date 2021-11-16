#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int edit_distance(const string &src1, const string &src2);
int findMin(int x, int y, int z);

int main()
{
    string src1;
    string src2;
    std::cin >> src1 >> src2;
    std::cout << edit_distance(src1, src2) << std::endl;
    return 0;
}

int edit_distance(const string &src1, const string &src2)
{
    int len1 = src1.length(), len2 = src2.length();
    vector<vector<int>> arr(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 0; i <= len1; i++)
        arr[i][0] = i;
    for (int i = 0; i <= len2; i++)
        arr[0][i] = i;
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (src1[i - 1] == src2[j - 1])
                arr[i][j] = findMin(arr[i - 1][j] + 1, arr[i][j - 1] + 1, arr[i - 1][j - 1]);
            else
                arr[i][j] = findMin(arr[i - 1][j], arr[i][j - 1], arr[i - 1][j - 1]) + 1;
        }
    }
    return arr[len1][len2];
}

int findMin(int x, int y, int z)
{
    if (x <= y && x <= z)
        return x;
    else if (y <= x && y <= z)
        return y;
    return z;
}
