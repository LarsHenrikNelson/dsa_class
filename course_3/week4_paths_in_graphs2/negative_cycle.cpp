#include <iostream>
#include <vector>
#include <limits>

using std::vector;

int bellmanford(vector<vector<int> > &adj, vector<vector<long long> > &cost)
{
  vector<long long> dist(adj.size(), 0);
  vector<bool> visited(adj.size(), false);
  for (size_t t = 0; t < adj.size(); ++t)
  {
    for (size_t i = 0; i < adj.size(); ++i)
    {
      for (size_t j = 0; j < adj.at(i).size(); ++j)
      {
        int v = adj.at(i).at(j);
        if (dist.at(v) > (dist.at(i) + cost.at(i).at(j)))
        {
          if (t == adj.size()-1)
          {
            return 1;
          }
          dist.at(v) = dist.at(i) + cost.at(i).at(j);
          visited.at(v) = true;
        }
      }
    }
  }
  return 0;
}

// int negcycle(vector<vector<int> > &adj, vector<vector<long long> > &cost)
// {
//   vector<long long> dist(adj.size(), std::numeric_limits<long long>::max());
//   vector<bool> visited(adj.size(), false);
//   for (size_t i = 0; i < adj.size(); ++i)
//   {
//     if (visited.at(i) == false)
//     {
//       visited.at(i) = true;
//       int ret_value = bellmanford(adj, cost, i, visited, dist);
      
//       if (ret_value == 1)
//       {
//         return 1;
//       }
//     }
//   }
//   return 0;
// }

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<long long> > cost(n, vector<long long>());
  for (int i = 0; i < m; i++) {
    int x, y;
    long long w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << bellmanford(adj, cost);
}
