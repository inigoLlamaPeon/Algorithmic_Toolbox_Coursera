#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

#define MAX 999999

vector<int> calculus(int n);
vector<int> optimal_sequence(int n);

int main() {
    int n;
    std::cin >> n;
    vector<int> sequence = calculus(n);
    std::cout << sequence.size() - 1 << std::endl;
    for (size_t i = 0; i < sequence.size(); ++i)
    {
        std::cout << sequence[i] << " ";
    }
}

vector<int> optimal_sequence(int n)
{
    std::vector<int> sequence;
    while (n >= 1)
    {
        sequence.push_back(n);
        if (n % 3 == 0) {
            n /= 3;
        } else if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n - 1;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

vector<int> calculus(int n)
{
    vector<int> arr = {0}, ops = {1}, seq;
    if (n == 1)
    {
        seq.push_back(1);
        return seq;
    }
    for (int i = 2; i <= n; i++)
    {
        int r1 = MAX, r2 = MAX, r3 = MAX;
        r1 = arr[i - 2];
        if (i % 2 == 0)
            r2 = arr[(i / 2) - 1];
        if (i % 3 == 0)
            r3 = arr[(i / 3) - 1];
        if (r3 <= r1 && r3 <= r2)
        {
            ops.push_back(3);
            arr.push_back(r3 + 1);
        }
        else if (r2 <= r1 && r2 <= r3)
        {
            ops.push_back(2);
            arr.push_back(r2 + 1);
        }
        else if (r1 <= r2 && r1 <= r3)
        {
            ops.push_back(1);
            arr.push_back(r1 + 1);
        }
    }
    int m = n;
    while (m >= 1)
    {
        seq.push_back(m);
        if (ops[m - 1] == 1)
            m--;
        else if (ops[m - 1] == 2)
            m /= 2;
        else
            m /= 3;
    }
    reverse(seq.begin(), seq.end());
    return seq;
}