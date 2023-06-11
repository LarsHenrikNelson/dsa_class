#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::stack;
using std::ios_base;
using std::cin;
using std::cout;
using std::string;

void post_order_func(int a, vector <int> &key, vector <int> &left, vector <int> &right, vector <int> &result);

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }


  vector <int> in_order() {
    vector<int> result (key.size());
    stack<int> node_stack;
    int results_index {0};
    int node {0}; 
    int parent_node {0};
    while (!node_stack.empty() || node != -1)
    {
      if (node != -1)
      {
        node_stack.push(node);
        parent_node = node;
        node = left.at(node);
      }
      else
      {
        int temp = node_stack.top();
        result.at(results_index) = key.at(temp);
        node_stack.pop();
        if (!node_stack.empty())
        {
          parent_node = node_stack.top();
        }
        else
        {
          parent_node = -1;
        }
        node = right.at(temp);
        ++results_index;
      }
    }

    return result;
  }

  vector <int> pre_order() {
    vector<int> result (key.size());
    stack<int> node_stack;
    node_stack.push(0);
    int node {0};
    int results_index {0};
    while (!node_stack.empty())
    {
      node = node_stack.top();
      node_stack.pop();
      result.at(results_index) = key.at(node);
      ++results_index;
      if (right.at(node) != -1)
      {
        node_stack.push(right.at(node));
      }
      if (left.at(node) != -1)
      {
        node_stack.push(left.at(node));
      }
    }
    

    return result;
  }

  vector <int> post_order() {
    vector<int> result;
    post_order_func(0, key, left, right, result);
    return result;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

void post_order_func(int a, vector <int> &key, vector <int> &left, vector <int> &right, vector <int> &result) {
  if (a != -1)
  {
    post_order_func(left.at(a), key, left, right, result);
    post_order_func(right.at(a), key, left, right, result);
    result.push_back(key.at(a));
  }
  
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}