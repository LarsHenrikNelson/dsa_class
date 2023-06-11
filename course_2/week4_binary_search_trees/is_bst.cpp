#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <tuple>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::stack;

struct Node {
  int key;
  int left;
  int right;

  // Default node constructor
  Node() : key(0), left(-1), right(-1) {}

  // Constructor with parameters
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool inorder(const vector<Node>& tree, int node, int& index, vector<int>& results, bool& output, bool& type) {
  if (node != -1) {
    type = true;
    output = inorder(tree, tree.at(node).left, index, results, output, type);
    results.at(index) = tree.at(node).key;
    if (index > 0) {
      if (results.at(index) < results.at(index-1)) {
        output = false;
        return output;
      }
      if (results.at(index) == results.at(index-1) && !type) {
        output = false;
        return output;
      }
    }
    ++index;
    type = false;
    output = inorder(tree, tree.at(node).right, index, results, output, type);
  }
  return output;
}

bool IsBinarySearchTree(const vector<Node>& tree) {
    if (tree.size() < 2) {
      return true;
    }
    vector<int> results (tree.size());
    int index {0};
    bool output {true};
    int node {0};
    bool type {true};
    output = inorder(tree, node, index, results, output, type);
  return output;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
