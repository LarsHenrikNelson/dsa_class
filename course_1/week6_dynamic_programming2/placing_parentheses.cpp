#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <limits>
#include <utility>
#include <tuple>
#include <algorithm>

using std::max;
using std::min;
using std::string;
using std::vector;

long long eval(long long a, long long b, char op)
{
  if (op == '*')
  {
    return a * b;
  }
  else if (op == '+')
  {
    return a + b;
  }
  else if (op == '-')
  {
    return a - b;
  }
  else
  {
    assert(0);
  }
}

std::tuple<long long, long long> max_and_min(long long i, long long j, std::vector<std::vector<long long>> &M, std::vector<std::vector<long long>> &m, string &ops)
{
  long long a{};
  long long b{};
  long long c{};
  long long d{};
  long long max_num = std::numeric_limits<long long>::min();
  long long min_num = std::numeric_limits<long long>::max();

  for (long long k = i; k < j; ++k)
  {
    // std::cout << "M[i][k]: " << M[i][k] << " M[k + 1][j]: " << M[k + 1][j] << "\n";
    a = eval(M[i][k], M[k + 1][j], ops[k]);
    b = eval(M[i][k], m[k + 1][j], ops[k]);
    c = eval(m[i][k], M[k + 1][j], ops[k]);
    d = eval(m[i][k], m[k + 1][j], ops[k]);
    long long min_temp = min({min_num, a, b, c, d});
    long long max_temp = max({max_num, a, b, c, d});
    min_num = min_temp;
    max_num = max_temp;
  }
  return std::tuple<long long, long long>(min_num, max_num);
}

long long get_maximum_value(const string &exp)
{
  string ops{};
  for (size_t i = 1; i < exp.length(); i += 2)
  {
    ops.push_back(exp.at(i));
  }
  string nums{};
  for (size_t i = 0; i < exp.length(); i += 2)
  {
    nums.push_back(exp.at(i));
  }
  vector<vector<long long>> M(nums.length(), vector<long long>(nums.length()));
  vector<vector<long long>> m(nums.length(), vector<long long>(nums.length()));
  for (size_t i = 0; i < nums.length(); ++i)
  {
    M[i][i] = static_cast<long long>(nums[i]) - 48;
    m[i][i] = static_cast<long long>(nums[i]) - 48;
  }
  // for (size_t i = 0; i < nums.length(); ++i)
  // {
  //   std::cout << "\n";
  //   for (size_t j = 0; j < nums.length(); ++j)
  //   {
  //     std::cout << M[i][j] << " ";
  //   }
  // }
  long long temp_min{};
  long long temp_max{};
  for (size_t s = 1; s < nums.length(); ++s)
  {
    for (size_t i = 0; i < nums.length() - s; ++i)
    {
      int j = static_cast<int>(i) + static_cast<int>(s);
      std::tie(temp_min, temp_max) = max_and_min(i, j, M, m, ops);
      M[i][j] = temp_max;
      m[i][j] = temp_min;
    }
  }

  return max(m[0][nums.length() - 1], M[0][nums.length() - 1]);
  // for (size_t i = 0; i < nums.length(); ++i)
  // {
  //   std::cout << "\n";
  //   for (size_t j = 0; j < nums.length(); ++j)
  //   {
  //     std::cout << M[i][j] << " ";
  //   }
  // }
}

int main()
{
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
