#include <bits/stdc++.h>
#include <string>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/summary-ranges/description/
  Runtime: 100.0%
  Memory: 74.56%
******************************************/

vector<string> summaryRanges(vector<int> &nums) {
  if (nums.size() == 0)
    return vector<string>();

  int start = nums[0];
  vector<string> ranges;
  for (int i = 1; i < nums.size(); ++i) {
    if (static_cast<long long>(nums[i]) - nums[i - 1] == 1)
      continue;

    if (nums[i - 1] == start)
      ranges.push_back(to_string(nums[i - 1]));
    else
      ranges.push_back(to_string(start) + "->" + to_string(nums[i - 1]));

    start = nums[i];
  }

  if (nums.back() != start)
    ranges.push_back(to_string(start) + "->" + to_string(nums.back()));
  else
    ranges.push_back(to_string(nums.back()));

  return ranges;
}

int main() { return 0; }
