#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

void randomized_quick_sort(vector<int> &a, int l, int r);
vector<int> threeWayPart(vector<int> &a, int l, int r);

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    randomized_quick_sort(a, 0, a.size() - 1);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    vector<int> m = threeWayPart(a, l, r);
    int m1 = m[0], m2 = m[1];
    randomized_quick_sort(a, l, m1 - 1);
    randomized_quick_sort(a, m2 + 1, r);
}

vector<int> threeWayPart(vector<int> &a, int l, int r)
{
    int i = l, L = l, R = r, x = a[l];
    while (i <= R)
    {
        if (a[i] > x)
            swap(a[i], a[R--]);
        else if (a[i] < x)
            swap(a[i++], a[L++]);
        else
            i++;
    }
    return vector<int> {L, R};
}