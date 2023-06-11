#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

struct Graph
{
  Graph(size_t n): previsit(n), postvisit(n), visited(n), adj(n) {}
  vector<int> previsit {};  
  vector<int> postvisit {};
  vector<bool> visited {};
  vector<vector<int>> adj {};
  int visit_count {1};
  vector<int> sorted {};
};

void explore(Graph &data, int node);

void explore(Graph &data, int node) {
  if (data.postvisit.at(node) > 0) {
    return;
  }
  data.previsit.at(node) = data.visit_count;
  ++data.visit_count;
  data.visited.at(node) = true;
  for (auto &neigh: data.adj.at(node)) {
    if (!data.visited.at(neigh)) {
      explore(data, neigh);
    }
  }
  data.postvisit.at(node) = data.visit_count;
  data.sorted.push_back(node);
  ++data.visit_count;
}

// void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order, int x) {
//   //write your code here
// }     

void toposort(Graph& data) {
  for (size_t i = 0; i < data.adj.size(); ++i) {
    if (!data.postvisit.at(i)) {
      explore(data, i);
    }
  }
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  Graph data {n};
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    data.adj.at(x - 1).push_back(y - 1);
  }
  toposort(data);
  for (int i = static_cast<int>(data.sorted.size()-1); i >= 0; --i) {
    std::cout << data.sorted.at(i) + 1 << " ";
  }
}
