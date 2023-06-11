#include <iostream>
#include <vector>

using std::vector;

long long optimal_weight(long long W, const vector<long long> &wn)
{

  vector<vector<long long>> grid(W + 1, vector<long long>(wn.size() + 1));
  long long current_weight = 0;
  long long val = 0;

  for (size_t i = 1; i <= wn.size(); ++i)
  {
    for (long long w = 1; w <= W; ++w)
    {
      grid.at(w).at(i) = grid.at(w).at(i - 1);
      // if (wn.at(i) <= W && w - wn.at(i - 1) >= 0)
      if (wn.at(i - 1) <= w)
      {
        val = grid.at(w - wn.at(i - 1)).at(i - 1) + wn.at(i - 1);
        if (grid.at(w).at(i) <= val)
        {
          grid.at(w).at(i) = val;
        }
      }
    }
  }
  auto ret_val = grid.at(W).at(wn.size());
  // for (auto &i : grid)
  // {
  //   for (auto &j : i)
  //   {
  //     std::cout << j << " ";
  //   }
  //   std::cout << "\n";
  // }
  return ret_val;
}

int main()
{
  long long n{};
  long long W{};
  std::cin >> W >> n;
  vector<long long> w(n);
  for (long long i = 0; i < n; i++)
  {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';

  return 0;
}
