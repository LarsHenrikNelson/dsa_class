#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

double get_optimal_value(long long capacity, std::vector<long long> weights, std::vector<long long> values)
{
  double value = 0.0;
  std::vector<long long> indexes(values.size());
  std::iota(indexes.begin(), indexes.end(), 0);
  std::sort(indexes.begin(), indexes.end(), [&](long long i, long long j)
            { return (static_cast<double>(values[i]) / static_cast<double>(weights[i])) > (static_cast<double>(values[j]) / static_cast<double>(weights[j])); });
  for (auto &i : indexes)
  {
    if (capacity >= 0)
    {
      long long amount = std::min(capacity, weights[i]);
      // std::cout << "Capacity: " << capacity << "\n";
      double temp = static_cast<double>(amount) / static_cast<double>(weights[i]);
      // std::cout << "Temp: " << temp << "\n";
      value += static_cast<double>(values[i]) * temp;
      // std::cout << "Value :" << value << "\n";
      capacity -= amount;
    }
  }
  return value;
}

int main()
{
  long long n;
  long long capacity;
  std::cin >> n >> capacity;
  std::vector<long long> values(n);
  std::vector<long long> weights(n);
  for (long long i = 0; i < n; i++)
  {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
