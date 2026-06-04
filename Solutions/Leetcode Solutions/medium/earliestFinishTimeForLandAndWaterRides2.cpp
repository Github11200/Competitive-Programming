#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <iterator>

using namespace std;

int solve(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime, vector<int> &waterDuration) {
  int minLandStartTime = INT_MAX;
  for (int i = 0; i < landStartTime.size(); ++i)
    minLandStartTime = min(minLandStartTime, landStartTime[i] + landDuration[i]);

  int minTime = INT_MAX;
  for (int i = 0; i < waterStartTime.size(); ++i)
    minTime = min(minTime, max(waterStartTime[i], minLandStartTime) + waterDuration[i]);

  return minTime;
}

int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime, vector<int> &waterDuration) {
  int s1 = solve(landStartTime, landDuration, waterStartTime, waterDuration);
  int s2 = solve(waterStartTime, waterDuration, landStartTime, landDuration);
  return min(s1, s2);
}

int main() {
  vector<int> landStartTime({41, 59, 14});
  vector<int> landDuration({8, 74, 45});

  vector<int> waterStartTime({41, 78});
  vector<int> waterDuration({16, 33});

  earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);
  return 0;
}
