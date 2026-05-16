#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description
  Runtime: 100.0%
  Memory: 27.34%
******************************************/

int findMin(vector<int> &nums) {
  int l = 0, r = nums.size() - 1;
  while (l <= r) {
    int m = (l + r) / 2;

    if (nums[m] == nums[l] && nums[m] == nums[r])
      return *min_element(nums.begin() + l, nums.begin() + r);
    if (nums[m] > nums[r])
      l = m + 1;
    else
      r = m;
  }

  return nums[l];
}

int main() { return 0; }
