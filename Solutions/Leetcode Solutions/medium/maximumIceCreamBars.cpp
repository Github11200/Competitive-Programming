#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/maximum-ice-cream-bars/description/
  Runtime: 50.26%
  Memory: 60.91%
******************************************/

int maxIceCream(vector<int> &costs, int coins) {
  sort(costs.begin(), costs.end());
  int iceCream = 0;
  for (int i = 0; i < costs.size(); ++i) {
    coins -= costs[i];
    if (coins < 0)
      break;
    ++iceCream;
  }

  return iceCream;
}

int main() { return 0; }
