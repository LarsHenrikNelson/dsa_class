#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <limits>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  vector<int> dist(adj.size(), std::numeric_limits<int>::max());

  dist.at(s) = 0;

  auto cmp = [](std::pair<int, int> left, std::pair<int, int> right) { return (left.second) > (right.second); };
  priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, decltype(cmp)> h(cmp);
  for(size_t i = 0; i < adj.size(); ++i)
  {
    h.push(std::make_pair(i, dist.at(i)));
  }

  while(!h.empty())
  {
    std::pair<int, int> u = h.top();
    h.pop();
    for (size_t i = 0; i < adj.at(u.first).size(); ++i)
    {
      int v = adj.at(u.first).at(i);
      if (dist.at(u.first) != std::numeric_limits<int>::max() && dist.at(v) > (dist.at(u.first) + cost.at(u.first).at(i)))
      {
        dist.at(v) = dist.at(u.first) + cost.at(u.first).at(i);
        h.push(std::make_pair(v, dist.at(v)));
      }
    }
  }
  if (dist.at(t) == std::numeric_limits<int>::max())
  {
    return -1;
  }
  return dist.at(t);
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
