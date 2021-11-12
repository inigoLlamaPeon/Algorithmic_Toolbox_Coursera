#include <iostream>
#include <vector>

using std::vector;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right);
long long mergeCount(vector<int> &arr1, vector<int> &arr2,size_t low, size_t half, size_t high);

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++)
        std::cin >> a[i];
    vector<int> b = a;
    std::cout << get_number_of_inversions(a, b, 0, a.size() - 1) << '\n';
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) 
{
    long long number_of_inversions = 0;
    if (right == left) 
        return 0;
    size_t center = left + ((right - left) >> 1);
    number_of_inversions += get_number_of_inversions(a, b, left, center);
    number_of_inversions += get_number_of_inversions(a, b, center + 1, right);
    number_of_inversions += mergeCount(a, b, left, center, right);
    return number_of_inversions;
}

long long mergeCount(vector<int> &arr1, vector<int> &arr2,size_t low, size_t half, size_t high)
{
    int cnt = 0, i = low, j = half + 1, k = low;
    while (i <= half && j <= high)
    {
        if (arr1[i] <= arr1[j])
            arr2[k++] = arr1[i++];
        else
        {
            arr2[k++] = arr1[j++];
            cnt = cnt + half - i + 1;
        }
    }
    while (i <= half)
        arr2[k++] = arr1[i++];
    for (int m = low; m <= high; m++)
        arr1[m] = arr2[m];
  return cnt;
}