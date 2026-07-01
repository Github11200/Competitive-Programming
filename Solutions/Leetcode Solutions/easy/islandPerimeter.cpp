#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/island-perimeter/description/
  Runtime: 36.55%
  Memory: 98.27%
******************************************/

#define Pair pair<int, int>

bool isValidPosition(Pair p, vector<vector<int>> &grid) {
  if (p.first < 0 || p.second < 0 || p.first >= grid.size() || p.second >= grid[0].size())
    return false;
  return true;
}

int islandPerimeter(vector<vector<int>> &grid) {
  int perimeter = 0;

  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[i].size(); ++j) {
      if (!grid[i][j])
        continue;

      Pair curr(i, j);
      Pair positions[4] = {
          Pair(curr.first - 1, curr.second),
          Pair(curr.first + 1, curr.second),
          Pair(curr.first, curr.second - 1),
          Pair(curr.first, curr.second + 1),
      };

      int currentPerimeter = 4;
      for (auto position : positions)
        if (isValidPosition(position, grid) && grid[position.first][position.second])
          --currentPerimeter;

      perimeter += currentPerimeter;
    }
  }

  return perimeter;
}

int main() { return 0; }
