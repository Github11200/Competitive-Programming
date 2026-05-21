#include <bits/stdc++.h>
#include <string>
#include <unordered_set>

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/
  Runtime: 37.50%
  Memory: 76.50%
******************************************/

int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
  unordered_set<int> prefixes;
  for (auto num : arr1) {
    string s = to_string(num);
    string currentString;
    for (int i = 0; i < s.size(); ++i) {
      currentString += s[i];
      prefixes.insert(stoi(currentString));
    }
  }

  int maxLength = 0;
  for (auto num : arr2) {
    while (num > 0) {
      if (prefixes.count(num) > 0) {
        maxLength = max(maxLength, static_cast<int>(to_string(num).size()));
        break;
      }
      num /= 10;
    }
  }

  return maxLength;
}

int main() { return 0; }
