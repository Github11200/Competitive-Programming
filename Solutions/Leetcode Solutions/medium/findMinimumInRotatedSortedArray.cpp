#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
  Runtime: 100.0%
  Memory: 97.70%
******************************************/

int findMin(vector<int> &nums) {
  int low = 0;
  int high = nums.size() - 1;

  while (low < high) {
    int mid = (low + high) / 2;

    if (nums[mid] > nums[high])
      low = mid + 1;
    else
      high = mid;
  }

  return nums[low];
}

int main() { return 0; }
