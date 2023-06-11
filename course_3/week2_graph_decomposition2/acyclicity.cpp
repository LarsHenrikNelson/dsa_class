#include <iostream>
#include <vector>

using std::vector;
using std::pair;

struct Graph
{
  Graph(size_t n): previsit(n), postvisit(n), visited(n), adj(n) {}
  vector<bool> previsit {};  
  vector<bool> postvisit {};
  vector<bool> visited {};
  vector<vector<int>> adj {};
  bool cycle {false};
  int visit_count {0};
};

// void dfs(Graph &data);
void explore(Graph &data, int node);

void explore(Graph &data, int node) {
  if (data.previsit.at(node)) {
    data.cycle = true;
    return;
  }
  data.previsit.at(node) = true;
  data.visited.at(node) = true;
  for (auto &neigh: data.adj.at(node)) {
    if (!data.postvisit.at(neigh)) {
      explore(data, neigh);
    }
  }
  data.postvisit.at(node) = true;
}

// void dfs(Graph& data) {
//   for (size_t i = 0; i < data.adj.size(); ++i) {
//     if (!data.visited.at(i)) {
//       explore(data, i);
//     }
//   }
// }

int acyclic(Graph& data) {
  for (size_t i = 0; i < data.adj.size(); ++i) {
    if (!data.visited.at(i)) {
      explore(data, i);
    }
  }
  return data.cycle;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  Graph data {n};
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    data.adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(data);
  return 0;
}
