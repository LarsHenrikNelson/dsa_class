#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int partition3(vector<int> &A)
{
  std::sort(A.begin(), A.end());
  if (A.size() < 3)
  {
    return 0;
  }
  int sum{0};
  for (auto &i : A)
  {
    sum += i;
  }
  if (sum % 3 != 0 || A[A.size() - 1] > sum / 3)
  {
    return 0;
  }
}

bool

    int
    main()
{
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i)
  {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
