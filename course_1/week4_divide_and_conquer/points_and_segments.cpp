#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using std::tuple;
using std::vector;

void merge(vector<tuple<int, int, int>> &a, size_t left, size_t ave, size_t right, vector<tuple<int, int, int>> &b)
{
  long long swaps{0};
  size_t n_1 = left;
  size_t n_2 = ave + 1;
  size_t k = left;
  for (int i = n_1; i <= right; ++i)
  {
    b[i] = a[i];
  }

  while (n_1 <= ave && n_2 <= right)
  {
    if (std::get<0>(b[n_1]) <= std::get<0>(b[n_2]))
    {
      a[k] = b[n_1];
      ++n_1;
    }
    else
    {
      a[k] = b[n_2];
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
}

void merge_sort(vector<tuple<int, int, int>> &a, size_t left, size_t right, vector<tuple<int, int, int>> &b)
{
  long long number_of_inversions = 0;
  if (left >= right)
  {
    // std::cout << "early return" << left << " " << right << "\n";
    return;
  }
  size_t ave = left + (right - left) / 2;
  merge_sort(a, left, ave, b);
  merge_sort(a, ave + 1, right, b);
  merge(a, left, ave, right, b);
}

bool sort_mod(const tuple<int, int, int> &t1, const tuple<int, int, int> &t2)
{
  if (std::get<0>(t1) < std::get<0>(t2) && std::get<1>(t1) < std::get<1>(t2))
  {
    return true;
  }
  else
  {
    return false;
  }
}

vector<int> fast_count_segments(vector<tuple<int, int, int>> &segments, int points)
{
  vector<int> cnt(points);
  std::sort(segments.begin(), segments.end(), sort_mod);
  int count{0};
  for (auto &seg : segments)
  {
    if (std::get<1>(seg) == 2)
    {
      cnt[std::get<2>(seg)] = count;
    }
    else if (std::get<1>(seg) == 1)
    {
      ++count;
    }
    else
    {
      --count;
    }
  }

  return cnt;
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  vector<tuple<int, int, int>> segments((2 * n) + m);
  int start{0};
  int end{0};
  int i{0};
  for (int i{0}; i < n; ++i)
  {
    std::cin >> start >> end;
    segments[i] = std::make_tuple(start, 1, -1);
    segments[n + m + i] = std::make_tuple(end, 3, -1);
  }
  int point{0};
  for (size_t j = 0; j < m; j++)
  {
    std::cin >> point;
    segments[j + n] = std::make_tuple(point, 2, j);
  }
  // std::sort(segments.begin(), segments.end(), sort_mod);
  vector<tuple<int, int, int>> b((2 * n) + m);
  merge_sort(segments, 0, segments.size() - 1, b);
  vector<int> cnt = fast_count_segments(segments, m);
  for (size_t i = 0; i < cnt.size(); i++)
  {
    std::cout << cnt[i] << ' ';
  }
  return 0;
}