#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/gas-station/description/
  Runtime: 59.12%
  Memory: 16.20%
******************************************/

bool asteroidsDestroyed(int mass, vector<int> &asteroids) {
  sort(asteroids.begin(), asteroids.end());

  auto it = upper_bound(asteroids.begin(), asteroids.end(), mass);
  if (it == asteroids.end())
    it = asteroids.begin();
  else if (*it > mass) {
    if (it == asteroids.begin())
      return false;
    --it;
  }

  int index = distance(asteroids.begin(), it);
  mass += asteroids[index];

  long long bigMass = static_cast<long long>(mass);
  for (int i = 0; i < asteroids.size(); ++i) {
    if (i == index)
      continue;

    if (bigMass < asteroids[i])
      return false;
    bigMass += asteroids[i];
  }

  return true;
}

int main() { return 0; }
