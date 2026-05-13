#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/jump-game/description/
  Runtime: 100.00%
  Memory: 81.48%
******************************************/

bool canJump(vector<int> &nums) {
  int jumps = nums[0];

  for (int i = 0; i < nums.size(); ++i) {
    jumps = max(jumps, nums[i]);
    if (i < nums.size() - 1 && jumps <= 0)
      return false;
    --jumps;
  }

  return true;
}

int main() {
  vector<int> test({2, 3, 1, 1, 4});
  canJump(test);
  return 0;
}
