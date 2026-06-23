#include <bits/stdc++.h>
#include <climits>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/description/
  Runtime: 100.00%
  Memory: 84.03%
******************************************/

int minCostToMoveChips(vector<int> &position) {
  int minNumberOfOnes = INT_MAX;

  for (int i = 0; i < position.size(); ++i) {
    int numberOfOnes = 0;
    for (int j = 0; j < position.size(); ++j) {
      if (i == j)
        continue;
      if (abs(position[j] - position[i]) % 2 != 0)
        ++numberOfOnes;
    }

    minNumberOfOnes = min(minNumberOfOnes, numberOfOnes);
  }

  return minNumberOfOnes;
}

int main() { return 0; }
