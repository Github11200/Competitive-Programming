#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/maximum-number-of-balloons/description/
  Runtime: 100.00%
  Memory: 84.03%
******************************************/

int maxNumberOfBalloons(string text) {
  unordered_map<char, int> count;

  for (char c : text) {
    if (c != 'b' && c != 'a' && c != 'l' && c != 'o' && c != 'n')
      continue;
    count[c]++;
  }

  if (count.size() < 5)
    return 0;

  int maxBalloons = INT_MAX;
  for (auto item : count) {
    int maxNum = item.second;
    if (item.first == 'l' || item.first == 'o')
      maxNum /= 2;
    maxBalloons = min(maxNum, maxBalloons);
  }
  return maxBalloons;
}

int main() {
  maxNumberOfBalloons("nlaebolko");
  return 0;
}
