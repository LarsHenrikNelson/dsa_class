#include <iostream>
#include <vector>
using std::vector;
using std::pair;

void explore(vector<bool> &visited, vector<vector<int> > &adj, int node) {
  visited.at(node) = true;
  for (auto &neigh: adj.at(node)) {
    if (!visited.at(neigh)) {
      explore(visited, adj, neigh);
    }
  }
}

int number_of_components(vector<vector<int> > &adj) {
  int comps {0};
  vector<bool> visited(adj.size(), false);
  for (size_t i = 0; i < adj.size(); ++i) {
    if (!visited.at(i)) {
      ++comps;
      explore(visited, adj, i);
    }
  }
  return comps;
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
  std::cout << number_of_components(adj);
}
