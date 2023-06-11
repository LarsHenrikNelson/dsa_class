#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;


class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }
  
  void SiftDown(size_t index)
  {
    size_t min_index = index;
    size_t left_child = index*2+1;
    if (left_child < data_.size() && data_.at(left_child) < data_.at(min_index))
    {
      min_index = left_child;
    }
    size_t right_child = index*2+2;
    if (right_child < data_.size() && data_.at(right_child) < data_.at(min_index))
    {
      min_index = right_child;
    }
    if (data_.at(right_child) == data_.at(left_child) && data_.at(left_child) < data_.at(min_index))
    {
      min_index = left_child;
    }
    if (index != min_index)
    {
      swap(data_.at(index), data_.at(min_index));
      swaps_.push_back(make_pair(index, min_index));
      SiftDown(min_index);
    }
  }

  void GenerateSwaps() {
    swaps_.clear();
    for (size_t i = (data_.size()/2); i > 0; --i)
    {
      SiftDown(i-1);
    }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
