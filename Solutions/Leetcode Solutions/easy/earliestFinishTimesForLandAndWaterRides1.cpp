#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/description/
  Runtime: 38.40%
  Memory: 85.65%
******************************************/

int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime, vector<int> &waterDuration) {
  int minTime = INT_MAX;
  for (int i = 0; i < landStartTime.size(); ++i) {
    for (int j = 0; j < waterStartTime.size(); ++j) {
      int time1, time2;

      time1 = landStartTime[i] + landDuration[i];
      if (waterStartTime[j] > time1)
        time1 += waterStartTime[j] - time1;
      time1 += waterDuration[j];

      time2 = waterStartTime[j] + waterDuration[j];
      if (landStartTime[i] > time2)
        time2 += landStartTime[i] - time2;
      time2 += landDuration[i];

      minTime = min(minTime, min(time1, time2));
    }
  }

  return minTime;
}

int main() { return 0; }
