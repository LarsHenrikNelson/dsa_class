#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using std::string;
using std::vector;

bool larger(const std::string a, const std::string b)
{
  for (auto const &i : a)
    for (auto const &j : b)
    {
      if (static_cast<int>(i) - 48 > static_cast<int>(j) - 48)
        return true;
    }
  return false;
}

string largest_number(vector<string> a)
{
  // write your code here
  if (a.size() == 1)
  {
    string result{a[0]};
    return result;
  }
  std::sort(a.begin(), a.end(), larger);
  std::string result = std::accumulate(a.begin(), a.end(), std::string(""));
  return result;
}

int main()
{
  int n{0};
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
