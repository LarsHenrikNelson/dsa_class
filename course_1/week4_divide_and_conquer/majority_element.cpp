#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right)
{
  // if (left == right) return -1;
  // if (left + 1 == right) return a[left];
  std::unordered_map<long, int> map;
  map.reserve(a.size());
  int min_size = a.size() / 2;
  for (size_t i = 0; i < a.size(); i++)
  {
    if (map.find(a[i]) != map.end())
    {
      map[a[i]] += 1;
      if (map[a[i]] >= min_size)
      {
        return 1;
      }
    }
    else
    {
      map[a[i]] = 0;
    }
  }

  // write your code here
  return -1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
