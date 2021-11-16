#include <iostream>

#define MAX 9999999

int get_change(int m);

int main()
{
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}

int get_change(int m)
{
    int coins[] = {1, 3, 4}, mnc[m + 1], nCoins = 0;
    mnc[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        mnc[i] = MAX;
        for (int j = 0; j < 3; j++)
        {
            if (coins[j] <= i)
            {
                nCoins = mnc[i - coins[j]] + 1;
                mnc[i] = nCoins < mnc[i] ? nCoins : mnc[i];
            }
        }
    }
    return mnc[m];
}