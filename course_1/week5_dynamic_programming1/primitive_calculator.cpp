#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<long long> optimal_sequence(long long n)
{
  std::vector<long long> sequence(n + 1);
  sequence.at(0) = 0;
  sequence.at(1) = 0;
  for (long long i = 2; i < n + 1; ++i)
  {
    sequence.at(i) = sequence.at(i - 1) + 1;
    if (i % 2 == 0)
    {
      sequence.at(i) = std::min({sequence.at(i / 2) + 1, sequence.at(i)});
    }
    if (i % 3 == 0)
    {
      sequence.at(i) = std::min({sequence.at(i / 3) + 1, sequence.at(i)});
    }
  }

  vector<long long> output;
  long long j = n;
  output.push_back(n);
  while (j > 1)
  {
    if (j % 3 == 0 && (sequence[j / 3] == sequence[j] - 1))
    {
      j = j / 3;
      output.push_back(j);
    }
    else if (j % 2 == 0 && (sequence[j / 2] == sequence[j] - 1))
    {
      j = j / 2;
      output.push_back(j);
    }
    else
    {
      j = j - 1;
      output.push_back(j);
    }
  }
  std::reverse(output.begin(), output.end());
  return output;
}

int main()
{
  long long n;
  std::cin >> n;
  vector<long long> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i)
  {
    std::cout << sequence[i] << " ";
  }
}
