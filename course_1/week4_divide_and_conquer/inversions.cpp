#include <iostream>
#include <vector>

using std::vector;

long long merge(vector<int> &a, size_t left, size_t ave, size_t right, vector<int> &b)
{
  long long swaps{0};
  size_t n_1 = left;
  size_t n_2 = ave + 1;
  size_t k = left;
  for (int i = n_1; i <= right; ++i)
  {
    b[i] = a[i];
  }

  // vector<int> t1(n_1);
  // vector<int> t2(n_2);

  // int a_i = 0;
  // int b_i = 0;
  // int k_i = left;

  // for (int i{0}; i < n_1; ++i)
  // {
  //   t1[i] = a[left + i];
  // }
  // for (int i{0}; i < n_1; ++i)
  // {
  //   t2[i] = a[ave + 1 + i];
  // }

  while (n_1 <= ave && n_2 <= right)
  {
    if (b[n_1] <= b[n_2])
    {
      a[k] = b[n_1];
      ++n_1;
    }
    else
    {
      a[k] = b[n_2];
      swaps += n_2 - k;
      ++n_2;
    }
    ++k;
  }

  while (n_1 <= ave)
  {
    a[k] = b[n_1];
    k++;
    n_1++;
  }

  while (n_2 <= right)
  {
    a[k] = b[n_2];
    ++k;
    ++n_2;
  }
  return swaps;
}

long long get_number_of_inversions(vector<int> &a, size_t left, size_t right, vector<int> &b)
{
  long long number_of_inversions = 0;
  if (left >= right)
  {
    // std::cout << "early return" << left << " " << right << "\n";
    return number_of_inversions;
  }
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, left, ave, b);
  number_of_inversions += get_number_of_inversions(a, ave + 1, right, b);
  number_of_inversions += merge(a, left, ave, right, b);

  return number_of_inversions;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  vector<int> b(n);
  std::cout << get_number_of_inversions(a, 0, a.size() - 1, b) << '\n';
  // for (auto &i : a)
  // {
  //   std::cout << i << " ";
  // }
  // std::cout << "\n";
}
