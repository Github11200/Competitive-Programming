#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/valid-triangle-number/description/
  Runtime: 13.82%
  Memory: 46.73%
******************************************/

int triangleNumber(vector<int> &nums) {
  if (nums.size() < 3)
    return 0;

  sort(nums.begin(), nums.end());

  int n = 0;
  for (int i = 0; i < nums.size() - 2; ++i) {
    for (int j = i + 1; j < nums.size() - 1; ++j) {
      if (nums[i] == 0 || nums[j] == 0)
        continue;

      int sum = nums[i] + nums[j];
      auto it = lower_bound(nums.begin(), nums.end(), sum) - 1;

      int index = distance(nums.begin(), it);
      n += index - j;
    }
  }

  return n;
}

// 2, 2, 3, 4

int main() {
  vector<int> test({0, 0, 0});
  triangleNumber(test);
  return 0;
}
