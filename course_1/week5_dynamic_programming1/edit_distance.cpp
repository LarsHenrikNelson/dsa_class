#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;

int edit_distance(const string &str1, const string &str2)
{
  std::vector<std::vector<int>> grid(str1.size() + 1, std::vector<int>(str2.size() + 1));

  int ins{0};
  int del{0};
  int mat{0};
  int mis{0};

  for (size_t i = 0; i <= str2.size(); ++i)
  {
    grid[0][i] = i;
  }

  for (size_t i = 0; i < grid.size(); ++i)
  {
    grid[i][0] = i;
  }

  for (size_t i = 1; i < grid.size(); ++i)
  {
    for (size_t j = 1; j < grid.at(i).size(); ++j)
    {
      ins = grid[i][j - 1] + 1;
      del = grid[i - 1][j] + 1;
      mat = grid[i - 1][j - 1];
      mis = grid[i - 1][j - 1] + 1;

      if (str1.at(i - 1) == str2.at(j - 1))
      {
        grid[i][j] = std::min({ins, del, mat});
      }
      else
      {
        grid[i][j] = std::min({ins, del, mis});
      }
    }
  }

  return grid[str1.size()][(str2.size())];
}

// int out_align(const std::vector<std::vector<int>> &matrix, const )
// {
//   int dist {0};
//   while (i >= 0 && j >= 0)
//   {
//     if (i > 0 && matrix.at(i).at(j) == matrix.at(i-1).at(j)+1)
//       dist += matrix.at(i).at(j);
//   }

// }

int main()
{
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
