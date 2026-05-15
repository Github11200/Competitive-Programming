#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/wiggle-sort-ii/description/
  Runtime: 100.00%
  Memory: 44.10%
******************************************/

void wiggleSort2(vector<int> &nums) {
  sort(nums.begin(), nums.end());

  if (nums.size() == 2)
    return;

  vector<int> newNums(nums.size());

  int j = nums.size() - 1;
  for (int i = 1; i < nums.size(); i += 2, --j)
    newNums[i] = nums[j];

  j = nums.size() / 2;
  if (nums.size() % 2 == 0)
    --j;
  for (int i = 0; i < nums.size(); i += 2, --j)
    newNums[i] = nums[j];

  nums = newNums;
}

int main() {
  vector<int> test({4, 5, 5, 6});
  wiggleSort2(test);
  return 0;
}
