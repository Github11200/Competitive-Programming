#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> &nums) {
  int drops = 0;
  for (int i = 0; i < nums.size(); ++i) {
    int nextIndex = i + 1 == nums.size() ? 0 : i + 1;
    if (nums[i] > nums[nextIndex])
      ++drops;
  }

  if (drops > 1)
    return false;
  return true;
}

int main() {
  vector<int> test({3, 4, 5, 1, 2});
  check(test);
  return 0;
}