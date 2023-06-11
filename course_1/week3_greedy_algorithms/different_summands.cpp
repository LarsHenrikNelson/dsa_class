#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n)
{
  if (n <= 2)
  {
    vector<int> summands{n};
    return summands;
  }
  vector<int> summands;
  int count{1};
  int sum{0};
  while (sum < n)
  {
    if (sum + count <= n)
    {
      summands.push_back(count);
      sum += count;
      ++count;
    }
    else
    {
      summands[summands.size() - 1] += n - sum;
      sum = n;
    }
  }

  return summands;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i)
  {
    std::cout << summands[i] << ' ';
  }
  return 0;
}
