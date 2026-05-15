#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/check-if-array-is-good/description/
  Runtime: 100.00%
  Memory: 85.57%
******************************************/

bool isGood(vector<int> &nums) {
  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size() - 1; ++i)
    if (nums[i] != i + 1)
      return false;

  if (nums.size() != nums.back() + 1 || nums.back() != nums[nums.size() - 1])
    return false;

  return true;
}

int main() { return 0; }
