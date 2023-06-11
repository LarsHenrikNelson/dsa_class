#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::pair;
using std::stack;

void explore(vector<bool> &visited, vector<vector<int> > &adj, int node) {
  visited.at(node) = true;
  for (auto &neigh: adj.at(node)) {
    if (!visited.at(neigh)) {
      explore(visited, adj, neigh);
    }
  }
}

int reach(vector<vector<int> > &adj, int x, int y) {
  if (adj.at(x).size() == 0 || adj.at(y).size() == 0) {
    return 0;
  }
  vector<bool> visited(adj.size(), false);
  explore(visited, adj, x);
  if (visited.at(y)) {
    return 1;
  }
  else {
    return 0;
  }
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
