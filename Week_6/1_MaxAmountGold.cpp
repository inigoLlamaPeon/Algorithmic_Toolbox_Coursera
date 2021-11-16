#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &wght);

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}

int optimal_weight(int W, const vector<int> &wght) 
{
    int wSize = wght.size(), val = 0, lim = W + 1;
    vector<vector<int>> value(wSize + 1, vector<int>(W + 1, 0));

    for (size_t i = 1; i <= wSize; i++)
    {
        for (int w = 1; w < lim; w++)
        {
            value[i][w] = value[i - 1][w];
            if (wght[i - 1] <= w)
            {
                val = value[i - 1][w - wght[i - 1]] + wght[i - 1];
                if (value[i][w] < val)
                    value[i][w] = val;
            }
        }
    }
    return value[wSize][W];
}