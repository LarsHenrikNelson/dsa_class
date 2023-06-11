#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class JobQueue {
 private:
  long long num_workers_;
  vector<long long> jobs_;

  vector<long long> assigned_workers_;
  vector<long long> start_times_;
  vector< pair<long long, long long> > heap_;


  void WriteResponse() const {
    for (long long i = 0; i < static_cast<long long>(jobs_.size()); ++i) {
      cout << assigned_workers_.at(i) << " " << start_times_.at(i) << "\n";
    }
  }

  void ReadData() {
    long long m;
    cin >> num_workers_ >> m;
    if (m < num_workers_)
    {
      num_workers_ = m;
    }
    jobs_.resize(m);
    assigned_workers_.resize(m);
    start_times_.resize(m);
    heap_.resize(num_workers_);
    for(long long i = 0; i < m; ++i)
      cin >> jobs_.at(i);
  }

  void SiftDown(long long index)
  {
    long long min_index = index;
    long long left_child = index*2+1;
    long long right_child = index*2+2;
    if (left_child < static_cast<long long>(heap_.size()) && right_child < static_cast<long long>(heap_.size()) && heap_.at(left_child).first > heap_.at(right_child).first && heap_.at(left_child).second == heap_.at(right_child).second)
    {
      // cout << "swapped\n";
      swap(heap_.at(left_child), heap_.at(right_child));

    }   
    if (left_child < static_cast<long long>(heap_.size()) && heap_.at(left_child).second < heap_.at(min_index).second)
    {
      min_index = left_child;
    }
    if (left_child < static_cast<long long>(heap_.size()) && heap_.at(left_child).second == heap_.at(min_index).second && heap_.at(left_child).first < heap_.at(min_index).first)
    {
      min_index = left_child;
    }
    if (right_child < static_cast<long long>(heap_.size()) &&  heap_.at(right_child).second < heap_.at(min_index).second)
    {
      min_index = right_child;
    }
    if (index != min_index)
    {
      swap(heap_.at(index), heap_.at(min_index));
      SiftDown(min_index);
    }
  }

  void AssignJobs() {
    for (long long i = 0; i < num_workers_; ++i)
    {
      assigned_workers_.at(i) = i;
      start_times_.at(i) = 0;
      heap_.at(i) = make_pair(i, jobs_.at(i));
    }
    for (size_t i = (heap_.size()/2); i > 0; --i)
    {
      SiftDown(i-1);
    }
    for (long long i = num_workers_; i < static_cast<long long>(jobs_.size()); ++i)
    {
      // cout << "start " << i << "\n";
      // for (auto &i: heap_)
      // {
      //   cout << i.first << "\n";
      // } 
      assigned_workers_.at(i) = heap_.at(0).first;
      start_times_.at(i) = heap_.at(0).second;
      heap_.at(0).second += jobs_.at(i);
      SiftDown(0);

    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
    
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
