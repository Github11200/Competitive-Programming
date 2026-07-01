#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/merge-intervals/description/
  Runtime: 12.04%
  Memory: 11.14%
******************************************/

vector<vector<int>> merge(vector<vector<int>> &intervals) {
  sort(intervals.begin(), intervals.end());
  vector<vector<int>> res;

  vector<int> currentInterval = intervals[0];
  for (int i = 1; i < intervals.size(); ++i) {
    vector<int> interval = intervals[i];
    if (interval[0] <= currentInterval[1])
      currentInterval[1] = max(currentInterval[1], interval[1]);
    else {
      res.push_back(currentInterval);
      currentInterval = interval;
    }
  }

  res.push_back(currentInterval);

  return res;
}

int main() { return 0; }
