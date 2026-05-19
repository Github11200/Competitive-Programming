#include <bits/stdc++.h>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/jump-game-iii/description/
  Runtime: 100.00%
  Memory: 71.26%
******************************************/

bool canReach(vector<int> &arr, int start) {
  vector<bool> visited(arr.size(), false);
  queue<int> s;
  s.push(start);

  while (!s.empty()) {
    int currentIndex = s.front();
    s.pop();

    if (arr[currentIndex] == 0)
      return true;
    if (visited[currentIndex])
      continue;

    visited[currentIndex] = true;

    int leftIndex = currentIndex - arr[currentIndex];
    int rightIndex = currentIndex + arr[currentIndex];

    bool leftResult = false, rightResult = false;
    if (leftIndex >= 0 && !visited[leftIndex])
      s.push(leftIndex);
    if (rightIndex < arr.size() && !visited[rightIndex])
      s.push(rightIndex);
  }

  return false;
}

int main() {
  vector<int> test({4, 2, 3, 0, 3, 1, 2});
  cout << canReach(test, 5) << endl;
  return 0;
}
