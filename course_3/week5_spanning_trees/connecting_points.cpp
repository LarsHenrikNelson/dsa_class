#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
#include <unordered_set>

using std::vector;
using std::queue;
using std::priority_queue;

void set_sets(std::unordered_set<int>& us, vector<std::unordered_set<int>>& nodes)
{
  for (auto& j: us)
  {
    nodes.at(j) = us;
  }
}

struct Connection
{
  std::tuple<int, int, int> point1;
  std::tuple<int, int, int> point2;
  double distance;
};

double minimum_distance(vector<int> x, vector<int> y) {

  auto cmp = [](const Connection& left,const Connection& right) { return (left.distance) > (right.distance); };
  priority_queue<Connection, std::vector<Connection>, decltype(cmp)> qu(cmp);

  vector<std::unordered_set<int>> nodes(x.size());
  for (size_t i = 0; i < x.size(); ++i)
  {
    nodes.at(i).insert(i);
  }

  double result = 0.;
  for (size_t i = 0; i < x.size()-1; ++i)
  {
    std::tuple<int, int, int> connection1 {i, x.at(i), y.at(i)};
    for (size_t j = i+1; j < x.size(); ++j)
    {
      std::tuple<int, int, int> connection2 {j, x.at(j), y.at(j)};
      double sx = (static_cast<double>(x.at(j))-static_cast<double>(x.at(i)));
      double sy = (static_cast<double>(y.at(j))-static_cast<double>(y.at(i)));
      double distance = std::sqrt((sx*sx) + (sy*sy));
      Connection con {connection1, connection2, distance};
      qu.push(con);

    }
  }
  size_t len = qu.size();
  for (size_t i = 0; i < len; ++i)
  {
    Connection temp = qu.top();
    qu.pop();
    size_t a = nodes.at(std::get<0>(temp.point1)).count(std::get<0>(temp.point2));
    size_t b = nodes.at(std::get<0>(temp.point2)).count(std::get<0>(temp.point1));
    if (a < 1 && b < 1)
    {
      std::unordered_set<int> p;
      p.insert(nodes.at(std::get<0>(temp.point1)).begin(), nodes.at(std::get<0>(temp.point1)).end());
      p.insert(nodes.at(std::get<0>(temp.point2)).begin(), nodes.at(std::get<0>(temp.point2)).end());
      set_sets(p, nodes);

      result += temp.distance;
    }
  }
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
