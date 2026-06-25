#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/description/
  Runtime: 100.00%
  Memory: 78.90%
******************************************/

int minimumCost(vector<int> &cost) {
  sort(cost.begin(), cost.end(), greater<int>());

  int c = 0;
  for (int i = 0; i < cost.size(); ++i) {
    if ((i + 1) % 3 == 0)
      continue;
    c += cost[i];
  }

  return c;
}

int main() { return 0; }
