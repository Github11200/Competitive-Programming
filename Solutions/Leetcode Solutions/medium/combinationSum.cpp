#include <bits/stdc++.h>
#include <vector>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/combination-sum/description/
  Runtime: 100.00%
  Memory: 51.61%
******************************************/

void dfs(vector<vector<int>> &answer, vector<int> &candidates,
         vector<int> &currentAnswer, int currentSum, int target, int index) {
  if (currentSum == target) {
    answer.push_back(currentAnswer);
    return;
  }

  if (currentSum > target)
    return;

  for (int i = index; i < candidates.size(); ++i) {
    currentAnswer.push_back(candidates[i]);
    dfs(answer, candidates, currentAnswer, currentSum + candidates[i], target,
        i);
    currentAnswer.pop_back();
  }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
  vector<vector<int>> answer;
  vector<int> currentAnswer;

  dfs(answer, candidates, currentAnswer, 0, target, 0);

  return answer;
}

int main() {
  vector<int> test({2, 3, 5});

  display2DVector(combinationSum(test, 6));

  return 0;
}
