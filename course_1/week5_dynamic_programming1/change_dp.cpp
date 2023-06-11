#include <iostream>
#include <vector>

int get_change(int m)
{
  std::vector<int> denoms{1, 3, 4};
  std::vector<int> min_num_coins(m + 1);
  min_num_coins.at(0) = 0;
  int num_coins = 0;

  for (size_t i = 1; i <= m; i++)
  {
    for (auto &coin : denoms)
    {
      if (i >= coin)
      {
        num_coins = min_num_coins.at(i - coin) + 1;
        if (min_num_coins.at(i) == 0 || num_coins < min_num_coins.at(i))
        {
          min_num_coins.at(i) = num_coins;
        }
      }
    }
  }

  return min_num_coins.at(m);
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
