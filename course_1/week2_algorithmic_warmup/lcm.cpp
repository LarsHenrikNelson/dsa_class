#include <iostream>

long long lcm_naive(int a, int b)
{
  for (long l = 1; l <= (long long)a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long)a * b;
}

int gcd_fast(int a, int b)
{
  if (a % b == 0)
  {
    return b;
  }
  else
  {
    return gcd_fast(b, a % b);
  }
}

long long lcm_fast(long long a, long long b)
{
  long long gcd = gcd_fast(a, b);
  return (a * b) / gcd;
}

int main()
{
  long long a, b;
  std::cin >> a >> b;
  // std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
