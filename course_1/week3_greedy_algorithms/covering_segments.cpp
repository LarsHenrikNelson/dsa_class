#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment
{
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments)
{
  vector<int> points;
  std::sort(segments.begin(), segments.end(), [](const Segment &lhs, const Segment &rhs)
            { return lhs.start < rhs.start; });
  long long points_index{0};
  points.push_back(segments[0].end);
  for (size_t i = 1; i < segments.size(); ++i)
  {
    if (segments[i].start <= points[points_index])
    {
      if (segments[i].end < points[points_index])
      {
        points[points_index] = segments[i].end;
      }
    }
    else
    {
      ++points_index;
      points.push_back(segments[i].end);
    }
  }
  return points;
}

int main()
{
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i)
  {
    std::cin >> segments[i].start >> segments[i].end;
  }
  // std::sort(segments.begin(), segments.end(), [](const Segment &lhs, const Segment &rhs)
  //           { return lhs.start < rhs.start; });
  // for (auto const &i : segments)
  // {
  //   std::cout << i.start << " ";
  // }
  // std::cout << "\n";
  // return 0;
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i)
  {
    std::cout << points[i] << " ";
  }
  return 0;
}
