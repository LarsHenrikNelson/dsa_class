#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  vector<int> dist(adj.size(), 0);
  vector<bool> visited(adj.size(), false);
  queue<int> q;
  q.push(s);
  visited.at(s) = true;
  int node {s};
  while (!q.empty())
  {
    node = q.front();
    q.pop();
    for (auto &n: adj.at(node)) 
    {
      if (!visited.at(n))
      {
        q.push(n);
        visited.at(n) = true;
        dist.at(n) = dist.at(node) + 1;

        if (n == t)
        {
          return dist.at(node) +1;
        }
      }
    }
  }
  
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
